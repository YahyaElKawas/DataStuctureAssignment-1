#pragma once

template<class T>
class Queue
{
private:
    int capacity;
    int front, rear;
    int size;
    T* arr{};
    int next(int idx);
public:
    Queue(int capacity);

    void enqueue(T element);
    T dequeue();
    T first();
    
    bool isEmpty();
    bool isFull();

    void clear();
    void print();
};

template<class T>
struct ListNode
{
    T val;
    ListNode* next{};
    ListNode(){}
    ListNode(T value) : val(value), next(nullptr) {}
    ListNode(T value, ListNode *next) : val(value), next(next) {}
};

template<class T>
class QueueBasedLinkedLis
{
private:
    ListNode<T>* head{};
    ListNode<T>* Tail{};
    int size{};
public:
    QueueBasedLinkedLis();
    ~QueueBasedLinkedLis();

    void enqueue(T element);
    T dequeue();
    T first();
    
    bool isEmpty();
    int Size();
    void clear();
    void print();
};

#include"Queue.cpp"
#include"QueueBasedLinkedLis.cpp"