//
// Created by Iulia on 4/12/2022.
//

#include "CheltuialaService.h"

CheltuialaService::CheltuialaService() {

}

CheltuialaService::~CheltuialaService() = default;

void CheltuialaService::addExpense(int id, int sum, int apartmentNumber, string typeOfExpense) {
    Cheltuiala e = Cheltuiala(id, sum, apartmentNumber, typeOfExpense.c_str());
    this->repo.addEntity(e);

}

void CheltuialaService::deleteExpense(int id) {
    Vector<Cheltuiala> expenses = repo.getAll();
    for (int i = 0; i < expenses.size(); i++)
        if (expenses[i].getId() == id) {
            repo.deleteEntity(expenses[i]);
    }

}

void CheltuialaService::updateExpense(int id, int newSum, int newApartmentNumber, string newTypeOfExpense) {
    Vector<Cheltuiala> expenses = repo.getAll();
    Cheltuiala c = Cheltuiala(id, newSum, newApartmentNumber, newTypeOfExpense.c_str());
    for(int i=0; i<expenses.size(); i++){
        if(expenses[i].getId()==id){
            repo.updateEntity(i,c);
        }
    }

}

Vector<Cheltuiala> CheltuialaService::showAll() {
    return repo.getAll();
}

Cheltuiala CheltuialaService::getExpense(int id) {
    Vector<Cheltuiala> expenses = repo.getAll();
    for(int i=0; i<expenses.size(); i++){
        if(expenses[i].getId()==id){
            return expenses[i];
        }
    }
}

