#include<iostream>
#include<assert.h>
#include "Queue.hpp"
using namespace std;


template<class T>
QueueBasedLinkedLis<T>::QueueBasedLinkedLis(){
    // cout << "this queue based linke list";
}

template <class T>
QueueBasedLinkedLis<T>::~QueueBasedLinkedLis()
{
    clear();
    delete head, Tail;
}

template <class T>
void QueueBasedLinkedLis<T>::enqueue(T element)   // O(1)
{
    ListNode<T>* node = new ListNode(element);
    if(head == nullptr)
        head = Tail = node;
    else{
        Tail->next = node;
        Tail = node;
    }
    size++;
}

template <class T>
T QueueBasedLinkedLis<T>::dequeue()          // O(1)
{
    assert(!isEmpty());
    ListNode<T>* removed = head;
    T removedValue = removed->val;
    head = head->next;
    size--;
    if(isEmpty())
        head = Tail = nullptr;
    
    delete removed;
    return removedValue;
}

template <class T>
T QueueBasedLinkedLis<T>::first()          // O(1)
{
    assert(!isEmpty());
    return head->val;
}

template <class T>
bool QueueBasedLinkedLis<T>::isEmpty()     // O(1)
{
    return (size == 0);
}

template <class T>
int QueueBasedLinkedLis<T>::Size()
{
    return size;
}

template <class T>
void QueueBasedLinkedLis<T>::clear()       // O(n)
{
    for(int i = 0; i < size; ++i){
        ListNode<T>* removed = head;
        head = head->next;
        delete removed;
    }
    head = Tail = nullptr;
    size = 0;
}

template <class T>
void QueueBasedLinkedLis<T>::print()
{
    cout << "size: " << size << endl;
    for(ListNode<T>* cur = head; head; head = head->next){
        cout << head->val << end;
    }
}
