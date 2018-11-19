#include <iostream>

#include "bag6.h"

using namespace main_savitch_10;

int main() {
    Bag<int>* numbers = new Bag<int>();

    numbers->insert(10);
    numbers->insert(30);
    numbers->insert(5);
    numbers->insert(11);
    numbers->insert(100);

    std::cout << "\n";

    main_savitch_10::print(numbers->rootPtr, 1);

    numbers->eraseOne(5);

    std::cout << "------eraseOne(5)--------------------\n";

    main_savitch_10::print(numbers->rootPtr, 1);

    numbers->insert(30);

    std::cout << "------insert(30)--------------------\n";

    main_savitch_10::print(numbers->rootPtr, 1);

    std::cout << "------" << numbers->count(10) << "--------------------\n";

    main_savitch_10::print(numbers->rootPtr, 1);

    delete numbers;

    return 0;
}