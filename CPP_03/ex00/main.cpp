#include "ClapTrap.hpp"

int main() {
    ClapTrap bot("Clapbot 3000");
    ClapTrap bot2("Clapzilla");

    bot.attack("Clapzilla");
    bot2.takeDamage(2);
    return 0;
}