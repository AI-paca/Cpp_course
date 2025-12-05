#ifndef QUEUE_H
#define QUEUE_H

#include "DynamicArray.h"
#include <stdexcept>

template<typename T>
class queue {
private:
  DynamicArray<T> data;

protected:

public:
  queue();
  void enqueue(T item);
  T dequeue();
  bool isEmpty();
  int size();
};

#endif // QUEUE_H
