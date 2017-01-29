//
// Created by shishengjia on 29/01/2017.
//

#ifndef ALGORITHM_SORTTESTHELPER_H
#define ALGORITHM_SORTTESTHELPER_H


#include <iostream>
#include <ctime>
#include <cassert>
#include <stdlib.h>

using namespace std;

namespace SortTestHelper {

    /*
     * 打印数组
     */
    template<typename T>
    void printArray(T arr[], int n) {
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
        return;
    }

    /*
     * 生成一个近乎有序的数组
     */

    int *generateNearlyOrderedArray(int n, int swapTimes) {
        int *arr = new int[n];
        //生成有序数组
        for (int i = 0; i < n; i++)
            arr[i] = i;
        srand(time(NULL));
        //将有序数组的元素随机调换swapTimes次
        for (int i = 0; i < swapTimes; i++) {
            int position_a = rand() % n;
            int position_b = rand() % n;
            swap(arr[position_a], arr[position_b]);
        }

        return arr;
    }

    /**
    * 生成有n个元素的随机数组，每个元素的随机范围为[rangeL，rangeR]
    * 返回数组的首地址
    */
    int *generateRandomArray(int n, int rangeL, int rangeR) {
        assert(rangeL <= rangeR);//确保rangeL<rangeR
        int *arr = new int[n];
        srand(time(NULL));
        for (int i = 0; i < n; i++)
            arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;//产生范围在rangeL-rangeR之间的数组
        return arr;
    }

    /*
     * 判断数组是否已经从小到大排序
     */
    template<typename T>
    bool isSorted(T arr[], int n) {
        for (int i = 0; i < n - 1; i++)
            if (arr[i] > arr[i + 1])
                return false;
        return true;
    }


    /*
     * 测试算法性能
     * 第二个参数为函数指针
     */
    template<typename T>
    void testSort(string sortName, void(*sort)(T[], int), T arr[], int n) {
        clock_t startTime = clock();
        sort(arr, n);
        clock_t endTime = clock();
        assert(isSorted(arr, n));//确保排序正确
        //endTime-startTime是指运行了几个时钟周期，CLOCKS_PER_SEC表示1秒所执行的时钟周期个数
        cout << sortName << ":" << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;
        return;
    }

    /*
     * 拷贝一个数组
     */
    template<typename T>
    T *copyArray(T a[], int n) {
        T *arr = new T[n];
        copy(a, a + n, arr);
        return arr;
    }


}

#endif //ALGORITHM_SORTTESTHELPER_H
