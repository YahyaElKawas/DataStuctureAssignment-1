#include <iostream>
#include <exception>

#include "Stack.hpp"
using namespace std;
/*=============================================================================================================*/
/*Stack Array Implementation*/
/*=============================================================================================================*/
template <class T>
bool Stack<T>::isEmpty()
{
    return inx == -1;
}
//------------------------------------------------------------
template <class T>
Stack<T>::Stack(int x)
{
    size = x;
    v = new T[size];
}
//------------------------------------------------------------
template <class T>
void Stack<T>::push(T x)
{
    if (stackSize() == size)
    {
        cout << "The Stack is Full\n";
        return;
    }
    v[++inx] = x;
}
//------------------------------------------------------------
template <class T>
int Stack<T>::stackSize()
{
    return inx + 1;
}
//------------------------------------------------------------
template <class T>
T Stack<T>::pop()
{
    try
    {
        if (isEmpty())
        {
            throw runtime_error("The Stack is Empty");
        }
        int tmp = v[inx--];
        return tmp;
    }
    catch (exception &e)
    {
        cout << "Exception: " << e.what() << '\n';
    }
}
//------------------------------------------------------------
template <class T>
T Stack<T>::top()
{
    try
    {
        if (isEmpty())
        {
            throw runtime_error("The Stack is Empty");
        }
        return v[inx];
    }
    catch (exception &e)
    {
        cout << "Exception: " << e.what() << '\n';
    }
}
//------------------------------------------------------------
template <class T>
void Stack<T>::clear()
{
    inx = -1;
    return;
}
//------------------------------------------------------------
template <class T>
void Stack<T>::print()
{
    for (int i = inx; i >= 0; --i)
    {
        cout << v[i] << ' ';
    }
    cout << endl;
}
/*=============================================================================================================*/
/*Stack Linked list implementation (All Functions)*/
/*=============================================================================================================*/
template <class T>
StackLinkedList<T>::StackLinkedList(int x)
{
    size = x;
}
//------------------------------------------------------------

template <class T>
void StackLinkedList<T>::push(T x)
{
    if (cn == size)
    {
        cout << "The Stack is Full\n";
        return;
    }
    Snode<T> *newSnode = new Snode<T>(x);
    if (!tail)
    {
        tail = newSnode;
    }
    else
    {
        newSnode->pre = tail;
        tail->next = newSnode;
        tail = newSnode;
    }
    ++cn;
}
//------------------------------------------------------------
template <class T>
void StackLinkedList<T>::print()
{
    for (Snode<T> *cur = tail; cur; cur = cur->pre)
    {
        cout << cur->data << ' ';
    }
    cout << '\n';
}
//------------------------------------------------------------

template <class T>
T StackLinkedList<T>::pop()
{
    try
    {
        if (!tail)
        {
            throw runtime_error("The Stack is Empty");
        }

        Snode<T> *tmp = tail;
        T x = tail->data;
        tail = tail->pre;
        delete tmp;
        --cn;
        return x;
    }
    catch (exception &e)
    {
        cout << "Exception: " << e.what() << '\n';
    }
}
//------------------------------------------------------------
template <class T>
T StackLinkedList<T>::top()
{
    try
    {
        if (isEmpty())
        {
            throw runtime_error("The Stack is Empty");
        }
        return tail->data;
    }
    catch (exception &e)
    {
        cout << "Exception: " << e.what() << '\n';
    }
}
//------------------------------------------------------------

template <class T>
bool StackLinkedList<T>::isEmpty()
{
    return tail == nullptr;
}
//------------------------------------------------------------
template <class T>
void StackLinkedList<T>::clear()
{
    if (isEmpty())
    {
        return;
    }
    while (tail)
    {
        Snode<T> *tmp = tail;
        tail = tail->pre;
        delete tmp;
    }
}
//------------------------------------------------------------

template <class T>
int StackLinkedList<T>::stackSize()
{
    return cn;
}
//------------------------------------------------------------
