#include <iostream>
#include <string>

int main() {
    std::string brain = "HI THIS IS BRAIN";
    std::string* stringPTR = &brain;   // puntero a la variable
    std::string& stringREF = brain;    // referencia a la variable

    std::cout << "Memory addresses:" << std::endl;
    std::cout << "  brain:     " << &brain << std::endl;
    std::cout << "  stringPTR: " << stringPTR << std::endl;
    std::cout << "  stringREF: " << &stringREF << std::endl;

    std::cout << std::endl << "Values:" << std::endl;
    std::cout << "  brain:     " << brain << std::endl;
    std::cout << "  *stringPTR: " << *stringPTR << std::endl;
    std::cout << "  stringREF: " << stringREF << std::endl;

    return 0;
}
