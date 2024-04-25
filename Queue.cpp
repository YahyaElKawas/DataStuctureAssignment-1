#include<iostream>
#include<assert.h>
#include "Queue.hpp"
using namespace std;

template <class T>
int Queue<T>::next(int idx)
{
    if(++idx == capacity)
        return 0;
    return idx + 1;
}


template <class T>
inline Queue<T>::Queue(int _capacity) : capacity(_capacity), front(0), rear(0), size(0)
{
    arr = new T(capacity);
}


template <class T>
void Queue<T>::enqueue(T element)
{
    assert(!isFull());
    arr[rear] = element;
    rear = next(rear);
    size++;
}

template <class T>
T Queue<T>::dequeue()
{
    assert(!isEmpty());
    T removed = arr[front];
    front = next(front);
    size--;
    return removed;
}

template <class T>
T Queue<T>::first()
{
    assert(!isEmpty());
    return arr[front];
}

template <class T>
bool Queue<T>::isEmpty()
{
    return (size == 0);
}

template <class T>
bool Queue<T>::isFull()
{
    return (size == capacity);
}

template <class T>
void Queue<T>::clear()
{
    front = 0;
    rear = 0;
    size = 0;
}

template <class T>
void Queue<T>::print()
{
    cout << "size: " << size << '\n';
    for(int i = 0 ; i < size; ++i){
        cout << arr[i] << endl;
    }
}
