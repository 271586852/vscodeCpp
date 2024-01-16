//类的封装、继承、多态示例
// Created by apple on 2020/4/21.
//

#include <iostream>
using namespace std;


#include <iostream>
using namespace std;

// 基类 Shape
class Shape {
public:
    // 虚函数，用于计算面积
    virtual double getArea() const {
        return 0;
    }
    // 虚函数，用于计算周长
    virtual double getPerimeter() const {
        return 0;
    }
};

// 派生类 Rectangle，继承自 Shape
class Rectangle : public Shape {
public:
    // 构造函数，初始化矩形的宽度和高度
    Rectangle(double width, double height) : m_width(width), m_height(height) {}
    // 重写基类的虚函数，计算矩形的面积
    double getArea() const override {
        return m_width * m_height;
    }
    // 重写基类的虚函数，计算矩形的周长
    double getPerimeter() const override {
        return 2 * (m_width + m_height);
    }
private:
    double m_width;  // 矩形的宽度
    double m_height; // 矩形的高度
};

// 派生类 Circle，继承自 Shape
class Circle : public Shape {
public:
    // 构造函数，初始化圆的半径
    Circle(double radius) : m_radius(radius) {}
    // 重写基类的虚函数，计算圆的面积
    double getArea() const override {
        return 3.14 * m_radius * m_radius;
    }
    // 重写基类的虚函数，计算圆的周长
    double getPerimeter() const override {
        return 2 * 3.14 * m_radius;
    }
private:
    double m_radius; // 圆的半径
};

int main() {
    Rectangle rect(3, 4); // 创建一个矩形对象，宽度为3，高度为4
    Circle circle(5);    // 创建一个圆对象，半径为5

    // 输出矩形的面积和周长
    cout << "Rectangle area: " << rect.getArea() << endl;
    cout << "Rectangle perimeter: " << rect.getPerimeter() << endl;

    // 输出圆的面积和周长
    cout << "Circle area: " << circle.getArea() << endl;
    cout << "Circle perimeter: " << circle.getPerimeter() << endl;

    return 0;
}
