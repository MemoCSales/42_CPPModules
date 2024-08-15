#include "Zombie.hpp"

int main() {
    Zombie  zombie4;
    int     n = 10;
    Zombie  *zombie5 = zombie4.zombieHorde(n, "Bob");
    std::cout << GREEN << "Number of Zombies in the Horde: " << n << DEFAULT << std::endl;
    for (int i = 0; i < n; i++) {
        zombie5[i].announce();
    }
    
    //Clean up dinamically allocated memory
    if (DEBUG)
        std::cout<< "Before" << std::endl;
    delete[] zombie5;
    if (DEBUG)
        std::cout<< "After" << std::endl;
    return (0);
}
