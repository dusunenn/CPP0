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
    std::cout << "There are currently " << contactCount << "  people in the directory." << std::endl;
    
    if (contactCount >= 3)
    {
        std::cout << "PhoneBook is full!" << std::endl;
        return;
    }

    Contact newContact;
    std::cout << "Adding new person..\n" << std::endl;
    
    std::string name;
    std::cout << "Enter name: ";
    if(!std::getline(std::cin, name))
    {
        std::cout << std::endl;
        return;
    }
    newContact.setName(name);

    std::string surname;
    std::cout << "Enter surname: ";
    if(!std::getline(std::cin, surname))
    {
        std::cout << std::endl;
        return;
    }
    newContact.setSurname(surname);

    std::string nickname;
    std::cout << "Enter nickname: ";
    if(!std::getline(std::cin, nickname))
    {
        std::cout << std::endl;
        return;
    }
    newContact.setNickname(nickname);

    std::string phoneNumber;
    std::cout << "Enter phone number: ";
    if(!std::getline(std::cin, phoneNumber))
    {
        std::cout << std::endl;
        return;
    }
    newContact.setPhoneNumber(phoneNumber);
    
    std::string secret;
    std::cout << "Enter darkest secret: ";
    if(!std::getline(std::cin, secret))
    {
        std::cout << std::endl;
        return;
    }
    newContact.setDarkestSecret(secret);

    contacts[contactCount] = newContact;
    contactCount++;
    std::cout << "Contact added successfully!" << std::endl;
}

void PhoneBook::displayContactsList()
{
    std::cout << "\033[2J\033[1;1H";
    std::cout.flush(); 
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << std::setw(10) << std::right << "Index|";
    std::cout << std::setw(10) << std::right << "Name|";
    std::cout << std::setw(10) << std::right << "Surname|";
    std::cout << std::setw(10) << std::right << "Nickname|" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;

    for (int i = 0; i < contactCount; i++)
    {
        std::cout << std::setw(10) << std::right << i + 1 << "|";
        std::cout << std::setw(10) << std::right << truncateString(contacts[i].getName(), 10) << "|";
        std::cout << std::setw(10) << std::right << truncateString(contacts[i].getSurname(), 10) << "|";
        std::cout << std::setw(10) << std::right << truncateString(contacts[i].getNickname(), 10) << std::endl;
    }
    
}

void PhoneBook::searchContact()
{
    if (contactCount == 0)
    {
        std::cout << "No contacts in the phonebook" << std::endl;
        return;
    }
    
    displayContactsList();
    std::cout << "\nSelect an index to view details: ";
    
    std::string input;
    std::getline(std::cin, input);

    int selectedIndex = -1;
    bool isValidNumber = true;

    if (input.empty())
    {
        std::cout << "Invalid input: empty string" << std::endl;
        return;
    }
    
    for (size_t i = 0; i < input.length(); i++)
    {
        if (input[i] < '0' || input[i] > '9')
        {
            isValidNumber = false;
            break;
        }
    }
    
    if (!isValidNumber)
    {
        std::cout << "Invalid input: not a number" << std::endl;
        return;
    }

    selectedIndex = 0;
    for (size_t i = 0; i < input.length(); i++)
    {
        selectedIndex = selectedIndex * 10 + (input[i] - '0');
    }

    if (selectedIndex < 1 || selectedIndex > contactCount)
    {
        std::cout << "Invalid index: out of range (1-" << contactCount << ")" << std::endl;
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
