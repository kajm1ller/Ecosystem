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

        todd.move(rand() % 5, test);
        test.printMap();
        Sleep(1000);
        system("CLS");
    }

    return 0;
}