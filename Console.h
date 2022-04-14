//
// Created by Iulia on 4/7/2022.
//

#ifndef LAB7_8_CONSOLE_H
#define LAB7_8_CONSOLE_H

#include "../Service/CheltuialaService.h"
class Console {
private:
    CheltuialaService service;
public:
    void runMenu();
    void addExpense();
    void deleteExpense();
    void modifyExpense();
    void showAll();
};

#endif //LAB7_8_CONSOLE_H
