#include "Zombie.hpp"

int main() {
    //Define Zombie names
    const std::string zombieName = "Foo";
    const std::string zombieName2 = "Bob The Zombie";
    const std::string zombieName3 = "Chump The New Zombie";

    //Part 1: Create and announce a zombie
    Zombie  zombie;
    zombie.setZombieName(zombieName);
    std::cout << GREEN << "Part 1: " << DEFAULT << std::endl;
    zombie.announce();

    //Part 2: Create and announce a dynamically allocate zombie
    std::cout << GREEN << "Part 2: " << DEFAULT << std::endl;
    Zombie zombie1;
    Zombie *zombie2 = zombie1.newZombie(zombieName2);
    zombie2->announce();

    //Part 3: Create a random zombie that will announce itself
    Zombie  zombie3;
    zombie3.randomChump(zombieName3);
    
    //Clean up dinamically allocated memory
    if (DEBUG)
        std::cout<< "Before" << std::endl;
    delete zombie2;
    if (DEBUG)
        std::cout<< "After" << std::endl;
    return (0);
}