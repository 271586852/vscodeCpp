// //虚函数的定义和使用示例
#include <iostream>
using namespace std;

class Shape {
public:
    virtual double getArea() const {
        return 0;
    }
    virtual double getPerimeter() const {
        return 0;
    }
};

class Rectangle : public Shape {
public:
    Rectangle(double width, double height) : m_width(width), m_height(height) {}
    double getArea() const override {
        return m_width * m_height;
    }
    double getPerimeter() const override {
        return 2 * (m_width + m_height);
    }
private:
    double m_width;
    double m_height;
};

class Circle : public Shape {
public:
    Circle(double radius) : m_radius(radius) {}
    double getArea() const override {
        return 3.14 * m_radius * m_radius;
    }
    double getPerimeter() const override {
        return 2 * 3.14 * m_radius;
    }
private:
    double m_radius;
};

int main() {
    Rectangle rect(3, 4);
    Circle circle(5);
    cout << "Rectangle area: " << rect.getArea() << endl;
    cout << "Rectangle perimeter: " << rect.getPerimeter() << endl;
    cout << "Circle area: " << circle.getArea() << endl;
    cout << "Circle perimeter: " << circle.getPerimeter() << endl;
    return 0;
}
