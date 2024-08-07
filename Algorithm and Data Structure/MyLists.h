#include<iostream>

template<typename T>
class ListNode {
    private:
        T data;
        ListNode<T>* next;
    public:
        ListNode();
        ListNode(T data);
        

        T getData();
        void printList();
        int search(T data);
        void insert(T data);
        void remove(T data);
        void setData(T data);
};