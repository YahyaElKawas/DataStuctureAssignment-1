#include"SinglyLinkedList.hpp"

template <class T>
SinglyLinkedList<T>::SinglyLinkedList() {
    size = 0;
}

template<typename T>
SinglyLinkedList<T>::SinglyLinkedList(T element) {
    head = new Node<T>(element);
        head->next = nullptr;
        size = 1;
}

template<typename T>
void SinglyLinkedList<T>::insertAtHead(T element)
{
    Node<T> *new_node = new Node<T>(element);
        new_node->next = nullptr;
        if (size == 0) {
            head = new_node;
            size++;
        } else {
            new_node->next = head;
            head = new_node;
            size++;
        }
}

template <typename T>
void SinglyLinkedList<T>::insertAt(T element, int index)
{
    if (index == 1) {
            insertAtHead(element);
        }  
        else if (index == size + 1) {
            insertAtTail(element);
        }
        else if (index > size || index <= 0) {
            cout << "Invalid index\n" << endl;
        } else {
            int cnt = 1;
            for (Node<T>* prev = nullptr, *cur = head;cur != nullptr; prev = cur, cur = cur->next, cnt++) {
                if (cnt == index) {
				    Node<T> *new_node = new Node<T>(element);
                    prev->next = new_node;
				    new_node->next = cur;
                    size++;
                    break;
                }
            }
        }
}

template <typename T>
void SinglyLinkedList<T>::removeAtHead()
{
    if (size == 0) {
            cout << "List is empty can not remove from head\n" << endl;
        }
        else {
            if (size == 1)  {
                delete head;
                size = 0;
            } else {
                Node<T> *temp = head;
                head = head->next;
                delete temp;
                size--;
            }
        }
}

template <typename T>
void SinglyLinkedList<T>::removeAtTail()
{
    if (size == 0) {
        cout << "List is empty can not remove from Tail\n" << endl;
    } else {
        Node<T> *prev = nullptr , *cur = head;
        while(cur->next) {
            prev = cur;
            cur = cur->next;
        }
        prev->next = nullptr;
        delete cur;
        size--;
    }
}

template <typename T>
void SinglyLinkedList<T>::removeAt(int index)
{
    if (index > size || index <= 0) {
            cout << "Invalid index\n" << endl;
        } else if (index == 1) { 
            this->removeAtHead();
        } else if (index == size) {
            this->removeAtTail();
        
        } else {
            int cnt = 1;
            Node<T>* prev = nullptr , *cur = head;
            for (;cur->next != nullptr ; prev = cur, cur = cur->next, cnt++) {
                if (cnt == index) {
                    prev->next = cur->next;
                    delete cur;
                    size--;
                    break;
                }
            }
        }
}

template <typename T>
T SinglyLinkedList<T>::retrieveAt(int index)
{
    if (index > size || index <= 0)  {
        cout << "Invalid index\n" << endl;
        return 0;
    } else {
        int cnt = 1;
        Node<T>* prev = nullptr;
        for (Node<T>* cur = head; cur != nullptr; prev = cur, cur = cur->next, cnt++) {
            if (cnt == index) {
                return cur->val;
            }
        }
    }
}

template <typename T>
void SinglyLinkedList<T>::replaceAt(T newElement, int index)
{
    if (index > size || index <= 0) {
            cout << "Invalid index\n" << endl;
    } else {
        int cnt = 1;
        Node<T>* prev = nullptr;
        for (Node<T>* cur = head; cur != nullptr; prev = cur, cur = cur->next, cnt++) {
            if (cnt == index) {
                cur->val = newElement;
            }
        }
    }
}

template <typename T>
bool SinglyLinkedList<T>::isExist(T element)
{
    for (Node<T>* cur = head; cur; cur = cur->next) {
        if (cur->val == element) {
            return true;
        }
    }
    return false;
}

template <typename T>
bool SinglyLinkedList<T>::isItemAtEqual(T element, int index)
{
    if (index > size || index <= 0) {
        cout << "Invalid index\n" << endl;
        return false;
    } else {
        int cnt = 1;
        for (Node<T> *cur = head; cur; cur = cur->next, cnt++) {
            if (cnt == index) {
                if (cur->val == element) {
                    return true;
                
                }
                return false;
            }
        }
    }
}

template <typename T>
void SinglyLinkedList<T>::swapTwoNodes(int firstItemIdx, int secondItemIdx)
{
    if (firstItemIdx > size || firstItemIdx <= 0 || secondItemIdx > size || secondItemIdx <= 0) {
            cout << "Invalid index\n";
            return;
    } else if (firstItemIdx == secondItemIdx) {
            return;
    } else {
        Node<T> *first = head , *second = head , *temp_first= head, *temp_second = head;
        
        for (int i = 1; i < size; first = first->next ,++i) {
            if (i == firstItemIdx) {
                temp_first = first;
            }
        }
        for (int i = 1; i < size; second = second->next ,++i) {
            if(i == secondItemIdx) {
                temp_second = second;
            }
            
        }
        if (!first || !second)
            return;

        T temp = temp_first->val;
        temp_first->val = temp_second->val;
        temp_second->val = temp;
    }
}

template <typename T>
bool SinglyLinkedList<T>::isEmpty()
{
    if (size == 0) {
        return true;
    } return false;
}

template <typename T>
int SinglyLinkedList<T>::linkedListSize()
{
    return size;

}

template <typename T>
void SinglyLinkedList<T>::clear()
{
    Node<T>* prev = nullptr;
    Node<T>* cur = head;
    while (cur) {
        prev = cur;
        cur = cur->next;
        delete prev;
    }
    head = nullptr;
    size = 0;
}

template <typename T>
void SinglyLinkedList<T>::print()
{
    if (size == 0) {
        cout << "Can not print the list because the it is empty" << "\n";
        return;
    } else {
        for (Node<T>* cur = head; cur; cur = cur->next) {
            cout << cur->val << " --> ";
        }
        cout << "NULL" << "\n";
    }
}

template <typename T>
void SinglyLinkedList<T>::insertAtTail(T element)
{
    Node<T>* new_node = new Node<T>(element);
        new_node->next = nullptr;
        
        if (size == 0) {
            head = new_node;
            size++;
        } else {
            Node<T> *cur = head;
            while (cur->next) {
                cur = cur->next;
            }
            cur->next = new_node;
            size++;
        }
}






