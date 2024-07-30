//[] 内的 a 和 b 是捕获列表（capture list），表示 lambda 表达式将捕获外部作用域中的变量 a 和 b。捕获列表中的变量可以在 lambda 表达式的函数体内使用。
//() 内的 int x, int y 是参数列表（parameter list），表示 lambda 表达式的参数。参数列表中的变量是 lambda 表达式被调用时传递的参数。

//使用&符号可以捕获外部作用域中的变量，并且可以修改这些变量的值。如果不使用&符号，则默认情况下是以值传递的方式捕获外部变量，无法修改外部变量的值。
//使用=符号可以捕获外部作用域中的变量，并且可以修改这些变量的值。如果不使用=符号，则默认情况下是以值传递的方式捕获外部变量，无法修改外部变量的值。

#include<iostream>

int z = 1;//全局变量无法捕获, 但是可以直接访问


void ptintTest(int x, int y, int a, int b, int z) {
    auto lambdaTest = [a, b](int x, int y) { 
        std::cout << "Hello Lambda\n"; 
        return x + y + a + b + z;
    };

    int result = lambdaTest(x, y);
    std::cout << "Result: " << result << std::endl;
}


int main(){
    int a = 10;
    int b = 20;

    /**
     * @brief 打印测试函数
     * 该函数演示了如何使用 lambda 表达式捕获外部变量并进行计算。
     * @param a 捕获的第一个外部变量
     * @param b 捕获的第二个外部变量
     * @param x 第一个整数参数
     * @param y 第二个整数参数
     * @param z 全局变量
     */
    auto  lambdaTest = [a,b](int x, int y) { 
        ptintTest(x,y,a,b,z);
        int result = x + y + a + b + z;
        std::cout << "和 = " << result << std::endl;
        return result;
    };


    lambdaTest(30,40);
    
}