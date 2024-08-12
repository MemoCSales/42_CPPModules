#include "Zombie.hpp"

int main() {
    Zombie  zombie4;
    Zombie  *zombie5 = zombie4.zombieHorde(3, "Bob");
    for (int i = 0; i < 3; i++) {
        zombie5[i].announce();
    }
    
    //Clean up dinamically allocated memory
    if (DEBUG)
        std::cout<< "Before" << std::endl;
    delete zombie5;
    if (DEBUG)
        std::cout<< "After" << std::endl;
    return (0);
}
