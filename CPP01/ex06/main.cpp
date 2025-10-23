#include "Harl.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: ./harlFilter <level>" << std::endl;
        return 1;
    }

    Harl harl;
    std::string level = argv[1];
    int filter = -1;

    // Convertimos el argumento en un índice
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for (int i = 0; i < 4; i++) {
        if (levels[i] == level)
            filter = i;
    }

    // Usamos switch para imprimir desde ese nivel hacia arriba
    switch (filter) {
        case 0:
            harl.complain("DEBUG");
        case 1:
            harl.complain("INFO");
        case 2:
            harl.complain("WARNING");
        case 3:
            harl.complain("ERROR");
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
    return 0;
}
