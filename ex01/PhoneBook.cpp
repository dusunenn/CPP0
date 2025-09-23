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
    std::cout << "Şu anda rehberde " << contactCount << " kişi var." << std::endl;
    
    if (contactCount >= 3)
    {
        std::cout << "PhoneBook is full!" << std::endl;
        return;
    }

    Contact newContact;
    std::cout << "Yeni kisi ekleniyor.." << std::endl;
    
    std::string name;
    std::cout << "Enter name: ";
    std::getline(std::cin, name);
    newContact.setIsim(name);

    std::string surname;
    std::cout << "Enter surname: ";
    std::getline(std::cin, surname);
    newContact.setSoyisim(surname);

    std::string nickname;
    std::cout << "Enter nickname: ";
    std::getline(std::cin, nickname);
    newContact.setTakmaAd(nickname);

    std::string phoneNumber;
    std::cout << "Enter phone number: ";
    std::getline(std::cin, phoneNumber);
    newContact.setTelefonNumarasi(phoneNumber);
    
    std::string secret;
    std::cout << "Enter darkest secret: ";
    std::getline(std::cin, secret);
    newContact.setGizliBilgi(secret);

    contacts[contactCount] = newContact;
    contactCount++;
    std::cout << "Contact added successfully!" << std::endl;
}

void PhoneBook::displayContactsList()
{
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << std::setw(10) << std::right << "Index|";
    std::cout << std::setw(10) << std::right << "Name|";
    std::cout << std::setw(10) << std::right << "Surname|";
    std::cout << std::setw(10) << std::right << "Nickname|" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;

    for (int i = 0; i < contactCount; i++)
    {
        std::cout << std::setw(10) << std::right << i + 1 << "|";
        std::cout << std::setw(10) << std::right << truncateString(contacts[i].getIsim(), 10) << "|";
        std::cout << std::setw(10) << std::right << truncateString(contacts[i].getSoyisim(), 10) << "|";
        std::cout << std::setw(10) << std::right << truncateString(contacts[i].getTakmaAd(), 10) << std::endl;
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
    std::cout << "Name: " << contacts[arrayIndex].getIsim() << std::endl;
    std::cout << "Surname: " << contacts[arrayIndex].getSoyisim() << std::endl;
    std::cout << "Nickname: " << contacts[arrayIndex].getTakmaAd() << std::endl;
    std::cout << "Phone Number: " << contacts[arrayIndex].getTelefonNumarasi() << std::endl;
    std::cout << "Darkest Secret: " << contacts[arrayIndex].getGizliBilgi() << std::endl;
    std::cout << "-----------------------" << std::endl;
}