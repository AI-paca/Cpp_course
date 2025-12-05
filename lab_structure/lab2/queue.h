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
  queue() {}

  void enqueue(T item) {
    data.push_back(item);
  }

  T dequeue() {
    if (isEmpty()) {
      throw std::underflow_error("Queue empty");
    }
    T item = data.front();
    data.erase(0);
    return item;
  }

  bool isEmpty() {
    return data.getSize() == 0;
  }

  int size() {
    return data.getSize();
  }
};

#endif // QUEUE_H
