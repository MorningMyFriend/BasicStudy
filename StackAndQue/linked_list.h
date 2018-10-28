//
// Created by wurui on 18-10-26.
//

#ifndef ALGORITHM_LINKED_LIST_H
#define ALGORITHM_LINKED_LIST_H

#include <iostream>

template<class T>
struct Node {
    Node(T item) : data(item), next(nullptr) {}

    T data;
    Node *next;
};

template<class T>
class LinkedList {
public:
    LinkedList() : _size(0), _head(nullptr) {};

    LinkedList(const LinkedList &linkedList) : _head(linkedList._head), _size(linkedList._size) {}

    ~LinkedList() {
        Node<T> *first = _head;
        while (first->next != nullptr) {
            Node<T> *next = first->next;
            delete first;
            first = next;
        }
    }

    int Size() { return _size; }

    bool Insert(T item, int i) {
        // insert into (i-1,i)
        if (i > _size - 1 || i < 0) {
            std::cerr << "out of range" << std::endl;
            return false;
        }

        if (i == 0) {
            Node<T> *node = new Node<T>(item);
            Node<T> *temp = _head;
            _head = node;
            _head->next = temp;
        } else {
            Node<T> *temp = _head;
            int index = 1;
            while (index < i) {
                temp = temp->next;
                index++;
            }
            if (temp != nullptr) {
                Node<T> *node_after = temp->next;
                Node<T> *node_new = new Node<T>(item);
                temp->next = node_new;
                node_new->next = node_after;
            }
        }
        _size++;
        return true;
    }

    bool Push(T item) {
        if (_head == nullptr) {
            Node<T> *node = new Node<T>(item);
            _head = node;
        } else {
            Node<T> *temp = _head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            Node<T> *node = new Node<T>(item);
            temp->next = node;
        }
        _size++;
    }

    bool Erase(int i) {
        if (_head == nullptr) {
            throw "null list";
        } else if (i < 0 || i > _size - 1) {
            throw "out of range";
        }

        if (i == 0) {
            Node<T> *node = _head->next;
            delete _head;
            _head = node;
        } else {
            int index = 0;
            Node<T> *node = _head;
            while (node->next != nullptr) {
                if (index + 1 == i) {
                    Node<T> *node_after_i = node->next->next;
                    node->next = node_after_i;
                    delete node->next;
                    break;
                } else {
                    node = node->next;
                    index++;
                }
            }
        }
        _size--;
        return true;
    }

    T Pop() {
        if (_head == nullptr) {
            throw "null list";
        }

        Node<T> *node = _head;
        Node<T> *node_after = node->next;

        if (node_after == nullptr) {
            T data = _head->data;
            delete _head;
            _head = nullptr;
            _size--;
            return data;
        }

        while (node_after->next != nullptr) {
            node = node_after;
            node_after = node_after->next;
        }
        T data = node_after->data;
        delete node_after;
        node_after = nullptr;
        node->next = nullptr;
        _size--;
        return data;
    }

    void Print() {
        Node<T> *node = _head;
        while (node != nullptr) {
            std::cout << node->data << ", " << std::endl;
            node = node->next;
        }
        std::cout << std::endl;
    }

    Node<T> *Head() { return _head; }

    class Iterator {
    public:
        Iterator():_iter(nullptr) {}

        Iterator(const Node<T>* node):_iter(const_cast<Node<T>*>(node)){}

        ~Iterator() { delete _iter; }

        T &operator*() { return _iter->data; }

        T *operator->() { return &_iter->data; }

        // 前加
        Iterator &operator++() {
            _iter = _iter->next;
            return *this;
        };

        // 后加
        Iterator &operator++(int) {
            Iterator old = *this;
            _iter = _iter->next;
            return old;
        }

        bool operator==(const Iterator &right) {
            return _iter == right._iter;
        }

        bool operator!=(const Iterator &right) {
            return _iter != right._iter;
        }


    protected:
        Node<T> *_iter;
    };

    Iterator begin(){
        return Iterator(_head);
    }

    Iterator end(){
        return Iterator();
    }


private:
    int _size;
    Node<T> *_head;
};


#endif //ALGORITHM_LINKED_LIST_H
