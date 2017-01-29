//
// Created by shishengjia on 29/01/2017.
//

#ifndef ALGORITHM_SELECTIONSORT_H
#define ALGORITHM_SELECTIONSORT_H

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

template<typename T>
void swap(T *a,T *b){
    T temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

template<typename T>
void selection_sort(T arr[], int n) {
    for (int i = 0; i < n; i++) {
        int minIndex = i;//用来存储最小值位置索引
        for (int j = i + 1; j < n; j++) { //依次与剩余的元素进行比较
            if (arr[j] < arr[minIndex])
                minIndex = j; //更新最小值索引
        }
        swap(&arr[i], &arr[minIndex]);//第一次遍历结束后，将最小值与当前元素交换位置
    }
}


#endif //ALGORITHM_SELECTIONSORT_H
