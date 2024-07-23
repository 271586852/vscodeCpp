#include <iostream>
#include <cstddef>


class A{
public:
    char c;
    int a;
    short b ;
    //默认构造函数
    A():c(1),a(2),b(3){}
    //构造函数
    A(char c, int a, short b):c(c),a(a),b(b){}
    //拷贝构造函数
    A(const A& a):c(a.c),a(a.a),b(a.b){
        std::cout << "Copy constructor called" << std::endl;
    }
    //移动构造函数
    A(A&& a):c(a.c),a(a.a),b(a.b){
        std::cout << "Move constructor called" << std::endl;
    }
    //类型转换构造函数
    A(int a):a(a){
        std::cout << "Type conversion constructor called" << std::endl;
    }
    //委托构造函数
    A(int a, short b):A('a', a, b){
        std::cout << "Delegating constructor called" << std::endl;
    }
    //赋值运算符
    A& operator=(const A& a){
        std::cout << "Assignment operator called" << std::endl;
        if(this == &a){
            return *this;
        }
        c = a.c;
        this->a = a.a;
        b = a.b;
        return *this;
    }
    //移动赋值运算符
    A& operator=(A&& a){
        std::cout << "Move assignment operator called" << std::endl;
        if(this == &a){
            return *this;
        }
        c = a.c;
        this->a = a.a;
        b = a.b;
        return *this;
    }

    //析构函数
    ~A(){
        std::cout << "Destructor called" << std::endl;
    }

};

int main() {

    auto a1 = "hello";
    auto a2 = std::string("hello");
    A a;
    A b('a', 1, 2);
    std::cout << a.c << " " << a.a << " " << a.b << std::endl;
    return 0;
}
