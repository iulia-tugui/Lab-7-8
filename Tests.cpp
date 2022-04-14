//
// Created by Iulia on 4/7/2022.
//
#include "../Tests/Tests.h"
#include "../Domain/Cheltuiala.h"
#include "../Repository/Repository.h"
#include "../Service/CheltuialaService.h"
#include<cassert>
#include <cstring>

void Test::testConstructors() {
    Cheltuiala ch;
    assert(ch.getSum() == 0);
    char *c = new char(5);
    strcpy(c, "apa");
    Cheltuiala ch1(1,1, 5, c);
    assert(ch1.getId() == 1);
    assert(ch1.getSum() == 1);
    Repository<Cheltuiala> repo;
    repo.addEntity(ch);
    assert(repo.getSize() == 1);
    repo.addEntity(ch1);
    assert(repo.getSize() == 2);
}

void Test::testSetters() {
    Cheltuiala ch;
    ch.setSum(2);
    assert(ch.getSum() == 2);
}

void Test::testGetters() {
    char c[5] ="apa";
    Cheltuiala ch(1,120, 12, c);
    assert(ch.getSum() == 120);
    assert(ch.getId() == 1);

    Repository<Cheltuiala> repo;
    Cheltuiala c1(2,1, 10, c);
    Cheltuiala c2(3, 2, 20, c);
    Cheltuiala c3(4, 3, 25, c);

    repo.addEntity(c1);
    repo.addEntity(c2);
    repo.addEntity(c3);

    assert(repo.getSize() == 3);
    assert(repo.getEntity(0).getSum() == 1);
    assert(repo.getEntity(1).getSum() == 2);
    assert(repo.getEntity(2).getSum() == 3);
}

void Test::testRepository() {
    Repository<Cheltuiala> repo;

    assert(repo.getSize() == 0);

    char *c = new char(5);
    strcpy(c, "apa");
    Cheltuiala ch(1, 1, 120, c);
    repo.addEntity(ch);

    char *v = new char(5);
    strcpy(v, "gaz");
    Cheltuiala h(2, 130, 13, v);
    repo.updateEntity(0, h);
    assert(repo.getEntity(0).getSum() == 130);

    repo.addEntity(ch);
    assert(repo.getSize() == 2);
    repo.deleteEntity(ch);
    assert(repo.getSize() == 1);

}

void Test::testService() {
    CheltuialaService serv;
    assert(serv.showAll().size() == 0);

    serv.addExpense(1, 1, 20, "apa");
    serv.addExpense(2, 2, 15, "altele");
    assert(serv.getExpense(2).getSum() == 2);
    assert(serv.getExpense(1).getApartmentNumber() == 20);

    assert(serv.showAll().size() == 2);

    serv.deleteExpense(1);
    assert(serv.showAll().size() == 1);

}

void Test::testAll() {
    testConstructors();
    testGetters();
    testSetters();
    testRepository();
    testService();
}
