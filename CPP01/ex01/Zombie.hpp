#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie {
private:
    std::string name;

public:
    Zombie();                      // Constructor por defecto
    Zombie(std::string name);      // Constructor con nombre
    ~Zombie();                     // Destructor

    void announce(void);
    void setName(std::string name);
};

Zombie* zombieHorde(int N, std::string name);

#endif
