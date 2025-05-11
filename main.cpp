#include <iostream>
#include "animal.h"
#include "map.h"
#include <Windows.h>
#include <cstdlib>
#include <random>

int main()
{
    animal todd;
    map test(40, 100);
    test.insert(todd, 12);
    test.printMap();
    int direction = 0;
    while (true)
    {

        std::cout << "Enter a direction: 1, 2, 3, 4 " << std::endl;
        std::cin >> direction;
        todd.move(direction, test);
        system("CLS");
        test.printMap();
    }

    return 0;
}