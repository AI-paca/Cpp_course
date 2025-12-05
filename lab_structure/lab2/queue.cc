#include "queue.h"

template<typename T>
queue<T>::queue() {}

template<typename T>
void queue<T>::enqueue(T item) {
  data.push_back(item);
}

template<typename T>
T queue<T>::dequeue() {
  if (isEmpty()) {
    throw std::underflow_error("Queue empty");
  }
  T item = data.front();
  data.erase(0);
  return item;
}

template<typename T>
bool queue<T>::isEmpty() {
  return data.getSize() == 0;
}

template<typename T>
int queue<T>::size() {
  return data.getSize();
}
