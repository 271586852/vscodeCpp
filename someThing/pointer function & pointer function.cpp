#include <iostream>

// 定义一个指针函数，返回类型为double指针
double* pointerFunction(double value) {
    double* ptr = new double(value);
    return ptr;
}

// 定义一个函数指针类型
typedef double* (*FunctionPointer)(double);

// 定义一个函数，接受一个函数指针作为参数并调用它
void callFunctionPointer(FunctionPointer func, double value) {
    double* result = func(value);
    std::cout << "Result: " << *result << std::endl;
    delete result;
}

int main() {
    // 使用指针函数
    double* ptr = pointerFunction(3.14);
    std::cout << "Pointer Function Result: " << *ptr << std::endl;
    delete ptr;

    // 使用函数指针
    FunctionPointer funcPtr = pointerFunction;
    callFunctionPointer(funcPtr, 3.14);

    return 0;
}