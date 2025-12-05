#ifndef STACK_H
#define STACK_H

#include "DynamicArray.h"

template<typename x> //видимо это Template Specialization
class stack {
private:

//Класс `stack` обязан быть шаблонным и использовать внутри класс `DynamicArray`
  DynamicArray data; //так... а если я хочу хранить не float...
                     //а вдруг комментарии кто-то читает...  
  std::int64_t max_size; //максимальный размер стека
  std::int64_t current_size = 0; //текущий размер стека

//Класс `stack` имеет фиксированный максимальный размер, переполнение ведет в выбросу исключения `std::overflow_error`.


protected:

public:

//место для коструктора с параметром, который задает максимальный размер стека (int_t64_t) т.к. размер может быть -1000


    void push(x); //добавить элемент в стек
    x top(); //посмотреть на элемент, находящийся на вершине стека без удаления
    x pop(); //удалить элемент на вершине стека и вернуть его
    bool isEmpty(); //проверка стека на пустоту
    int size(); //возвращает кол-во элементов в стеке
};

#endif // STACK_H