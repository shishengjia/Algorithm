#include <iostream>
#include "SelectionSort.h"
#include "SortTestHelper.h"
#include "InsertionSort.h"
using namespace std;

int main() {
    int n = 10000;
    int *arr = SortTestHelper::generateRandomArray(n,0,n);
    int *arr_2 = SortTestHelper::copyArray(arr,n);
    int *arr_3 = SortTestHelper::copyArray(arr,n);
    SortTestHelper::testSort("SelectionSort",selection_sort,arr,n);
    SortTestHelper::testSort("InsertionSort_Advanced",insertionSort_advanced,arr_2,n);
    SortTestHelper::testSort("InsertionSort_Original",insertionSort,arr_3,n);
    return 0;
}