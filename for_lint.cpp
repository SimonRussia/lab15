//  "Copyright [2017] <Ovcharov Anisim>"

#include <iostream>

template <typename T>
class Stack {
 public:
        Stack();
        ~Stack();
        size_t count() const;
        bool empty() const;
        void push(T const &);
        T pop();
        T& operator[](int pos) {
            return array_[pos];
        }
 private:
        T* array_;
        size_t array_size_;
        size_t count_;
};


template <typename T>
Stack<T>::Stack() : array_size_(size_t(10)), array_(new T[10]), count_(0) {}

template <typename T>
Stack<T>::~Stack() {
    delete[] array_;
}

template <typename T>
void Stack<T>::push(T const &val) {
    if (count_ == array_size_) {
        T* array_exp_ = new T[array_size_*2];
        for (int i = 0; i < array_size_; i++) {
            array_exp_[i] = array_[i];
        }
        array_size_ *= 2;
        delete[] array_;
        array_ = array_exp_;
    }
    array_[count_++] = val;
}

template <typename T>
T Stack<T>::pop() {
    return array_[--count_];
}

template <typename T>
size_t Stack<T>::count() const {
    return count_;
}

template <typename T>
bool Stack<T>::empty() const {
    if (count() == 0) return true;
    return false;
}


int main() {
    Stack<int> stack;

    for (int i = 0; i < 15; i++) {
        stack.push(i);
    }
    std::cout << "STACK SIZE:\t" << stack.count() << std::endl;

    while (!stack.empty()) {
        stack.pop();
    }
    std::cout << "STACK SIZE:\t" << stack.count() << std::endl;
    return 0;
}
