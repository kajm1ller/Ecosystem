#pragma once
#include <iostream>
#include <vector>
#include "animal.h"

#ifndef MAP_H
#define MAP_H

class map
{
public:
    map(int r, int c)
    {
        rows = r;
        columns = c;
        grid.resize(r * c);
        for (int i = 0; i < grid.size(); ++i)
        {
            grid.at(i) = 'g';
        }
    };

    void printMap() // for testing purposes.
    {
        int i = 0;
        for (int j = 0; j < rows; ++j)
        {
            for (int z = 0; z < columns; ++z)
            {
                std::cout << grid.at(i) << " ";
                ++i;
            }
            std::cout << std::endl;
        }
    };

    void insert(animal bastard, int location);

    int rows;
    int columns;

private:
    std::vector<char> grid;
};

#endif // MAP_H