#ifndef QUEUE_H
#define QUEUE_H

#include "stack.h"
#include <cstdint>
#include <stdexcept>

template <typename T> class queue {
private:
  stack<T> inputStack;
  stack<T> outputStack;

protected:
public:
  queue();
  queue(std::int64_t size);
  void enqueue(T item);
  T dequeue();
  bool isEmpty();
  int size();
};

#endif // QUEUE_H
