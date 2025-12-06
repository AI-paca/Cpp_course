#include "queue.h"
#include "stack.h"
#include <cstdint>
#include <stdexcept>

template <typename T> queue<T>::queue() {
  inputStack = stack<T>(100);
  outputStack = stack<T>(100);
}

template <typename T> queue<T>::queue(std::int64_t size) {
  inputStack = stack<T>(size);
  outputStack = stack<T>(size);
}

template <typename T> void queue<T>::enqueue(T item) { inputStack.push(item); }

template <typename T> T queue<T>::dequeue() {
  if (isEmpty()) {
    throw std::underflow_error("Queue empty");
  }

  // Если outputStack пуст, переносим все элементы из inputStack
  if (outputStack.isEmpty()) {
    while (!inputStack.isEmpty()) {
      outputStack.push(inputStack.pop());
    }
  }

  return outputStack.pop();
}

template <typename T> bool queue<T>::isEmpty() {
  return inputStack.isEmpty() && outputStack.isEmpty();
}

template <typename T> int queue<T>::size() {
  return inputStack.size() + outputStack.size();
}

// указываем линковщику, что нужно использовать шаблонные функции для этих типов
template class queue<int>;
template class queue<float>;
template class queue<double>;
template class queue<std::string>;
