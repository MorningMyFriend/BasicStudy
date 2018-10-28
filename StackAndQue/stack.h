//
// Created by wurui on 18-10-26.
//

#ifndef ALGORITHM_STACK_H
#define ALGORITHM_STACK_H

#include <iostream>
#include <vector>

template <class T>
class StackArray {
public:
    StackArray(){};
    StackArray(std::vector<T> &array):_array(array){}
    StackArray(const StackArray& stackArray) = delete;

    int Size(){ return _array.size();}

//    std::vector<T>::size_type Size(){ return _array.size();}

    bool Push(T &item){
        _array.emplace_back(item);
    }

    T Pop(){
        T data = _array.back();
        _array.pop_back();
        return data;
    }

private:
    std::vector<T> _array;
};

class TwoStackDijkstra{

};


#endif //ALGORITHM_STACK_H
