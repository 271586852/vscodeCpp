#include"MyLists.h"
#include <iostream>

template<typename T>
ListNode<T>::ListNode(){
    this->next = nullptr;
    std::cout << "ListNode constructor called" << std::endl;
}

template<typename T>
ListNode<T>::ListNode(T data){
    this->data = data;
    this->next = nullptr;
}

template<typename T>
T ListNode<T>::getData(){
    return this->data;
}

template<typename T>
void ListNode<T>::printList(){
    for(auto p = this;P ->next != nullptr;p = p->next){
        std::cout << p->data << " ";
    }
}

template<typename T>
int ListNode<T>::search(T data){
    int index = 0;
    for(auto p = this;p != nullptr;p = p->next){
        if(p->data == data){
            return index;
        }
        index++;
    }
    return -1;
}

template<typename T>
void ListNode<T>::insert(T data){
    auto p = this;
    while(p->next != nullptr){
        p = p->next;
    }
    p->next = new ListNode<T>(data);
    p->next->next = nullptr;
}

template<typename T>
void ListNode<T>::remove(T data){
    auto p = this;
    while(p->next != nullptr){
        if(p->next->data == data){
            auto temp = p->next;
            p->next = p->next->next;
            delete temp;
            return;
        }
        p = p->next;
    }
}

template<typename T>
void ListNode<T>::setData(T data){
    this->data = data;
}