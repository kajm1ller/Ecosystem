// map.cpp
#include "map.h"
#include "animal.h"

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