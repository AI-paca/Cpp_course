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
  stack(std::int64_t capacity);
  void push(T item);
  T top();
  T pop();
  bool isEmpty();
  int size();
};

#endif // STACK_H
