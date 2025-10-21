#include "Contact.hpp"
#include <cstdlib> // <<< necesario para exit()

Contact::Contact() {}

void Contact::setContact() {
    std::string input;

    std::cout << "First name: ";
    std::getline(std::cin, input);
    while (input.empty()) {
        if (std::cin.eof()) {
            std::cout << "\nExiting PhoneBook..." << std::endl;
            std::exit(0); // o exit(0);
        }
        std::cout << "❌ Field cannot be empty. Enter first name: ";
        std::getline(std::cin, input);
    }
    firstName = input;

    std::cout << "Last name: ";
    std::getline(std::cin, input);
    while (input.empty()) {
        if (std::cin.eof()) {
            std::cout << "\nExiting PhoneBook..." << std::endl;
            std::exit(0);
        }
        std::cout << "❌ Field cannot be empty. Enter last name: ";
        std::getline(std::cin, input);
    }
    lastName = input;

    std::cout << "Nickname: ";
    std::getline(std::cin, input);
    while (input.empty()) {
        if (std::cin.eof()) {
            std::cout << "\nExiting PhoneBook..." << std::endl;
            std::exit(0);
        }
        std::cout << "❌ Field cannot be empty. Enter nickname: ";
        std::getline(std::cin, input);
    }
    nickname = input;

    std::cout << "Phone number: ";
    std::getline(std::cin, input);
    while (input.empty()) {
        if (std::cin.eof()) {
            std::cout << "\nExiting PhoneBook..." << std::endl;
            std::exit(0);
        }
        std::cout << "❌ Field cannot be empty. Enter phone number: ";
        std::getline(std::cin, input);
    }
    phoneNumber = input;

    std::cout << "Darkest secret: ";
    std::getline(std::cin, input);
    while (input.empty()) {
        if (std::cin.eof()) {
            std::cout << "\nExiting PhoneBook..." << std::endl;
            std::exit(0);
        }
        std::cout << "❌ Field cannot be empty. Enter darkest secret: ";
        std::getline(std::cin, input);
    }
    darkestSecret = input;
}
