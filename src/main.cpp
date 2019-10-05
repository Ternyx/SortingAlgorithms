#include <iostream>
#include <chrono>
#include <array>
#include <functional>
#include <cmath>

#include "random.hpp"
#include "sortingAlgorithms.hpp"

enum modes {TIMED, DATA};

void test(std::function<void(std::vector<int>&)> sort, unsigned int repetitions);
void test(std::function<void(std::vector<int>&, std::vector<long>&)> sort, unsigned int repetitions); 

int main() {
    unsigned int mode;
    std::cout << "0: Time\n1: Swaps & Comparisons" << std::endl;
    std::cin >> mode;

    unsigned int repetitions;
    std::cout << "How many repetitions per N?" << std::endl;
    std::cin >> repetitions;

    std::cout << "Choose algorithm:" << std::endl;

    if (mode == TIMED) {
        auto sortingAlgorithms = sorting::getAllSorts();
        for (auto it = sortingAlgorithms.begin(); it != sortingAlgorithms.end(); it++) {
            std::cout << (*it).first << std::endl;
        }

        int alg;
        std::cin >> alg;

        if (alg >= 0 && alg < sortingAlgorithms.size()) {
            test(sortingAlgorithms[alg].second, repetitions);
        }
    }

    else if (mode == DATA) {
        auto sortingAlgorithms = sorting::getAllSortsWithData();
        for (auto it = sortingAlgorithms.begin(); it != sortingAlgorithms.end(); it++) {
            std::cout << (*it).first << std::endl;
        }

        int alg;
        std::cin >> alg;

        if (alg >= 0 && alg < sortingAlgorithms.size()) {
            test(sortingAlgorithms[alg].second, repetitions);
        }
    }

    return 0;
}

void test(std::function<void(std::vector<int>&)> sort, unsigned int repetitions) {
    static constexpr long MAX_N = 1000000000;
    std::vector<int> tmpVectorForSize;
    const long VECTOR_MAX_SIZE = tmpVectorForSize.max_size();

    Random rand(0);

    for (long arrSize = 10; arrSize <= MAX_N; arrSize*= 10) {
        double totalTime = 0;

        if (arrSize > VECTOR_MAX_SIZE) {
            std::cerr << "Exceeded max vector size" << std::endl;
            std::terminate();
        }

        for (int rep = 0; rep < repetitions; rep++) {
            rand.setSeed(rep);
            std::vector<int> arr = rand.randIntVector(arrSize);

            std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
            sort(arr);
            std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();

            double time = std::chrono::duration_cast<std::chrono::duration<double>>(end-start).count(); 
            totalTime+=time;

            if (!sorting::isSorted(arr)) {
                std::cerr << "Array was not sorted" << std::endl;
                std::terminate();
            } 
            else if (rep == 0) {
                std::printf("\nFirst run: %.9f sec\n", time);
            }
        }

        if (totalTime > 0) {
            const int gap = log10(MAX_N) - log10(arrSize);
            std::printf("N: %ld %*s Avg: %.9f sec\n", arrSize, gap , "", totalTime/repetitions);
        }
        else std::cout << "Something went badly wrong" << std::endl;
    }
}

void test(std::function<void(std::vector<int>&, std::vector<long>&)> sort, unsigned int repetitions) {
    static constexpr long MAX_N = 1000000;
    std::vector<int> tmpVectorForSize;
    const long VECTOR_MAX_SIZE = tmpVectorForSize.max_size();

    Random rand(0);

    for (long arrSize = 10; arrSize <= MAX_N; arrSize*= 10) {
        std::vector<long> comparesAndSwaps = {0,0};

        if (arrSize > VECTOR_MAX_SIZE) {
            std::cerr << "Exceeded max vector size" << std::endl;
            std::terminate();
        }

        for (int rep = 0; rep < repetitions; rep++) {
            rand.setSeed(rep);
            std::vector<int> arr = rand.randIntVector(arrSize);

            sort(arr, comparesAndSwaps);

            if (!sorting::isSorted(arr)) {
                std::cerr << "Array was not sorted" << std::endl;
                std::terminate();
            } 
            /*std::printf("%d run: Compares: %ld, Swaps: %ld\n",rep,  comparesAndSwaps[0], comparesAndSwaps[1]);*/
        }

        std::printf("N: %ld, Compares: %ld, Swaps: %ld\n", arrSize, (comparesAndSwaps[0]/repetitions), comparesAndSwaps[1]/repetitions);
    }
}
