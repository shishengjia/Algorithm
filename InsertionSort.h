//
// Created by shishengjia on 29/01/2017.
//

#ifndef ALGORITHM_INSERTIONSORT_H
#define ALGORITHM_INSERTIONSORT_H

//插入排序原始版本，每一次执行swap操作，内存中进行三次赋值操作，比较耗费时间
template<typename T>
void insertionSort(T arr[], int n) {
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0 && arr[j] < arr[j - 1]; j--)//j元素比(j-1)元素小且j>0，才进行交换，再进行下一个循环，否则循环终止
            swap(arr[j], arr[j - 1]);
    }
}

/*
 *改进之后减少了赋值操作
 *另外，插入排序相对于选择排序能够提早结束循环
 */
template<typename T>
void insertionSort_advanced(T arr[], int n) {
    for (int i = 1; i < n; i++) {
        T e = arr[i];//当前元素e
        int j;//保存元素e应插入的位置
        //如果(j-1)元素比e元素大，则将(j-1)元素的值赋给j元素，然后进行下一次比较，直到(j-1)元素小于e元素，退出循环
        //此时j就是e所应该插入的位置
        for ( j = i; j > 0 && arr[j-1] > e; j--)
            arr[j] = arr[j-1];
        arr[j] = e;
    }
}


#endif //ALGORITHM_INSERTIONSORT_H
