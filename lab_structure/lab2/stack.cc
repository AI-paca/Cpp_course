#include "stack.h"

template<typename T>
stack<T>::stack(std::int64_t capacity) : max_size(capacity), data(capacity) {}

template<typename T>
void stack<T>::push(T item) {
  if (data.getSize() >= max_size) {
    throw std::overflow_error("Stack overflow");
  }
  data.push_back(item);
}

template<typename T>
T stack<T>::top() {
  if (isEmpty()) {
    throw std::underflow_error("Stack empty");
  }
  return data.back();
}

template<typename T>
T stack<T>::pop() {
  if (isEmpty()) {
    throw std::underflow_error("Stack empty");
  }
  T item = data.back();
  data.erase(data.getSize() - 1);
  return item;
}

template<typename T>
bool stack<T>::isEmpty() {
  return data.getSize() == 0;
}

template<typename T>
int stack<T>::size() {
  return data.getSize();
}
