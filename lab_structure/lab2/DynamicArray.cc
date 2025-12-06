#include "DynamicArray.h"

#include <cstdlib>
#include <exception>
#include <iostream>
#include <stdexcept>
#include <string>

template <typename T> DynamicArray<T>::DynamicArray() {
  this->capacity = 8;
  this->data = new T[this->capacity];
}

template <typename T> DynamicArray<T>::DynamicArray(std::int64_t capacity) {
  // check if user is dumb
  if (capacity < 1) {
    throw std::invalid_argument(
        "Capacity < 1"); // https://en.cppreference.com/w/cpp/error/exception.html
    // std::exception like an animal
    // std::invalid_argument like a dog (heir of animal)
  }
  this->capacity = capacity;
  this->data = new T[this->capacity];
}

template <typename T> DynamicArray<T>::DynamicArray(DynamicArray &other) {
  this->size = other.size;
  this->capacity = other.capacity;
  this->data = new T[this->capacity]; // (*this).data

  for (int i = 0; i <= size; ++i) {
    this->data[i] = other.data[i];
  }
}

template <typename T>
DynamicArray<T> &DynamicArray<T>::operator=(const DynamicArray &other) {
  if (this == &other) {
    return *this;
  }

  // Освобождаем текущую память
  if (this->data) {
    delete[] this->data;
  }

  // Копируем данные
  this->size = other.size;
  this->capacity = other.capacity;
  this->data = new T[this->capacity];

  for (int i = 0; i <= size; ++i) {
    this->data[i] = other.data[i];
  }

  return *this;
}

template <typename T> DynamicArray<T>::~DynamicArray() {
  // deallocate if allocated
  if (this->data) {
    delete[] this->data;
  }
}

template <typename T> void DynamicArray<T>::push_back(T x) {
  // reallocate memory
  // increase capacity
  // copy data
  // dealloc old
  // assign new to old
  if (size + 1 >= capacity) {
    std::int64_t newCapacity = capacity * 2;
    T *tempArray = new T[newCapacity];
    for (int i = 0; i < capacity; ++i) {
      tempArray[i] = data[i];
    }
    delete[] data;
    data = tempArray;
    capacity = newCapacity;
  }
  data[++size] = x;
  // data[size + 1] = x;
  // ++size;
}

template <typename T>
template <typename U>
typename std::enable_if<std::is_arithmetic<U>::value, U>::type
DynamicArray<T>::add(std::int64_t idx1, std::int64_t idx2) {
  if (idx1 > size || idx2 > size || idx1 < 0 || idx2 < 0) {
    throw std::invalid_argument("idx1 or idx2 out of range");
  }
  return data[idx1] + data[idx2];
}

template <typename T>
template <typename U>
typename std::enable_if<std::is_arithmetic<U>::value, U>::type
DynamicArray<T>::max() {
  if (isEmpty()) {
    throw std::invalid_argument("Empty array");
  }
  U currentMax = data[0];
  for (int i = 1; i <= size; ++i) {
    if (data[i] >= currentMax) {
      currentMax = data[i];
    }
  }
  return currentMax;
}

template <typename T>
template <typename U>
typename std::enable_if<std::is_arithmetic<U>::value, U>::type
DynamicArray<T>::min() {
  if (isEmpty()) {
    throw std::invalid_argument("Empty array");
  }
  T currentMin = data[0];
  for (int i = 1; i <= size; ++i) {
    if (data[i] <= currentMin) {
      currentMin = data[i];
    }
  }
  return currentMin;
}

template <typename T> void DynamicArray<T>::clear() {
  if (this->data) {
    delete[] this->data;
    this->data = nullptr;
  }
  size = -1;
  capacity = 8;
}

template <typename T> void DynamicArray<T>::reinitialize() {
  clear();
  data = new T[capacity]; // init without zeros for non-arithmetic types
}

template <typename T> void DynamicArray<T>::printData() {
  if (isEmpty()) {
    return;
  }
  for (int i = 0; i <= size; ++i) {
    std::cout << data[i] << " ";
  }
  std::cout << std::endl;
}

template <typename T> T DynamicArray<T>::operator[](std::int64_t idx) {
  if (isEmpty() || idx < 0 || idx > size) {
    throw std::invalid_argument("Out of range");
  }
  return data[size - idx]; // Arabic operator[]
  // return data[idx];     // European operator[]
}

template <typename T>
template <typename U>
typename std::enable_if<std::is_arithmetic<U>::value, U>::type
DynamicArray<T>::operator()() {
  if (isEmpty()) {
    return 0;
  }
  U sum = 0;
  for (int i = 0; i <= size; ++i) {
    sum += data[i];
  }
  return sum;
}

////////////////////////////////////////////// HW

