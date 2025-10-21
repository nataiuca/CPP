#include "PhoneBook.hpp"
#include <iomanip> 

PhoneBook::PhoneBook() : index(0), totalContacts(0) {}

void PhoneBook::addContact() {
    if (index == 8)
        index = 0;
    contacts[index].setContact();
    index++;
    if (totalContacts < 8)
        totalContacts++;
}

void PhoneBook::searchContact() const {
    if (totalContacts == 0) {
        std::cout << "No contacts saved yet." << std::endl;
        return;
    }

    std::cout << "|" << std::setw(10) << "INDEX"
              << "|" << std::setw(10) << "FIRST NAME"
              << "|" << std::setw(10) << "LAST NAME"
              << "|" << std::setw(10) << "NICKNAME" << "|" << std::endl;

    for (int i = 0; i < totalContacts; i++)
        contacts[i].displayShort(i);

    std::cout << "Enter index to view details: ";
    std::string input;
    std::getline(std::cin, input);

    if (input.length() != 1 || input[0] < '0' || input[0] > '7') {
        std::cout << "Invalid index." << std::endl;
        return;
    }

    int idx = input[0] - '0';
    if (idx >= totalContacts) {
        std::cout << "No contact at that index." << std::endl;
        return;
    }

    contacts[idx].displayFull();
}
