#ifndef QUEUE_H
#define QUEUE_H

class queue {
private:
//Класс `queue` должен быть шаблонным и имплементирован с использованием класса stack
protected:
public:
//Для класса queue необходимо имлементировать:
    void enqueue(x); //добавить элемент в очередь
    x dequeue(); //удалить элемент из очереди и вернуть его
    bool isEmpty(); //проверка очереди на пустоту
    int size(); //возвращает кол-во элементов в очереди
};

#endif // QUEUE_H