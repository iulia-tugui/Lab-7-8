#include <iostream>
#include "UI/Console.h"
#include "Tests/Tests.h"

int main() {
    Test test;
    test.testAll();
    Console console;
    console.runMenu();
    return 0;
}
