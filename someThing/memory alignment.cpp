#include <iostream>
#include <cstddef>

struct s1 {
    char c;    // 1 byte
    int i;     // 4 bytes
    short s;   // 2 bytes
};

struct s2 {
    char c;    // 1 byte
    int i;     // 4 bytes
    struct s1 ss;   // 12 bytes
    double d;  // 8 bytes
};


struct s3 {
    char c;    // 1 byte
    int i;     // 4 bytes
    union w {
        int a;    // 4 bytes
        double b; // 8 bytes
    } w;      // 占用 8 bytes，因为 union 的大小取决于最大成员
    short s;   // 2 bytes
};

int main() {
    std::cout << "Size of s1: " << sizeof(s1) << std::endl;
    std::cout << "Size of s2: " << sizeof(s2) << std::endl;
    std::cout << "Size of s3: " << sizeof(s3) << std::endl;

    return 0;
}