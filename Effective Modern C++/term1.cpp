#include <iostream>

template <typename T>
void printType(T value) {
    std::cout << "Type: " << typeid(value).name()<< "打印自printType函数" << std::endl;
}

template <typename T>
void f(T value) {
    std::cout << "Type: " << typeid(value).name()<< "打印自f函数" << std::endl;
}

int main() {
    int num = 10;
    f(num); // 推导出 T 为 int

    double pi = 3.14159;
    printType(pi); // 推导出 T 为 double

    std::string name = "John";
    printType(name); // 推导出 T 为 std::string

    return 0;
}