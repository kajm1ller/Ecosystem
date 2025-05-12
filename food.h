#pragma once

#ifndef FOOD_H
#define FOOD_H

class food
{
public:
    food() : mapLocation(0), icon('F') {};

    int mapLocation;
    char icon;

    void setLocation(int local) { mapLocation = local; };

private:
};

#endif // FOOD_H