#pragma once

template<typename T>
class MyArray {

private:
    T* data;
    int size;
    int capacity;

public:
    MyArray();

    MyArray(const T* init_array, int array_size);

    ~MyArray();

    T add(T number);

    void insert(int position, T number);

    void remove(int position);

    T getArray(int position);

    void update(int position, T number);

    int getSize();

    bool isEmpty();

    void clear();

    int find(T number);

    T indexOf(int number);

    int getCapacity();

    void resize(T& capacity);

    void iterate();

    void reverse();

    void sort();

    void merge(MyArray<T>& other);

    void copy(MyArray<T>& other);

    bool contains(T number);

    MyArray<T> subMyArray(int start, int end);

    void fill(T number);
};
