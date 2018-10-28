//
// Created by wurui on 18-10-26.
//

#ifndef ALGORITHM_RESIZING_ARRAY_H
#define ALGORITHM_RESIZING_ARRAY_H


template<class T>
class ResizingArray {
public:
    ResizingArray() : _size(1), _capacity(1) {
        _array = new T[1];
    }

    bool Push(T &item) {
        if (_size == _capacity) {
            Resize(2 * _capacity);
        }
        _array[_size] = item;
        _size++;
        return true;
    }

    T Pop() {
        T item = _array[_size - 1];
        _array[_size - 1] = NULL;
        _size--;
        if (_size > 0 && _size <= static_cast<int>(_capacity / 4)) {
            Resize(static_cast<int>(_capacity / 4));
        }
        return item;
    }

    bool Insert(T item, int i) {
        if (i < 0 || i > _size - 1) {
            std::cerr << "out of range" << std::endl;
            return false;
        } else {
            T *temp;
            if (_size == _capacity) {
                temp = new T[2 * _capacity];

            } else {
                temp = new T[_capacity];
            }

            int k = 0; // temp
            for (int j = 0; j < _size; j++) {
                if (j == i) {
                    temp[k] = item;
                    k++;
                }

                temp[k] = _array[j];
                k++;
            }

            delete[]_array;
            _array = temp;
            _size++;
            return true;

        }
    }

    const T at(int i) {
        if (i < _size) {
            return _array[i];
        } else {
            std::cerr << "out of range" << std::endl;
            throw i;
        }
    }

    T &operator[](int i) {
        if (i < _size) {
            return _array[i];
        } else {
            std::cerr << "out of range" << std::endl;
            throw i;
        }
    };

    int Capacity() {
        return _capacity;
    }

    int Size() {
        return _size;
    }

    void Print() {
        for (int i = 0; i < _size; ++i) {
            std::cout << _array[i] << ", " << std::endl;
        }
    }

private:
    int _size;
    int _capacity;
    T *_array;

    void Resize(int length) {
        T *temp = new T[length];
        for (int i = 0; i < std::min(_size, length); ++i) {
            temp[i] = _array[i];
        }
        delete[] _array;
        _array = temp;
        _capacity = length;
    }

};


#endif //ALGORITHM_RESIZING_ARRAY_H
