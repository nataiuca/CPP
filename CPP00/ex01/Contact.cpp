#include "Contact.hpp"

Contact::Contact() {}

void Contact::setContact() {
    std::cout << "First name: ";
    std::getline(std::cin, firstName);

    std::cout << "Last name: ";
    std::getline(std::cin, lastName);

    std::cout << "Nickname: ";
    std::getline(std::cin, nickname);

    std::cout << "Phone number: ";
    std::getline(std::cin, phoneNumber);

    std::cout << "Darkest secret: ";
    std::getline(std::cin, darkestSecret);
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
