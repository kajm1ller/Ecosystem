#include <string>

class animal
{

public:
    animal() : health(0), age(0), name("") {};
    animal(animal &cpy) : health(cpy.health), age(cpy.age), name(cpy.name) {};
    void setHealth(int newHealth) { this->health = newHealth; };
    void setAge(int newAge) { this->age = newAge; };

private:
    int health;
    int age;
    std::string name;
};