// 在c++中，可以直接抛出异常之后自己进行捕捉处理
// 比如在进行数据库事务操作的时候，如果某一个语句返回SQL_ERROR则直接抛出异常，在catch块中进行事务回滚

// throw的作用是什么？
// try 和 catch 的作用是什么？

#include <iostream>
#include <exception>  


void throwException() {
    try  {  
        throw "error";  
        throw 1;  
    }  
    catch(std::exception& e){   //标准异常类
        std::cout << "default exception" << e.what() << std::endl;  
    }
    catch(int i)  {  
        std::cout << i << std::endl;  
    }
    catch(char *str)  {  
        std::cout << str << std::endl;  
    }  
}


double division(int a, int b) {
    if (b == 0) {
        throw "Division by zero condition!";
    }
    return (a / b);
}



int main() {
    throwException();

    int x = 50;
    int y = 0;

    while (true) {
        std::cin >> x >> y;

        try {
            double z = division(x, y);
            std::cout << z << std::endl;
            break; // If division is successful, break out of the loop
        }
        catch (const char* msg) {
            std::cerr << msg << std::endl;
            std::cerr << "Please try again." << std::endl;
        }
    }

    system("pause");
    return 0;
}