template <typename T> void DynamicArray<T>::push_front(T x) {
  if (size + 1 >= capacity) {
    std::int64_t newCapacity = capacity * 2;
    T *tempArray = new T[newCapacity];
    for (int i = 0; i < capacity; ++i) {
      tempArray[i + 1] = data[i];
    }
    delete[] data;
    data = tempArray;
    capacity = newCapacity;
    data[0] = x;
    ++size;
    return;
  } else {
    T temp = data[0];
    for (int i = 0; i <= size; ++i) {
      std::swap(data[i + 1], temp);
    }
    data[0] = x;
    ++size;
    return;
  }
}

template <typename T> T DynamicArray<T>::front() {
  if (isEmpty()) {
    throw std::invalid_argument("Empty array");
  }
  return data[0];
}

template <typename T> T DynamicArray<T>::back() {
  if (isEmpty()) {
    throw std::invalid_argument("Empty array");
  }
  return data[size];
}

template <typename T> void DynamicArray<T>::insert(std::int64_t idx, T val) {
  if (idx < 0 || idx > size + 1) {
    throw std::invalid_argument("Index out of range");
  }

  // сдвигать элементы массива, стоящие правее data[idx] вправо(Без этого, это
  // не инсерт, а replace)
  if (size + 1 >= capacity) {
    std::int64_t newCapacity = capacity * 2;
    T *tempArray = new T[newCapacity];
    for (int i = 0; i < idx; ++i) {
      tempArray[i] = data[i];
    }
    tempArray[idx] = val;
    for (int i = idx; i <= size; ++i) {
      tempArray[i + 1] = data[i];
    }
    delete[] data;
    data = tempArray;
    capacity = newCapacity;
    ++size;
    return;
  } else {
    T temp = data[idx];
    data[idx] = val;
    for (int i = idx; i <= size; ++i) {
      std::swap(data[i + 1], temp);
    }
    ++size;
    return;
  }
}

template <typename T> void DynamicArray<T>::erase(std::int64_t idx) {
  if (idx < 0 || idx > size) {
    throw std::invalid_argument("Index out of range");
  }
  // сдвигать элементы массива, стоящие правее data[idx] влево
  for (int i = idx; i < size; ++i) {
    data[i] = data[i + 1];
  }
  --size;
}

template <typename T> void DynamicArray<T>::erase_after(std::int64_t idx) {
  if (idx < 0 || idx > size) {
    throw std::invalid_argument("Index out of range");
  }
  for (int i = idx + 1; i <= size; ++i) {
    --size;
  }
  // удалить все после элемента idx (тебя должен капасити остаться тот же, в то
  // время как элементов для доступа меньше)
  //  Было 10 элементов, капасити 15
  //  Erase_after(5)
  //  Остаются первые 6, капасити также 15, размер 6
}

template <typename T>
void DynamicArray<T>::increase_capacity(std::int64_t newCapacity) {
  if (newCapacity <= capacity) {
    throw std::invalid_argument(
        "New capacity must be greater than current capacity");
  }
  T *tempArray = new T[newCapacity];
  for (int i = 0; i <= size; ++i) {
    tempArray[i] = data[i];
  }
  delete[] data;
  data = tempArray;
  capacity = newCapacity;
}

template <typename T>
void DynamicArray<T>::decrease_capacity(std::int64_t newCapacity) {
  if (newCapacity < 0) {
    throw std::invalid_argument(
        "New capacity must be greater than or equal to number of elements");
  }
  // новая вместимость может быть меньше количества элементов
  T *tempArray = new T[newCapacity];
  for (int i = 0; (i <= size) && (i < newCapacity); ++i) {
    tempArray[i] = data[i];
  }
  delete[] data;
  data = tempArray;
  capacity = newCapacity;
  if (size >= newCapacity) {
    size = newCapacity - 1;
  }
}

template <typename T> std::int64_t DynamicArray<T>::getSize() const {
  return size + 1; // size хранит индекс последнего элемента, поэтому +1
}

// указываем линковщику, что нужно использовать шаблонные функции для этих типов
template class DynamicArray<int>;
template class DynamicArray<float>;
template class DynamicArray<double>;
template class DynamicArray<std::string>;
template int DynamicArray<int>::add<int>(std::int64_t, std::int64_t);
template int DynamicArray<int>::max<int>();
template int DynamicArray<int>::min<int>();
template float DynamicArray<float>::add<float>(std::int64_t, std::int64_t);
template float DynamicArray<float>::max<float>();
template float DynamicArray<float>::min<float>();
template double DynamicArray<double>::add<double>(std::int64_t, std::int64_t);
template double DynamicArray<double>::max<double>();
template double DynamicArray<double>::min<double>();
template float DynamicArray<float>::operator()<float>();
