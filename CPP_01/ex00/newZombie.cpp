#include "Zombie.hpp"

Zombie* Zombie::newZombie(std::string _name) {
    Zombie* newZombie = new Zombie(_name);
    // newZombie->setZombieName(name);
    return (newZombie);
}
