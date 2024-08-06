
#include <iostream>
#include <stdexcept>
#include <initializer_list>

template <typename T>
class MyArray {
private:
    T* data;
    size_t capacity;
    size_t size;

    // 私有方法：重新分配内存并拷贝旧数据
    void resize(size_t new_capacity) {
        T* new_data = new T[new_capacity];
        for (size_t i = 0; i < size; i++) {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }

public:
    // 构造函数：默认构造
    MyArray() : data(nullptr), capacity(0), size(0) {}

    // 构造函数：带初始参数
    MyArray(std::initializer_list<T> init_list) : size(init_list.size()), capacity(init_list.size()) {
        data = new T[capacity];
        size_t i = 0;
        for (const T& item : init_list) {
            data[i++] = item;
        }
    }

    // 析构函数
    ~MyArray() {
        delete[] data;
    }

    // 获取数组大小
    size_t getSize() const {
        return size;
    }

    // 获取数组容量
    size_t getCapacity() const {
        return capacity;
    }

    // 添加元素
    void add(const T& element) {
        if (size == capacity) {
            resize((capacity == 0) ? 1 : capacity * 2);
        }
        data[size++] = element;
    }

    // 获取元素
    T& get(size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    // 删除元素
    void remove(size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        for (size_t i = index; i < size - 1; i++) {
            data[i] = data[i + 1];
        }
        size--;
        if (size <= capacity / 4) {
            resize(capacity / 2);
        }
    }
};

int main() {
    // 使用初始化列表初始化数组
    MyArray<int> arr = {1, 2, 3, 4, 5};
    
    std::cout << "Array size: " << arr.getSize() << std::endl;  // 输出：Array size: 5
    std::cout << "Element at index 2: " << arr.get(2) << std::endl;  // 输出：Element at index 2: 3

    arr.add(6);

    std::cout << "Array size after adding: " << arr.getSize() << std::endl;  // 输出：Array size after adding: 6
    std::cout << "Element at index 5: " << arr.get(5) << std::endl;  // 输出：Element at index 5: 6

    arr.remove(2);

    std::cout << "Array size after removal: " << arr.getSize() << std::endl;  // 输出：Array size after removal: 5
    std::cout << "Element at index 2 after removal: " << arr.get(2) << std::endl;  // 输出：Element at index 2 after removal: 4

    return 0;
}
