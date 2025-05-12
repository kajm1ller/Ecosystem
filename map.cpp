// map.cpp
#include "map.h"
#include "animal.h"
#include "food.h"

void map::insert(animal &bastard, int location)
{
    if (location >= 0 && location < grid.size())
    {
        grid.at(location) = bastard.icon;
        bastard.setLocation(location);
    }
    else
    {
        std::cerr << "Error: Insert location " << location << " is out of bounds." << std::endl;
    }
}

void map::insert(food tasty, int location)
{
    if (location >= 0 && location < grid.size())
    {
        grid.at(location) = tasty.icon;
        tasty.setLocation(location);
    }
    else
    {
        std::cerr << "Error: Insert location " << location << " is out of bounds." << std::endl;
    }
}