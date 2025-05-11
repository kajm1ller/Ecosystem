#include "animal.h"
#include "map.h"

animal::animal(const animal &cpy) : health(cpy.health), age(cpy.age), name(cpy.name), icon(cpy.icon), mapLocation(cpy.mapLocation), attackPower(cpy.attackPower), energy(cpy.energy) {}

void animal::move(int direction, map &poop)
{
    int num_cols = poop.columns;
    int num_rows = poop.rows; // for le boundary checks
    int current_grid_size = poop.grid.size();

    // Store original location in case move is invalid
    int originalMapLocation = mapLocation;

    int newMapLocation = mapLocation;

    switch (direction)
    {
    case 1: // RIGHT
        newMapLocation = mapLocation + 1;
        if ((mapLocation % num_cols < num_cols - 1) && (newMapLocation < current_grid_size))
        {
            poop.grid.at(newMapLocation) = this->icon;
            poop.grid.at(mapLocation) = '.';
            mapLocation = newMapLocation;
        }
        break;
    case 2: // LEFT
        newMapLocation = mapLocation - 1;
        if ((mapLocation % num_cols > 0) && (newMapLocation >= 0))
        {
            poop.grid.at(newMapLocation) = this->icon;
            poop.grid.at(mapLocation) = '.';
            mapLocation = newMapLocation;
        }
        break;
    case 3: // UP
        newMapLocation = mapLocation - num_cols;
        if ((mapLocation / num_cols > 0) && (newMapLocation >= 0))
        {
            poop.grid.at(newMapLocation) = this->icon;
            poop.grid.at(mapLocation) = '.';
            mapLocation = newMapLocation;
        }
        break;
    case 4: // DOWN
        newMapLocation = mapLocation + num_cols;
        if ((mapLocation / num_cols < num_rows - 1) && (newMapLocation < current_grid_size))
        {
            poop.grid.at(newMapLocation) = this->icon;
            poop.grid.at(mapLocation) = '.';
            mapLocation = newMapLocation;
        }
        break;
    default:
        std::cout << "Invalid direction!" << std::endl;
        break;
    }
}