//运算符重载
//重载为全局函数
//重载为成员函数
//重载为友元函数
//重载为成员函数和友元函数的区别
//重载为前置和后置运算符
//重载为双目运算符和单目运算符
//重载为混合运算符
//重载为赋值运算符
//重载为下标运算符
//重载为函数调用运算符
//重载为类型转换运算符
//重载为递增和递减运算符
//重载为输入和输出运算符
//重载为其他运算符
//重载为运算符函数模板
//重载为运算符函数模板的限制
//重载为运算符函数模板的实现
//重载为运算符函数模板的使用
//重载为运算符函数模板的实例

#include <iostream>
using namespace std;

class Complex {
public:
    Complex(double real = 0.0, double imag = 0.0) : m_real(real), m_imag(imag) {}
    Complex operator+(const Complex& c2) const;
    Complex operator-(const Complex& c2) const;
    Complex operator*(const Complex& c2) const;
    Complex operator/(const Complex& c2) const;
    Complex& operator+=(const Complex& c2);
    Complex& operator-=(const Complex& c2);
    Complex& operator*=(const Complex& c2);
    Complex& operator/=(const Complex& c2);
    Complex& operator++();
    Complex operator++(int);
    Complex& operator--();
    Complex operator--(int);
    friend ostream& operator<<(ostream& out, const Complex& c);
    friend istream& operator>>(istream& in, Complex& c);
private:
    double m_real;
    double m_imag;
};

Complex Complex::operator+(const Complex& c2) const {
    return Complex(m_real + c2.m_real, m_imag + c2.m_imag);
}

Complex Complex::operator-(const Complex& c2) const {
    return Complex(m_real - c2.m_real, m_imag - c2.m_imag);
}

Complex Complex::operator*(const Complex& c2) const {
    return Complex(m_real * c2.m_real - m_imag * c2.m_imag, m_real * c2.m_imag + m_imag * c2.m_real);
}

Complex Complex::operator/(const Complex& c2) const {
    double real = (m_real * c2.m_real + m_imag * c2.m_imag) / (c2.m_real * c2.m_real + c2.m_imag * c2.m_imag);
    double imag = (m_imag * c2.m_real - m_real * c2.m_imag) / (c2.m_real * c2.m_real + c2.m_imag * c2.m_imag);
    return Complex(real, imag);
}

Complex& Complex::operator+=(const Complex& c2) {
    m_real += c2.m_real;
    m_imag += c2.m_imag;
    return *this;
}

Complex& Complex::operator-=(const Complex& c2) {
    m_real -= c2.m_real;
    m_imag -= c2.m_imag;
    return *this;
}

Complex& Complex::operator*=(const Complex& c2) {
    double real = m_real * c2.m_real - m_imag * c2.m_imag;
    double imag = m_real * c2.m_imag + m_imag * c2.m_real;
    m_real = real;
    m_imag = imag;
    return *this;
}

Complex& Complex::operator/=(const Complex& c2) {
    double real = (m_real * c2.m_real + m_imag * c2.m_imag) / (c2.m_real * c2.m_real + c2.m_imag * c2.m_imag);
    double imag = (m_imag * c2.m_real - m_real * c2.m_imag) / (c2.m_real * c2.m_real + c2.m_imag * c2.m_imag);
    m_real = real;
    m_imag = imag;
    return *this;
}

Complex& Complex::operator++() {
    ++m_real;
    ++m_imag;
    return *this;
}

Complex Complex::operator++(int) {
    Complex c(m_real, m_imag);
    ++m_real;
    ++m_imag;
    return c;
}

Complex& Complex::operator--() {
    --m_real;
    --m_imag;
    return *this;
}

Complex Complex::operator--(int) {
    Complex c(m_real, m_imag);
    --m_real;
    --m_imag;
    return c;
}

ostream& operator<<(ostream& out, const Complex& c) {
    out << c.m_real << "+" << c.m_imag << "i";
    return out;
}

istream& operator>>(istream& in, Complex& c) {
    in >> c.m_real >> c.m_imag;
    return in;
}

//重载为运算符函数模板
template <typename T>
class MyArray {
public:
    MyArray(int capacity) : m_capacity(capacity) {
        m_pArr = new T[m_capacity];
    }
    T& operator[](int index) {
        return m_pArr[index];
    }
    template <typename U>
    friend ostream& operator<<(ostream& out, const MyArray<U>& arr);
private:
    T* m_pArr;
    int m_capacity;
};


// //重载为全局函数和成员函数的区别
// class Complex {
// public:
//     Complex(double real = 0.0, double imag = 0.0) : m_real(real), m_imag(imag) {}

//     // 成员函数重载
//     Complex operator+(const Complex& c) const {
//         return Complex(m_real + c.m_real, m_imag + c.m_imag);
//     }

//     // 全局函数重载
//     friend Complex operator-(const Complex& c1, const Complex& c2) {
//         return Complex(c1.m_real - c2.m_real, c1.m_imag - c2.m_imag);
//     }

//     void display() const {
//         std::cout << m_real << " + " << m_imag << "i" << std::endl;
//     }

// private:
//     double m_real;
//     double m_imag;
// };

// int main() {
//     Complex c1(1, 2);
//     Complex c2(3, 4);

//     Complex c3 = c1 + c2; // 成员函数重载调用
//     Complex c4 = c1 - c2; // 全局函数重载调用

//     c3.display();
//     c4.display();

//     return 0;
// }

int main() {
    Complex c1(1, 2);
    Complex c2(3, 4);
    cout << c1 << endl;
    cout << c2 << endl;
    cout << c1 + c2 << endl;
    cout << c1 - c2 << endl;
    cout << c1 * c2 << endl;
    cout << c1 / c2 << endl;
    cout << ++c1 << endl;
    cout << c1++ << endl;
    cout << c1 << endl;
    cout << --c1 << endl;
    cout << c1-- << endl;
    cout << c1 << endl;
    cout << (c1 += c2) << endl;
    cout << (c1 -= c2) << endl;
    cout << (c1 *= c2) << endl;
    cout << (c1 /= c2) << endl;
    cin >> c1;
    cout << c1 << endl;

    return 0;
}
