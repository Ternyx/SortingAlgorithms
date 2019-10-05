#ifndef SORTING_H
#define SORTING_H

#include <vector>
#include <utility>
#include <string>
#include <functional>

namespace sorting {
    void bubbleSort(std::vector<int>& arr);
    void insertionSortShiftBased(std::vector<int>& arr); 
    void insertionSortSwapBased(std::vector<int> & arr);

    void bubbleSortData(std::vector<int>& arr, std::vector<long>& data);
    void insertionSortShiftBasedData(std::vector<int>& arr, std::vector<long>& data); 
    void insertionSortSwapBasedData(std::vector<int> & arr, std::vector<long>& data);

    void nativeSort(std::vector<int>& arr);
    std::vector<std::pair<std::string, std::function<void(std::vector<int>&)>>> getAllSorts(); 

    std::vector<std::pair<std::string, std::function<void(std::vector<int>&, std::vector<long>&)>>> getAllSortsWithData(); 

    // utilities
    bool isSorted(std::vector<int>& arr);
    void printArr(std::vector<int>& arr);
} // namespace sorting

#endif
