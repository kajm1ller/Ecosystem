#include <string>

class animal
{

public:
    animal() : health(0), age(0), name(""), attackPower(0), energy(0) {};

    animal(int h, int a, int ap, int e, std::string n) : health(h), age(a), attackPower(ap), energy(e), name(n) {};

    animal(animal &cpy) : health(cpy.health), age(cpy.age), name(cpy.name) {};

    void setHealth(int newHealth) { this->health = newHealth; };

    void setAge(int newAge) { this->age = newAge; };

    int attack(animal &target);

private:
    int health;
    int age;
    int attackPower;
    int energy;
    std::string name;
};