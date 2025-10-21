#include "Zombie.hpp"

int main() {
    int N = 5;
    Zombie* horde = zombieHorde(N, "Brainy");

    if (!horde) {
        std::cout << "Error: invalid horde size." << std::endl;
        return 1;
    }

    for (int i = 0; i < N; i++)
        horde[i].announce();

    delete[] horde; // destrucción de todos los zombies

    return 0;
}
