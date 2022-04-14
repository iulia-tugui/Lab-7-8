//
// Created by Iulia on 4/12/2022.
//

#ifndef LAB7_8_CHELTUIALASERVICE_H
#define LAB7_8_CHELTUIALASERVICE_H

#include "../Repository/Repository.h"
class CheltuialaService {
private:
    Repository<Cheltuiala> repo;
public:
    CheltuialaService();

    ~CheltuialaService();

    void addExpense(int id, int sum, int apartmentNumber,  std::string typeOfExpense);

    void deleteExpense(int id);

    void updateExpense(int id, int sum, int apartmentNumber, std::string typeOfExpense);

    Cheltuiala getExpense(int id);

    Vector<Cheltuiala> showAll();
};


#endif //LAB7_8_CHELTUIALASERVICE_H
