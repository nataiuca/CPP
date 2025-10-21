#include "Contact.hpp"
#include <cstdlib>

Contact::Contact() {}

void Contact::setContact() {
    std::string input;

    std::cout << "First name: ";
    std::getline(std::cin, input);
    while (input.empty()) {
        if (std::cin.eof()) {
            std::cout << "\nExiting PhoneBook..." << std::endl;
            exit(0);
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
            exit(0);
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
            exit(0);
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
            exit(0);
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
            exit(0);
        }
        std::cout << "❌ Field cannot be empty. Enter darkest secret: ";
        std::getline(std::cin, input);
    }
    darkestSecret = input;
}

void Contact::displayShort(int index) const {
    std::cout << "|" << std::setw(10) << index << "|";
    if (firstName.length() > 10)
        std::cout << firstName.substr(0, 9) + ".";
    else
        std::cout << std::setw(10) << firstName;
    std::cout << "|";

    if (lastName.length() > 10)
        std::cout << lastName.substr(0, 9) + ".";
    else
        std::cout << std::setw(10) << lastName;
    std::cout << "|";

    if (nickname.length() > 10)
        std::cout << nickname.substr(0, 9) + ".";
    else
        std::cout << std::setw(10) << nickname;

    std::cout << "|" << std::endl;
}

void Contact::displayFull() const {
    std::cout << "First name: " << firstName << std::endl;
    std::cout << "Last name: " << lastName << std::endl;
    std::cout << "Nickname: " << nickname << std::endl;
    std::cout << "Phone number: " << phoneNumber << std::endl;
    std::cout << "Darkest secret: " << darkestSecret << std::endl;
}
