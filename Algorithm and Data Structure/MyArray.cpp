#include<iostream>
#include "MyArray.h"

template<typename T>
MyArray<T>::MyArray() : capacity(10), size(0) {
    data = new T[capacity];
}

template<typename T>
MyArray<T>::~MyArray() {
    // 析构函数内容，如果有需要清理的资源，可以在这里添加
}

template<typename T>
T MyArray<T>::add(T number){
    data[data.size()] = number;
}

template<typename T>
void MyArray<T>::insert(int position,T number){
    for(int i = 0;i<this->getCapacity();i++){
        if(i == position){
            this.data[i] = number;
        }
        if(i>position){
            this.data[i] = this.data[i-1];
        }
    }
}

template<typename T>
void MyArray<T>::remove(int position){
    for(int i = position;i<this->size;i++){
        this->data[i] = this->data[i+1];
    }
}

template<typename T>
T MyArray<T>::getArray(int position){
    T a = this->data[position];
    return a;
}

template<typename T>
void MyArray<T>::update(int position,T number){
    this->data[position] = number;
}

template<typename T>
int MyArray<T>::getSize(){
    return this->size;
}

template<typename T>
bool MyArray<T>::isEmpty(){
    if(this->data.size() == 0){
        return true;
    }
}

template<typename T>
void MyArray<T>::clear(){
    for(int i = 0; i<this.getSize() ;i++   ){
        this.data[i]=nullptr;
    }
}

template<typename T>
int MyArray<T>::find(T number){ //查找返回找到的第一个元素
    for(int i = 0; i<this.getSize() ;i++   ){
        if(this->data[i] == number){
            return i;
        }
    }
} 

template<typename T>
T MyArray<T>::indexOf(int number){
    return this->data[number];
}

template<typename T>
int MyArray<T>::getCapacity(){
    return this->capacity;
}

template<typename T>
void MyArray<T>::resize(T &capacity){
    this->capacity = capacity;
}

template<typename T>
void MyArray<T>::iterate(){
    for(int a=0;a<this->size;a++){
        std::cout << this->data[a] << std::endl;
    }
}

template<typename T>
void MyArray<T>::reverse(){
    for(int i = 0;i<this->size/2;i++){
        T temp = this->data[i];
        this->data[i] = this->data[this->size-1-i];
        this->data[this->size-1-i] = temp;
    }
}


// 冒泡排序
template<typename T>
void MyArray<T>::sort(){
    for(int i = 0;i<this->size;i++){
        for(int j = 0;j<this->size-i-1;j++){
            if(this->data[j]>this->data[j+1]){
                T temp = this->data[j];
                this->data[j] = this->data[j+1];
                this->data[j+1] = temp;
            }
        }
    }
}


template<typename T>
void MyArray<T>::merge(MyArray<T>& other){
    for(int i = 0;i<other.getSize();i++){
        this->data[this->size+i] = other.getArray(i);
    }
}

template<typename T>
void MyArray<T>::copy(MyArray<T>& other){
    for(int i = 0;i<other.getSize();i++){
        this->data[i] = other.getArray(i);
    }
}

template<typename T>
bool MyArray<T>::contains(T number){
    for(int i = 0;i<this->size;i++){
        if(this->data[i] == number){
            return true;
        }
    }
    return false;
}

template<typename T>
MyArray<T> MyArray<T>::subMyArray(int start,int end){
    MyArray<T> arr;
    for(int i = start;i<end;i++){
        arr.add(this->data[i]);
    }
    return arr;
}

template<typename T>
void MyArray<T>::fill(T number){
    for(int i = 0;i<this->getSize();i++){
        this->data[i] = number;
    }
}

 

int main(){
    
    MyArray <int> arr;
    MyArray <double> arr2;
    int arr3[5]= {1, 2, 3, 4, 5}; //使用的是c++默认的数组，而不是MyArray


    int size = arr.getSize();

    std::cout << "数组大小：" << size << std::endl;
    std::cout << "结束";
}