#include <iostream>
#include <cstddef>

class Drink
{
private:
    /* data */
public:
    Drink(/* args */);

    void make(){
        std::cout << "make drink" << std::endl;
    }
    ~Drink();
};

class Tea : public Drink {
private:
    /* data */
public:
    Tea(/* args */);
    void make(){
        std::cout << "make tea" << std::endl;
    }
    ~Tea();
};

int main(){
    // Drink d;
    // d.make();
    Tea t;
    t.make();
    t.Drink::make(); //显式调用基类成员函数
    return 0;
}
