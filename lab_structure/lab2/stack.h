#ifndef STACK_H
#define STACK_H

#include "DynamicArray.h"
#include <stdexcept>

template<typename T>
class stack {
private:
  DynamicArray<T> data;
  static const std::int64_t max_size = 100;

protected:

public:
  stack();
  stack(std::int64_t size);
  void push(T item);
  T top();
  T pop();
  bool isEmpty();
  int size();
};

#endif // STACK_H
