#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
private:
    Contact contacts[3];
    int contactCount;
    int index;

public:
    PhoneBook();
    void addContact();
    void searchContact();
    void ContactList();
    void displayContactsList();
    std::string truncateString(const std::string& str, size_t width) const;
};

#endif
