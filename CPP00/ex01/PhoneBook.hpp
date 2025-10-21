#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include "Contact.hpp"

class PhoneBook {
private:
    Contact contacts[8];
    int     index;
    int     totalContacts;

public:
    PhoneBook();
    void addContact();
    void searchContact() const;
};

#endif
