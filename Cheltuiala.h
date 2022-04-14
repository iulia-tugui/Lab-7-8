//
// Created by Iulia on 4/6/2022.
//

#ifndef LAB7_8_ENTITY_H
#define LAB7_8_ENTITY_H
#include <iostream>
#include <string>

using namespace std;

class Cheltuiala {
private:
    int id;
    int sum;
    int apartmentNumber;
    char * typeOfExpense;
public:
    friend std::ostream &operator<<(std::ostream &os, const Cheltuiala &cheltuiala);

    friend std::istream &operator>>(std::istream &is, Cheltuiala &cheltuiala);

    Cheltuiala();

    Cheltuiala(int id, int sum, int apartmentNumber, const char* typeOfExpense);

    void setSum(int newSum);

    void setApartmentNumber(int newApartmentNumber);

    void setTypeOfExpense(const char * newTypeOfExpense);

    int getId();

    int getSum();

    int getApartmentNumber();

    char * getTypeOfExpense();

    bool operator==(const Cheltuiala &rhs) const;

    bool operator!=(const Cheltuiala &rhs) const;
};
#endif //LAB7_8_ENTITY_H
