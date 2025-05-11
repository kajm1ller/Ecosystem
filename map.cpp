#include "map.h"

void map::insert(animal bastard, int location)
{
    grid.at(location) = bastard.icon;
}