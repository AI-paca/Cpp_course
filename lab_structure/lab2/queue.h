#ifndef QUEUE_H
#define QUEUE_H

#include "DynamicArray.h"

template<typename x>
class queue {
private:


protected:
public:

//место для коструктора с параметром, который задает максимальный размер стека (int_t64_t) т.к. размер может быть -1000


//Для класса queue необходимо имлементировать:
    void enqueue(x); //добавить элемент в очередь
    x dequeue(); //удалить элемент из очереди и вернуть его
    bool isEmpty(); //проверка очереди на пустоту
    int size(); //возвращает кол-во элементов в очереди
};

#endif // QUEUE_H