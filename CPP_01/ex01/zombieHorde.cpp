#include "Zombie.hpp"

Zombie* Zombie::zombieHorde(int N, std::string name)
{
    Zombie*  zombieHorde[N];

    for (int i = 0; i < N; i++) {
        zombieHorde[i] = new Zombie(name);
    }
    int i = 0;
    return (zombieHorde[i]);
}
