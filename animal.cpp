#include "animal.h"
#include "map.h"

animal::animal(const animal &cpy) : health(cpy.health), age(cpy.age), name(cpy.name), icon(cpy.icon), mapLocation(cpy.mapLocation), attackPower(cpy.attackPower), energy(cpy.energy) {}

void animal::move(int direction, map &poop) // hoo wee what a fucked up function
{
    if (this->energy <= 0)
    {
        std::cout << "out of energy! \n";
        return;
    }

    int num_cols = poop.columns;
    int num_rows = poop.rows; // for le boundary checks
    int current_grid_size = poop.grid.size();

    // Store original location in case move is invalid
    int originalMapLocation = mapLocation;

    int newMapLocation = mapLocation;

    // Calculate current row and column
    int currentRow = mapLocation / num_cols;
    int currentCol = mapLocation % num_cols;

    switch (direction)
    {
    case 1: // RIGHT
        newMapLocation = mapLocation + 1;
        if ((currentCol < num_cols - 1) && (newMapLocation < current_grid_size))
        {
            poop.grid.at(newMapLocation) = this->icon;
            poop.grid.at(mapLocation) = '.';
            mapLocation = newMapLocation;
            energy--;
        }
        break;
    case 2: // LEFT
        newMapLocation = mapLocation - 1;
        if ((currentCol > 0) && (newMapLocation >= 0))
        {
            poop.grid.at(newMapLocation) = this->icon;
            poop.grid.at(mapLocation) = '.';
            mapLocation = newMapLocation;
            energy--;
        }
        break;
    case 3: // UP
        newMapLocation = mapLocation - num_cols;
        if ((currentRow > 0) && (newMapLocation >= 0))
        {
            poop.grid.at(newMapLocation) = this->icon;
            poop.grid.at(mapLocation) = '.';
            mapLocation = newMapLocation;
            energy--;
        }
        break;
    case 4: // DOWN
        newMapLocation = mapLocation + num_cols;
        if ((currentRow < num_rows - 1) && (newMapLocation < current_grid_size))
        {
            poop.grid.at(newMapLocation) = this->icon;
            poop.grid.at(mapLocation) = '.';
            mapLocation = newMapLocation;
            energy--;
        }
        break;
    case 5: // NORTHWEST
        newMapLocation = mapLocation - num_cols - 1;
        if ((currentRow > 0) && (currentCol > 0) && (newMapLocation >= 0))
        {
            poop.grid.at(newMapLocation) = this->icon;
            poop.grid.at(mapLocation) = '.';
            mapLocation = newMapLocation;
            energy--;
        }
        break;
    case 6: // NORTHEAST
        newMapLocation = mapLocation - num_cols + 1;
        if ((currentRow > 0) && (currentCol < num_cols - 1) && (newMapLocation >= 0) && (newMapLocation < current_grid_size)) // Added check for newMapLocation < current_grid_size
        {
            poop.grid.at(newMapLocation) = this->icon;
            poop.grid.at(mapLocation) = '.';
            mapLocation = newMapLocation;
            energy--;
        }
        break;
    case 7: // SOUTHWEST
        newMapLocation = mapLocation + num_cols - 1;
        if ((currentRow < num_rows - 1) && (currentCol > 0) && (newMapLocation < current_grid_size) && (newMapLocation >= 0)) // Added check for newMapLocation >=0
        {
            poop.grid.at(newMapLocation) = this->icon;
            poop.grid.at(mapLocation) = '.';
            mapLocation = newMapLocation;
            energy--;
        }
        break;
    case 8: // SOUTHEAST
        newMapLocation = mapLocation + num_cols + 1;
        if ((currentRow < num_rows - 1) && (currentCol < num_cols - 1) && (newMapLocation < current_grid_size))
        {
            poop.grid.at(newMapLocation) = this->icon;
            poop.grid.at(mapLocation) = '.';
            mapLocation = newMapLocation;
            energy--;
        }
        break;
    default:
        std::cout << "Invalid direction!" << std::endl;
        break;
    }
}

void animal::print()
{
    std::cout << "Name: " << name << "\n";
    std::cout << "Health: " << health << "\n";
    std::cout << "Attack Power: " << attackPower << "\n";
    std::cout << "Energy: " << energy << "\n";
    std::cout << std::endl;
}