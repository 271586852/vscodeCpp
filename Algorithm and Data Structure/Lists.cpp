#include<iostream>


template<typename T>
class MyArray {
private:
    T * data;
    T capacity;
public:
    MyArray() : data(nullptr), capacity(0) {}
    MyArray (int number);
    ~MyArray (){
        delete[]data;
        std::cout << "析构" << std::endl;
    };

    T add(T number);
    T insert(int positition,T number);
    void remove(int positition);
    T get(int positition);
    void update(int position,T number);
    T size(int number);
    bool isEmpty();
    void clear();
    int find(T number); //查找返回找到的第一个元素
    T indexOf(int number);
    int size();
    void resize(T &capacity);

    // iterate
    // reverse
    // sort
    // merge
    // copy
    // contains
    // subMyArray 
    // fill


};



int main(){
    
    MyArray <int> arr;
    std::cout << "结束";
}