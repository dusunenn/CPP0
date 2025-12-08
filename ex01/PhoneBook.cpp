#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook()
{
    contactCount = 0;
    index = 0;
}

std::string PhoneBook::truncateString(const std::string& str, size_t width) const
{
    if (str.length() > width)
        return str.substr(0, width - 1) + ".";
    return str;
}

void PhoneBook::addContact()
{
    std::cout << "\033[2J\033[1;1H";
    std::cout.flush(); 
    std::cout << "There are currently " << (contactCount < 8 ? contactCount : 8) << " people in the directory." << std::endl;

    /*
    if (contactCount < 8) 
    {
        std::cout << contactCount;
    }
     else 
    {
        std::cout << 8;
    }
    */

    //cin >>: Tek kelime okur. (Boşluk görünce kaçar).
    //getline: Cümle okur. (Sadece Enter'a basınca durur).
    
    Contact newContact;
    std::cout << "Adding new person..\n" << std::endl;
    
    std::string name;
    std::cout << "Enter name: ";
    std::getline(std::cin, name);
    if (name.empty()) {
        std::cout << "Field cannot be empty!" << std::endl;
        return;
    }
    newContact.setName(name);

    std::string surname;
    std::cout << "Enter surname: ";
    std::getline(std::cin, surname);
    if (surname.empty()) {
        std::cout << "Field cannot be empty!" << std::endl;
        return;
    }
    newContact.setSurname(surname);

    std::string nickname;
    std::cout << "Enter nickname: ";
    std::getline(std::cin, nickname);
    if (nickname.empty()) {
        std::cout << "Field cannot be empty!" << std::endl;
        return;
    }
    newContact.setNickname(nickname);

    std::string phoneNumber;
    std::cout << "Enter phone number: ";
    std::getline(std::cin, phoneNumber);
    if (phoneNumber.empty()) {
        std::cout << "Field cannot be empty!" << std::endl;
        return;
    }
    newContact.setPhoneNumber(phoneNumber);
    
    std::string secret;
    std::cout << "Enter darkest secret: ";
    std::getline(std::cin, secret);
    if (secret.empty()) {
        std::cout << "Field cannot be empty!" << std::endl;
        return;
    }
    newContact.setDarkestSecret(secret);

    if (contactCount < 8) {
        contacts[contactCount] = newContact;
        contactCount++;
    } else {
        contacts[index] = newContact;
        index = (index + 1) % 8;
    }
    std::cout << "Contact added!" << std::endl;
}

void PhoneBook::displayContactsList()
{
    std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
    std::cout << "|----------|----------|----------|----------|" << std::endl;
    int totalContacts = (contactCount < 8) ? contactCount : 8;
    for (int i = 0; i < totalContacts; i++)
    {
        std::cout << "|" << std::setw(10) << std::right << i + 1;
        std::cout << "|" << std::setw(10) << std::right << truncateString(contacts[i].getName(), 10);
        std::cout << "|" << std::setw(10) << std::right << truncateString(contacts[i].getSurname(), 10);
        std::cout << "|" << std::setw(10) << std::right << truncateString(contacts[i].getNickname(), 10) << "|" << std::endl;
    }
    
}

void PhoneBook::searchContact()
{
    int totalContacts = (contactCount < 8) ? contactCount : 8;
    if (totalContacts == 0)
    {
        std::cout << "No contacts in the phonebook" << std::endl;
        return;
    }
    
    displayContactsList();
    std::cout << "\nSelect an index to view details: ";
    
    std::string input;
    std::getline(std::cin, input);

    if (input.length() != 1 || input[0] < '1' || input[0] > '8')
    {
        std::cout << "Invalid index! Enter 1-8." << std::endl;
        return;
    }
    
    int selectedIndex = input[0] - '0';

    if (selectedIndex > totalContacts)
    {
        std::cout << "Invalid index! Available contacts: 1-" << totalContacts << std::endl;
        return;
    }
    int arrayIndex = selectedIndex - 1;

    std::cout << "\n--- Contact Details ---" << std::endl;
    std::cout << "Name: " << contacts[arrayIndex].getName() << std::endl;
    std::cout << "Surname: " << contacts[arrayIndex].getSurname() << std::endl;
    std::cout << "Nickname: " << contacts[arrayIndex].getNickname() << std::endl;
    std::cout << "Phone Number: " << contacts[arrayIndex].getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << contacts[arrayIndex].getDarkestSecret() << std::endl;
    std::cout << "-----------------------" << std::endl;
}
