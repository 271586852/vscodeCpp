// 优化1：普通单向列表，面临插入空列表导致报错，添加一个哨兵节点
// 优化2：只有一个后向指针，导致访问前一个节点的时候需要遍历，添加一个前向指针
// 优化3：添加第二个哨兵节点或循环列表解决指针指向不明确的问题

#include<iostream>

template<typename T>
class ListNode {
    private:
        T data;
        ListNode<T>* next;
        ListNode<T>* prev;
        
    public:
        ListNode():next(nullptr),prev(nullptr);
        ListNode(T data);
        

        T getData();
        void printList();
        int search(T data);
        void insert(T data);
        void remove(T data);
        void setData(T data);
};

template<typename T>
class DLList {
    private:
        ListNode<T>* head;
        ListNode<T>* tail;
        int size;
        
    public:
        DLList();
        void printList();
        int search(T data);
        void insert(T data);
        void remove(T data);
        int getSize();
};