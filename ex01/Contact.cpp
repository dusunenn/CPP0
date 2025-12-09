#include "Contact.hpp"

Contact::Contact()
{
}

void Contact::setName(std::string n)
{
    this->name = n;
}

void Contact::setSurname(std::string sn)
{
    this->surname = sn;
}

void Contact::setNickname(std::string ta)
{
    this->nickname = ta;
}

void Contact::setPhoneNumber(std::string phoneNumber)
{
    this->phoneNumber = phoneNumber;
}
void Contact::setDarkestSecret(std::string gb)
{
    this->darkestSecret = gb;
}
std::string Contact::getName() const
{
    return this->name;
}

std::string Contact::getSurname() const
{
    return this->surname;
}

std::string Contact::getNickname() const
{
    return this->nickname;
}

std::string Contact::getPhoneNumber() const
{
    return this->phoneNumber;
}

std::string Contact::getDarkestSecret() const
{
    return this->darkestSecret;
}