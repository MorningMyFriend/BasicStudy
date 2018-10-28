//
// Created by wurui on 18-10-26.
//

#include <iostream>

#include "resizing_array.h"
#include "linked_list.h"
#include "stack.h"
#include "que.h"
#include "copy_forbidden.h"

using namespace std;

void test_array() {
    ResizingArray<int> array = ResizingArray<int>();
    array.Print();
    cout << "size:" << array.Size() << " capacity:" << array.Capacity() << endl;
    int a = 2;
    array.Push(a);
    array.Push(a);
    array.Push(a);
    array.Insert(5, 3);
    array.Print();
    cout << "size:" << array.Size() << " capacity:" << array.Capacity() << endl;

    cout << "pop:" << array.Pop() << endl;
    cout << "pop:" << array.Pop() << endl;
    cout << "pop:" << array.Pop() << endl;
    cout << "size:" << array.Size() << " capacity:" << array.Capacity() << endl;

}

void test_list() {
    LinkedList<int> llist = LinkedList<int>();
    llist.Push(0);
    llist.Push(1);
    llist.Push(2);
    cout << llist.Pop() << endl;
    llist.Push(3);
    llist.Print();
    llist.Insert(9,0);
    llist.Print();
    llist.Insert(10, llist.Size()-1);
    llist.Print();

    LinkedList<int> linkedList = LinkedList<int>(llist);
    linkedList.Erase(3);
    linkedList.Print();

   LinkedList<int>::Iterator iter = llist.begin();
    cout << *(iter) << endl;

}

void test_stack(){
    vector<int> v = {1,2,3};
    StackArray<int> *stackArray = new StackArray<int>(v);
    cout << stackArray->Size() << endl;
    cout << stackArray->Pop() << endl;
}

int main() {
    test_list();
}
