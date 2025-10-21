#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name(name) {
    std::cout << "🧟 Zombie " << name << " has been created!" << std::endl;
}

Zombie::~Zombie() {
    std::cout << "💀 Zombie " << name << " has been destroyed!" << std::endl;
}

void Zombie::announce(void) {
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
