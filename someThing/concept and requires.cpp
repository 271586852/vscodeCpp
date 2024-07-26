#include <iostream>
#include <concepts>
#include <type_traits>

template <typename T>
concept Addable = requires(T a, T b) {
    { a + b } -> std::same_as<T>;
};

template <Addable T>
T add(T a, T b) {
    return a + b;
}

int main() {
    std::cout << add(1, 2) << std::endl;    // OK
    // std::cout << add(1, "test") << std::endl;  // 错误，不满足 Addable 概念
    return 0;
}
