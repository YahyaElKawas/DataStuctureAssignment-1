#include<iostream>
#include"Queue.hpp"
#include"Stack.hpp"
#include"SinglyLinkedList.hpp"
#include"DoublyLinkedList.hpp"
#include"CircularLinkedList.hpp"
#include "Student.cpp"
#include"Sorting.cpp"
#include <vector>
#include <functional>
// #include <algorithm>

using namespace std;




bool compareGBA(Student s1, Student s2){
    return (s1.getGpa() < s2.getGpa());
}


    // Mariam 69712 3.7
    // Ali 3541 3.5
    // Sara  78697 3.1
    // Mohamed  97848 2.2    



int main()
{
    // Student arr[4];
    
    // for(int i = 0; i < 4; ++i){
    //     string name, id;
    //     double gpa;
    //     cin >> name >> id >> gpa;
    //     arr[i].setName(name);
    //     arr[i].setId(id);
    //     arr[i].setGpa(gpa);
    // }
    

    // cout << "-------Insertion Sort by Gpa-----------\n";
    // insertionSort(arr, arr+4, compareGBA); // compare by GPA
    // for(int i = 0; i < 4; ++i)
    //     cout << arr[i];
    
    // cout << "-------Insertion Sort by Name-----------\n";
    // insertionSort(arr, arr+4);        // compare by name
    // for(int i = 0; i < 4; ++i)
    //     cout << arr[i];
    
    // cout << "---------Bubble Sort---------\n";
    // BubbleSort(arr, arr+4, compareGBA); // compare by GPA
    // for(int i = 0; i < 4; ++i)
    //     cout << arr[i];
    
    // cout << "--------Count Sort----------\n";
    // CountSort(arr, arr+4 , compareGBA);
    // for(int i = 0; i < 4; ++i)
    //     cout << arr[i];

    // cout << "-------merge Sort by Gpa-----------\n";
    // mergeSort(arr, arr+4, compareGBA); // compare by GPA
    // for(int i = 0; i < 4; ++i)
    //     cout << arr[i];
    

    // Stack<int> s(5);
    // s.push(1);
    // s.push(2);
    // s.push(3);
    // s.push(4);
    // s.push(5);
    // s.print();
    
    // SinglyLinkedList<int> StackLinkedList;
    // StackLinkedList.insertAtTail(1);
    // StackLinkedList.insertAtTail(2);
    // StackLinkedList.insertAtTail(3);
    // StackLinkedList.insertAtTail(4);
    // StackLinkedList.print();


    int arr[] {123,321312,22,1,3,5};
    BubbleSort(arr, arr+6);
    for(int i = 0;i < 6; ++i)
        cout << arr[i] << ' ';

}