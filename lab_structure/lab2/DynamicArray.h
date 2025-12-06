#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <cstdint>
#include <stdexcept>
#include <type_traits>

template <typename T> class DynamicArray {
private:
  T *data;
  std::int64_t size = -1; // actual (last occupied)
  std::int64_t capacity;  // max

public:
  bool isEmpty() { return size == -1; }
  DynamicArray();                      // default ctor
  DynamicArray(std::int64_t capacity); // parametrized ctor
  DynamicArray(DynamicArray &other);
  DynamicArray &operator=(const DynamicArray &other); // copy assignment
  ~DynamicArray();                                    // destructor

  void push_back(T x);

  // Арифметические операции (только для числовых типов)
  template <typename U = T>
  typename std::enable_if<std::is_arithmetic<U>::value, U>::type
  add(std::int64_t idx1, std::int64_t idx2);

  template <typename U = T>
  typename std::enable_if<std::is_arithmetic<U>::value, U>::type max();

  template <typename U = T>
  typename std::enable_if<std::is_arithmetic<U>::value, U>::type min();

  void clear();        // deallocate the data
  void reinitialize(); // restore to default
  void printData();

  T operator[](std::int64_t idx);
  template <typename U = T>
  typename std::enable_if<std::is_arithmetic<U>::value, U>::type operator()();

  void push_front(T x);
  T front(); // получить нулевой элемент
  T back();  // получить последний элемент
  void insert(std::int64_t idx,
              T val); // сдвигать элементы массива, стоящие правее data[idx]
                      // вправо(Без этого, это не инсерт, а replace)
  void erase(std::int64_t idx); // сдвигать элементы массива, стоящие правее
                                // data[idx] влево
  void erase_after(
      std::int64_t
          idx); // удалить все после элемента idx (тебя должен капасити остаться
                // тот же, в то время как элементов для доступа меньше)
                //  Было 10 элементов, капасити 15
                //  Erase_after(5)
                //  Остаются первые 6, капасити также 15, размер 6
  void increase_capacity(std::int64_t newCapacity);
  void
  decrease_capacity(std::int64_t newCapacity); // новая вместимость может быть
                                               // меньше количества элементов

  std::int64_t getSize() const; // получить текущий размер массива
};

#endif // DYNAMICARRAY_H
