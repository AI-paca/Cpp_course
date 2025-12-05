#ifndef STACK_H
#define STACK_H

#include "DynamicArray.h"
#include <stdexcept>

template<typename T>
class stack {
private:
  DynamicArray<T> data;
  std::int64_t max_size;

protected:

public:
  stack(std::int64_t capacity) : max_size(capacity), data(capacity) {}

  void push(T item) {
    if (data.getSize() >= max_size) {
      throw std::overflow_error("Stack overflow");
    }
    data.push_back(item);
  }

  T top() {
    if (isEmpty()) {
      throw std::underflow_error("Stack empty");
    }
    return data.back();
  }

  T pop() {
    if (isEmpty()) {
      throw std::underflow_error("Stack empty");
    }
    T item = data.back();
    data.erase(data.getSize() - 1);
    return item;
  }

  bool isEmpty() {
    return data.getSize() == 0;
  }

  int size() {
    return data.getSize();
  }
};

#endif // STACK_H
