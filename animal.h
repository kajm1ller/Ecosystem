
#pragma once

#include <string>
#include <random>

#ifndef ANIMAL_H
#define ANIMAL_H

class map;

class animal
{
public:
    animal(std::string n) : health(0), age(0), name(n), attackPower(0), energy(100), icon('a'), mapLocation(0) {};
    animal() : health(0), age(0), name(""), attackPower(0), energy(100), icon('a'), mapLocation(0) {};
    animal(int h, int a, int ap, int e, char i) : health(h), age(a), attackPower(ap), energy(e), name(), icon(i), mapLocation(0) {};

    animal(const animal &cpy);

    void setHealth(int newHealth) { health = newHealth; };
    void setAge(int newAge) { age = newAge; };
    void setIcon(char i) { icon = i; };
    void setLocation(int local) { mapLocation = local; };

    void move(int direction, map &poop);

    void print();

    int mapLocation;
    char icon;

private:
    int health;
    int age;
    int attackPower;
    int energy;
    std::string name;
};

#endif // ANIMAL_H