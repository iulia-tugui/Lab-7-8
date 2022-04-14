//
// Created by Iulia on 4/6/2022.
//
#include <iostream>
#include <utility>
#include "Cheltuiala.h"
#include <cstring>

Cheltuiala::Cheltuiala() {
    this->id = 0;
    this->sum = 0;
    this->apartmentNumber = 0;
    this->typeOfExpense = nullptr;
}

Cheltuiala::Cheltuiala(int id, int sum, int apartmentNumber, const char * typeOfExpense) {
    this->id = id;
    this->sum = sum;
    this->apartmentNumber = apartmentNumber;
    this->typeOfExpense = new char[strlen(typeOfExpense)+1];
    std::strcpy(this->typeOfExpense, typeOfExpense);
}

void Cheltuiala::setSum(int newSum) {
    this->sum = newSum;

}

int Cheltuiala::getSum() {
    return this->sum;

}

std::ostream &operator<<(std::ostream &os, const Cheltuiala &cheltuiala) {
    os << "Expense :" << cheltuiala.id << '\n' << '{' << '\n';
    os << "Apartment number: " << cheltuiala.apartmentNumber << '\n';
    os << "Sum: " << cheltuiala.sum << '\n';
    os << "Type of expense : " << cheltuiala.typeOfExpense << '\n';
    os << '\n' << '}' << '\n';
    return os;
}

std::istream &operator>>(std::istream &is, Cheltuiala &cheltuiala) {
    std::cout << "Expense id =";
    is >> cheltuiala.id;
    std::cout << "Apartment number = ";
    is >> cheltuiala.apartmentNumber;
    std::cout << "Sum = ";
    is >> cheltuiala.sum;
    std::cout << "Type of expense = ";
    is >> cheltuiala.typeOfExpense;
}


bool Cheltuiala::operator==(const Cheltuiala &rhs) const {
    if(abs(sum - rhs.sum) < 1e-9)
        return true;
    return false;
}

bool Cheltuiala::operator!=(const Cheltuiala &rhs) const {
    return !(rhs == *this);
}

void Cheltuiala::setApartmentNumber(int newApartmentNumber) {
    this->apartmentNumber = newApartmentNumber;
}

void Cheltuiala::setTypeOfExpense(const char * newTypeOfExpense) {
    if(this->typeOfExpense){
        delete[] typeOfExpense;
    }
    this->typeOfExpense = new char[strlen(newTypeOfExpense)+1];
    std::strcpy(this->typeOfExpense, newTypeOfExpense);
}

int Cheltuiala::getApartmentNumber() {
    return this->apartmentNumber;
}

char * Cheltuiala::getTypeOfExpense() {
    return const_cast<char *>(this->typeOfExpense);
}

int Cheltuiala::getId() {
    return this->id;
}

