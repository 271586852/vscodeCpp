#include<iostream>

//快速排序
template<typename T>
void quickSort(T* arr, int left, int right) {
    if (left >= right) {
        return;
    }
    int i = left;
    int j = right;
    T key = arr[left];
    while (i < j) {
        while (i < j && arr[j] >= key) {
            j--;
        }
        arr[i] = arr[j];
        while (i < j && arr[i] <= key) {
            i++;
        }
        arr[j] = arr[i];
    }
    arr[i] = key;
    quickSort(arr, left, i - 1);
    quickSort(arr, i + 1, right);
}

//冒泡排序
template<typename T>
void bubbleSort(T* arr, int len) {
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

//小根堆
template<typename T>
void heapify(T* arr, int len, int i) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int min = i;
    if (left < len && arr[left] < arr[min]) {
        min = left;
    }
    if (right < len && arr[right] < arr[min]) {
        min = right;
    }
    if (min != i) {
        T temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
        heapify(arr, len, min);
    }
}

//堆排序
template<typename T>
void heapSort(T* arr, int len) {
    for (int i = len / 2 - 1; i >= 0; i--) {
        heapify(arr, len, i);
    }
    for (int i = len - 1; i >= 0; i--) {
        T temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

//归并排序
template<typename T>
void merge(T* arr, int left, int mid, int right) {
    T* temp = new T[right - left + 1];
    int i = left;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= right) {
        if (arr[i] < arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }
    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    while (j <= right) {
        temp[k++] = arr[j++];
    }
    for (int p = 0; p < k; p++) {
        arr[left + p] = temp[p];
    }
    delete[] temp;
}


template<typename T>
void mergeSort(T* arr, int left, int right) {
    if (left >= right) {
        return;
    }
    int mid = (left + right) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

//插入排序
template<typename T>
void insertSort(T* arr, int len) {
    for (int i = 1; i < len; i++) {
        T temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

//选择排序
template<typename T>
void selectSort(T* arr, int len) {
    for (int i = 0; i < len - 1; i++) {
        int min = i;
        for (int j = i + 1; j < len; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        if (min != i) {
            T temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}

