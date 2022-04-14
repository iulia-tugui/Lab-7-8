//
// Created by Iulia on 4/7/2022.
//

#include "Console.h"
#include "../UI/ReadOption.h"
#include "../UI/ShowMenu.h"
#include <iostream>

using namespace std;


void Console::runMenu() {
    char choice;
    bool shouldRun = true;
    while (shouldRun) {
        showMenu();
        choice = option();
        switch (choice) {
            case '1': {
               addExpense();
                break;
            }
            case '2': {
                showAll();
                break;
            }
            case '3': {
                deleteExpense();
                break;
            }
            case '4': {
               modifyExpense();
                break;
            }
            case 'x': {
                shouldRun = false;
                break;
            }
            default: {
                cout << "The option does not exist! Try again: " << '\n';
            }
        }
    }

}

void Console::addExpense() {
    int id, sum,  apartmentNumber;
    std::string typeOfExpense;
    cout << "Give expense id: ";
    cin >> id;
    cout << "Give apartment number: ";
    cin >> apartmentNumber;
    cout << "Give sum: ";
    cin >> sum;
    cout << "Give type of expense: ";
    cin >> typeOfExpense;
    service.addExpense(id, sum, apartmentNumber, typeOfExpense);
}
void Console::modifyExpense() {
    int id, apartmentNumber, sum;
    string typeOfExpense;
    cout<<"Give expense id to modify: ";
    cin>>id;
    cout<<"Give new apartment number : ";
    cin>>apartmentNumber;
    cout<<"Give new sum: ";
    cin>>sum;
    cout<<"Give new type of expense: ";
    cin>>typeOfExpense;
    service.updateExpense(id, sum, apartmentNumber, typeOfExpense);
}

void Console::deleteExpense() {
    int id;
    cout<<"Give expense id to delete: ";
    cin>>id;
    service.deleteExpense(id);
}

void Console::showAll() {
    Vector<Cheltuiala> expenses = service.showAll();
    for(int i=0; i<expenses.size(); i++){
        cout<<expenses[i]<<endl;
    }
}
