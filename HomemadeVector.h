//
// Created by Iulia on 4/6/2022.
//

#ifndef LAB7_8_HOMEMADEVECTOR_H
#define LAB7_8_HOMEMADEVECTOR_H
#include <ostream>
#include "Cheltuiala.h"

template<class T>
class Vector {
private:
    int CAPACITY_BATCH_SIZE = 1024;
    T *_entities;
    int _capacity{};
    int _size{};

    void resize();

public:
    Vector();

    Vector(const Vector<T> &vector);

    ~Vector();

    void push_back(T entity);

    int size() const;

    T at(int index) const;

    T operator[](int index) const;
    void insert(int index, T entity);

    void remove(int index);

    friend std::ostream &operator<<(std::ostream &os, const Vector<T> &vector) {
        for (int i = 0; i < vector._size; i++) {
            os << vector[i] << '\n';
        }
        return os;
    }
};

template<class T>
Vector<T>::Vector() {
    _capacity = CAPACITY_BATCH_SIZE;
    _entities = new T[_capacity];
    _size = 0;
}

template<class T>
Vector<T>::Vector(const Vector<T> &vector) {
    this->_capacity = vector._capacity;
    this->_size = vector._size;
    auto *newEntities = new T[_capacity];
    for (int i = 0; i < _size; i++) {
        newEntities[i] = vector._entities[i];
    }
    this->_entities = newEntities;
}

template<class T>
Vector<T>::~Vector() {
    delete[] _entities;
}

template<class T>
void Vector<T>::resize() {
    _capacity = _capacity + CAPACITY_BATCH_SIZE;
    auto *newEntities = new T[_capacity];
    for (int i = 0; i < _size; i++) {
        newEntities[i] = _entities[i];
    }
    delete[] _entities;
    _entities = newEntities;
}

template<class T>
void Vector<T>::push_back(T entity) {
    if (_size == _capacity) {
        resize();
    }
    _entities[_size] = entity;
    _size++;
}

template<class T>
int Vector<T>::size() const {
    return this->_size;
}

template<class T>
T Vector<T>::operator[](int index) const {
    return this->_entities[index];
}

template<class T>
T Vector<T>::at(int index) const {
    return this->_entities[index];
}

template<class T>
void Vector<T>::remove(int index) {
    int i;
    if (index >= this->_size) {
        return;
    }
    for (i = index; i < this->_size - 1; i++) {
        this->_entities[i] = this->_entities[i + 1];
    }
    this->_size = this->_size - 1;
}

template<class T>
void Vector<T>::insert(int index, T entity) {
    for(int i=this->_size; i>index; i++){
        this->_entities[i] = this->_entities[i-1];
    }
    this->_entities[index] = entity;
    this->_size++;
}


#endif //LAB7_8_HOMEMADEVECTOR_H
