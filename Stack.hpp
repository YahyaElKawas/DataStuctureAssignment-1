#ifndef _STACK_HPP
#define _STACK_HPP
// Snode for making the Linked list
template <class T>
struct Snode
{
    T data{};
    Snode *next{};
    Snode *pre{};
    Snode(T x)
    {
        data = x;
    }
};
// Stack Interface
template <class T>
class Stack
{
private:
    int size;
    int inx = -1;
    T *v;

public:
    Stack(int size);
    void push(T x);
    T top();
    T pop();
    bool isEmpty();
    int stackSize();
    void clear();
    void print();
};
// Stack Linked List Interface
template <class T>
class StackLinkedList
{
private:
    Snode<T> *tail{};
    int size;
    int cn = 0;

public:
    StackLinkedList(int size);
    void push(T x);
    T top();
    T pop();
    bool isEmpty();
    int stackSize();
    void clear();
    void print();
};
#include "Stack.cpp"
#endif
