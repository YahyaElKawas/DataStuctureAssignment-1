#pragma once
#include <iostream>
using namespace std;


template <typename T>
class Node {
public:
    T val;
    Node<T>* next;
    Node() : val{ }, next(nullptr) {}
    Node(T element) : val{ element }, next{ nullptr } {}
    ~Node() { }
};

template <typename T>
class SinglyLinkedList
{
private:
    Node<T>* head;
    int size;

public:
    SinglyLinkedList();
    SinglyLinkedList(T element);
    void insertAtHead(T element);
    void insertAtTail(T element);
    void insertAt(T element, int index);
    void removeAtHead();
    void removeAtTail();
    void removeAt(int index);
    T retrieveAt(int index);
    void replaceAt(T newElement, int index);
    bool isExist(T element);
    bool isItemAtEqual(T element, int index);
    void swapTwoNodes(int firstItemIdx, int secondItemIdx);
    bool isEmpty();
    int linkedListSize();
    void clear();
    void print();
    // ~SinglyLinkedList();
};

#include "SinglyLinkedList.cpp"
