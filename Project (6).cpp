#include <iostream>

template<typename T>
class shared_ptr {
private:
    T* ptr;
    int* count;

    void release() {
        if (count && --(*count) == 0) {
            delete ptr;
            delete count;
        }
    }

public:
    explicit shared_ptr(T* p = nullptr) : ptr(p), count(new int(1)) {}

    shared_ptr(const shared_ptr<T>& other) : ptr(other.ptr), count(other.count) {
        if (count) {
            ++(*count);
        }
    }

    shared_ptr<T>& operator=(const shared_ptr<T>& other) {
        if (this != &other) {
            release();
            ptr = other.ptr;
            count = other.count;
            if (count) {
                ++(*count);
            }
        }
        return *this;
    }

    ~shared_ptr() {
        release();
    }

    T& operator*() const {
        return *ptr;
    }

    T* operator->() const {
        return ptr;
    }

    T* get() const {
        return ptr;
    }

    int use_count() const {
        return count ? *count : 0;
    }

    bool unique() const {
        return use_count() == 1;
    }

    void reset(T* p = nullptr) {
        release();
        ptr = p;
        count = p ? new int(1) : nullptr;
    }

    explicit operator bool() const {
        return ptr != nullptr;
    }
};

class Test {
public:
    int value;
    Test(int v) : value(v) {
        std::cout << "Test constructed: " << value << std::endl;
    }
    ~Test() {
        std::cout << "Test destroyed: " << value << std::endl;
    }
};

int main() {
    shared_ptr<Test> ptr1(new Test(10));
    std::cout << "use_count: " << ptr1.use_count() << std::endl;

    {
        shared_ptr<Test> ptr2 = ptr1;
        std::cout << "use_count: " << ptr1.use_count() << std::endl;
        std::cout << "Value: " << ptr2->value << std::endl;
    }

    std::cout << "use_count: " << ptr1.use_count() << std::endl;
    std::cout << "Value: " << (*ptr1).value << std::endl;

    shared_ptr<Test> ptr3;
    ptr3 = ptr1;
    std::cout << "use_count: " << ptr1.use_count() << std::endl;

    ptr3.reset(new Test(20));
    std::cout << "use_count ptr1: " << ptr1.use_count() << std::endl;
    std::cout << "use_count ptr3: " << ptr3.use_count() << std::endl;

    return 0;
}