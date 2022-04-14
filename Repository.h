//
// Created by Iulia on 4/7/2022.
//

#ifndef LAB7_8_REPOSITORY_H
#define LAB7_8_REPOSITORY_H
using namespace std;
#include<ostream>
#include "../Domain/Cheltuiala.h"
#include "../Domain/HomemadeVector.h"
template<class T>
class Repository {
private:
    Vector<T> entities;
public:
    Repository();

    ~Repository();

    void addEntity(T entity);

    void deleteEntity(T entity);

    void updateEntity(int index, T entity);

    Vector<T> getAll();

    T getEntity(int index);

    T getEntityById(int id);

    int getSize();

    template<class Y>
    friend std::ostream &operator<<(std::ostream &os, const Repository<Y> &repository);
};

template<class T>
Repository<T>::Repository() {

}

template<class T>
Repository<T>::~Repository() = default;

template<class T>
void Repository<T>::addEntity(T entity) {
    this->entities.push_back(entity);
}

template<class T>
Vector<T> Repository<T>::getAll() {
    return entities;
}

template<class T>
T Repository<T>::getEntity(int index) {
    return entities.at(index);
}

template<class T>
int Repository<T>::getSize() {
    return this->entities.size();
}

template<class Y>
std::ostream &operator<<(std::ostream &os, const Repository<Y> &repository) {
    os << repository.entities;
    return os;
}

template<class T>
void Repository<T>::deleteEntity(T entity) {
 for(int i = 0; i< entities.size(); i++ )
     if(this->entities[i]==entity){
         this->entities.remove(i);
         break;
     }
}

template<class T>
void Repository<T>::updateEntity(int index, T entity) {
    this->entities.remove(index);
    this->entities.insert(index, entity);
}

#endif //LAB7_8_REPOSITORY_H
