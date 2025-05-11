#pragma once

#include <iostream>
#include <vector>

#ifndef MAP_H
#define MAP_H

const char GROUND = '.';

class animal;

class map
{
public:
    map(int r, int c)
    {
        rows = r;
        columns = c;
        grid.resize(r * c);
        for (size_t i = 0; i < grid.size(); ++i) // Use size_t for vector indices
        {
            grid.at(i) = GROUND;
        }
    };

    void printMap()
    {
        int i = 0;
        for (int j = 0; j < rows; ++j)
        {
            for (int z = 0; z < columns; ++z)
            {

                if (i < grid.size())
                {
                    std::cout << grid.at(i) << " ";
                }
                ++i;
            }
            std::cout << std::endl;
        }
    };

    void insert(animal &bastard, int location);

    int rows;
    int columns;
    std::vector<char> grid;

private:
};

#endif // MAP_H