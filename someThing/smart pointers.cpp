#include<iostream>
#include<memory>



class MyClass {
public:
    MyClass() { std::cout << "Constructor\n"; }
    ~MyClass() { std::cout << "Destructor\n"; }
    void hello() { std::cout << "Hello\n"; }
};

class A{
public:
    std::shared_ptr<B> ptr;
    std::shared_ptr<C> c_ptr;
    A() { std::cout << "A Constructor\n"; }
    ~A() { std::cout << "A Destructor\n"; }
    void hello() { std::cout << "A Hello\n"; }
};

class B{
public:
    std::shared_ptr<A> ptr;
    B() { std::cout << "B Constructor\n"; }
    ~B() { std::cout << "B Destructor\n"; }
    void hello() { std::cout << "B Hello\n"; }
};

class C
{
public:
    std::weak_ptr<A> ptr;
    C() { std::cout << "C Constructor\n"; }
    ~C() { std::cout << "C Destructor\n"; }
    void hello() { std::cout << "C Hello\n"; }
};

int main() {

    std::unique_ptr<int> uniquePtrTest = std::make_unique<int>(10);

    std::shared_ptr<int> sharedPtrTest = std::make_shared<int>(20);


    std::weak_ptr<int> weakPtrTest = sharedPtrTest;
    
    std::cout << "sharedPtrTest使用次数 =  " << sharedPtrTest.use_count() << std::endl;

    {
        std::shared_ptr<int> sharedPtrTest2 = sharedPtrTest; // 引用计数增加
        auto sharedPtrTest3 = sharedPtrTest; // auto 类型推导 此处auto = shared_ptr<int>

        std::cout << "sharedPtrTest使用次数 =  " << sharedPtrTest.use_count() << std::endl;
    }//超出作用域，引用计数减少

    
    std::cout << "sharedPtrTest使用次数 =  " << sharedPtrTest.use_count() << std::endl;

    //shared_ptr可能发生的循环引用问题
    {
        //循环引用
        std::shared_ptr<A> a = std::make_shared<A>();
        std::shared_ptr<B> b = std::make_shared<B>();
        a->ptr = b;
        b->ptr = a;
        
        // 此时 a 和 b 互相持有对方的 shared_ptr，导致循环引用
    }// 作用域结束，a 和 b 超出作用域，但不会触发析构函数

    {
        //解决循环引用
        std::shared_ptr<A> a = std::make_shared<A>();
        std::shared_ptr<C> c = std::make_shared<C>();
        a->c_ptr = c;
        c->ptr = a;

        // 此时 a 和 b 互相持有对方的指针，但不会造成循环引用
    }// 作用域结束，a 和 b 超出作用域，析构函数会被正确调用





    
    
    return 0;
}