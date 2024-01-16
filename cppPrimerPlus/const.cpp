#include<iostream>
using namespace std;
// const的多种用法

// 1. 常量变量
const int MAX_VALUE = 100; // 定义一个常量变量MAX_VALUE，其值为100，不可修改

// 2. 常量指针
int x = 5;
const int* ptr = &x; // 定义一个指向常量的指针ptr，指向变量x，不可通过ptr修改x的值，但可以通过其他方式修改x的值

// 3. 指针常量
int y = 10;
int* const p = &y; // 定义一个常量指针p，指向变量y，不可修改p的指向，但可以通过p修改y的值

// 4. 常量引用
int z = 15;
const int& ref = z; // 定义一个常量引用ref，引用变量z，不可通过ref修改z的值，但可以通过其他方式修改z的值

// 5. 常量成员函数
class MyClass {
public:
    void func() const {
        // 在成员函数后加上const关键字，表示该函数是一个常量成员函数，不会修改类的成员变量
    }
};

// 6. 常量对象
class MyObject {
public:
    void func() {
        // 一般情况下，成员函数可以修改对象的成员变量，但如果将对象声明为常量对象，则不能修改成员变量
    }
};

const MyObject obj; // 声明一个常量对象obj，不能通过obj调用非常量成员函数

// 7. 常量类
class MyConstClass {
public:
    int getValue() const {
        return value;
    }
private:
    const int value = 20; // 类中的常量成员变量
};

// 8. 常量参数
void func(const int x) {
    // 将参数声明为常量，表示在函数内部不会修改该参数的值
}

// 9. 常量返回值
const int func() {
    // 将函数返回值声明为常量，表示返回的值不能被修改
    return 30;
}
//写出const的多种用法

int main() {
    // 1. 常量变量
    cout << MAX_VALUE << endl;

    // 2. 常量指针
    cout << *ptr << endl;

    // 3. 指针常量
    cout << *p << endl;

    // 4. 常量引用
    //cout << ref << endl;

    // 5. 常量成员函数
    MyClass myClass;
    myClass.func();

    // 6. 常量对象
    // obj.func(); // 不能通过obj调用非常量成员函数

    // 7. 常量类
    MyConstClass myConstClass;
    cout << myConstClass.getValue() << endl;

    // 8. 常量参数
    func(40);

    // 9. 常量返回值
    cout << func() << endl;

    return 0;
}