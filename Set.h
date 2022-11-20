//
// Created by Mehdi Haddoud on 2022-11-12.
//

#ifndef SET_SET_H
#define SET_SET_H

#include <cassert>
#include <iostream>
#include<string>


using namespace std;

template<typename T>

class Set {

public:

    Set();

    Set(int N);

    Set(T* input, int N);

    Set(const Set& right);

    Set<T>& operator=(const Set<T>& right);

    int getSize() const;

    T& operator[](const int& i);

    T operator[](const int& i) const;

    int getNbElement() const;

    void add(T n);

    bool contains(const T& element) const;

    ~Set();

private:

    void erase();

    void copy(const Set<T>& input);

    void increaseMemorySize();

    int nbElement;

    T* elements;

    int size;

};

template<typename T>

Set<T>::Set() {

    this->elements = nullptr;

    this->nbElement = 0;

    this->size = 0;

}

template<typename T>
Set<T>::Set(int N) {

    this->nbElement = 0;

    this->size = 0;

    this->elements = new T[N];

}

template<typename T>
Set<T>::Set(T* input, int N) {

    this->size =N;

    this->nbElement = 0;

    this->elements = new T[N];

    for (int i = 0; i < N; ++i) {

        if(!this->contains(input[i]))
        {
            nbElement++;

            this->elements[nbElement - 1] = input[i];

        }

    }

}

template<typename T>

Set<T>::Set(const Set<T>&right) {

    copy(right);

}

template <typename T>
int Set<T>::getSize() const {
    return this->size;
}

template<typename T>
int Set<T>::getNbElement() const {
    return this->nbElement;
}

template<typename T>
bool Set<T>::contains(const T& element) const {

    for (int i = 0; i < this->nbElement; ++i) {

        if(this->elements[i] == element)
            return true;

    }

    return false;
}

template<typename T>
Set<T>& Set<T>::operator=(const Set<T> &right) {

    if(this != &right)
    {
        erase();

        copy(right);
    }

    return *this;
}

template<typename T>
void Set<T>::copy(const Set<T>& input) {

    this->size = input.getSize();

    this->nbElement = input.getNbElement();

    this->elements = new T[this->size];

    for (int i = 0; i < this->nbElement; ++i)
        this->elements[i] = input[i];

}

template<typename T>
T& Set<T>::operator[](const int &i) {

    assert(i >= 0 && i < nbElement);

    return this->elements[i];

}

template<typename T>
T Set<T>::operator[](const int &i) const {

    assert(i >= 0 && i < nbElement);

    return this->elements[i];

}

template<typename T>
void Set<T>::erase() {

    delete[] this->elements;

}

template<typename T>
Set<T>::~Set() {

    erase();

}

template<typename T>
void Set<T>::increaseMemorySize() {

    cout << "Memory increase!\n";

    T* new_array;

    this->size += 10;

    new_array = new T[this->size];

    for (int i = 0; i < this->nbElement; ++i)
        new_array[i] = this->elements[i];

    delete[] this->elements;

    this->elements = new_array;

}

template<typename T>
void Set<T>::add(T n) {

    if(!this->contains(n)) {

        this->nbElement++;

        if (this->nbElement > this->size) {

            this->increaseMemorySize();

            this->elements[this->nbElement - 1] = n;
        }

        else
            this->elements[this->nbElement - 1] = n;

    }

}

template<typename T>
ostream &operator<<(ostream &out, const Set<T> &right) {

    for (int i = 0; i < right.getNbElement(); ++i)
        out << right[i] << " ";

    return out;

}

template<typename T>
istream &operator>>(istream &in, Set<T> &right) {

    T input;

    T* buffer = new T[10];

    int capacity = 10;

    int nbElements = 0;


    while(!in.fail() && !in.eof()){

        in >> input;



        buffer[nbElements] = input;

        nbElements++;

        if(nbElements == capacity)
        {

            capacity+=10;

            T* new_buffer;

            new_buffer = new T[capacity];

            for (int i = 0; i < nbElements; ++i) {
                new_buffer[i] = buffer[i];
            }

            delete[] buffer;

            buffer = new_buffer;

        }

    }

    in.ignore();

    in.clear();

    cout << "capacity : " << capacity << '\n';

    right = Set<T>(buffer,nbElements);

    delete[] buffer;

    return in;
}




#endif //SET_SET_H
