#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <functional>

#include "sortingAlgorithms.hpp"

namespace sorting {

    void bubbleSort(std::vector<int>& arr) {
        const int length = arr.size();

        for (int i = 0; i < length - 1; i++) {
            bool isSorted = true;
            for (int j = 0; j < length - 1 - i; j++) {
                if (arr[j] > arr[j+1]) {
                    std::swap(arr[j], arr[j+1]);
                    isSorted = false;
                }
            }
            if (isSorted) return;
        }
    }

    void bubbleSortData(std::vector<int>& arr, std::vector<long>& data) {
        const int length = arr.size();
        long compares, swaps = 0;

        for (int i = 0; i < length - 1; i++) {
            bool isSorted = true;
            for (int j = 0; j < length - 1 - i; j++) {
                compares++;
                if (arr[j] > arr[j+1]) {
                    swaps++;
                    std::swap(arr[j], arr[j+1]);
                    isSorted = false;
                }
            }
            if (isSorted) break;
        }
        data[0]+=compares;
        data[1]+=swaps;
    }

    void insertionSortShiftBased(std::vector<int> & arr) {
        const int length = arr.size();
        for (int i = 1; i < length; i++) {
            const int current = arr[i];
            int j = i - 1;
            for ( ; j >= 0 && arr[j] > current; j--) {
                arr[j+1] = arr[j];
            }
            arr[j+1] = current;
        }
    }

    void insertionSortShiftBasedData(std::vector<int> & arr, std::vector<long>& data) {
        const int length = arr.size();
        long compares, swaps = 0;

        for (int i = 1; i < length; i++) {
            const int current = arr[i];
            int j = i - 1;

            while (j>=0) {
                compares++;
                if (arr[j] > current) {
                    swaps++;
                    arr[j+1] = arr[j];
                    j--;
                }
                else break;
            }

            swaps++;
            arr[j+1] = current;
        }

        data[0]+=compares;
        data[1]+=swaps;
    }

    void insertionSortSwapBased(std::vector<int>& arr) {
        const int length = arr.size();
        for (int i = 1; i < length; i++) {
            for (int j = i; j > 0 && arr[j-1] > arr[j]; --j) {
                std::swap(arr[j-1], arr[j]);
            }
        }
    }

    void insertionSortSwapBasedData(std::vector<int>& arr, std::vector<long>& data) {
        const int length = arr.size();
        long compares, swaps = 0;

        for (int i = 1; i < length; i++) {
            for (int j = i; j > 0; --j) {
                compares++;
                if (arr[j-1] > arr[j]) {
                    swaps++;
                    std::swap(arr[j-1], arr[j]);
                }
                else break;
            }
        }
        data[0]+=compares;
        data[1]+=swaps;
    }

    void nativeSort(std::vector<int>& arr) {
        std::sort(arr.begin(), arr.end());
    }

    std::vector<std::pair<std::string, std::function<void(std::vector<int>&)>>> getAllSorts() {
        std::vector<std::pair<std::string, std::function<void(std::vector<int>&)>>> container = {
            {"Bubble sort", bubbleSort},
            {"Insertion sort (shift based)", insertionSortShiftBased},
            {"Insertion sort (swap based)", insertionSortSwapBased},
            {"Native", nativeSort},
        };

        for (int i = 0; i < container.size(); i++) {
            const std::string temp = container[i].first;
            container[i].first = std::to_string(i) +  " : " + temp;
        }
        return container;
    } 

    std::vector<std::pair<std::string, std::function<void(std::vector<int>&, std::vector<long>&)>>> getAllSortsWithData() {
        std::vector<std::pair<std::string, std::function<void(std::vector<int>&, std::vector<long>&)>>> container = {
            {"Bubble sort ", bubbleSortData},
            {"Insertion sort (shift based)", insertionSortShiftBasedData},
            {"Insertion sort (swap based)", insertionSortSwapBasedData},
        };

        for (int i = 0; i < container.size(); i++) {
            const std::string temp = container[i].first;
            container[i].first = std::to_string(i) +  " : " + temp;
        }
        return container;
    }

    // utilities
    bool isSorted(std::vector<int>& arr) {
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i-1] > arr[i]) return false;
        }
        return true;
    }

    void printArr(std::vector<int>& arr) {
        const int length = arr.size();

        for (int i = 0; i < length; i++) {
            if (i >= length - 1) std::cout << arr[i];
            else std::cout << arr[i] << ' ';
        }
        std::cout << std::endl; 
    }
} // namespace sorting
