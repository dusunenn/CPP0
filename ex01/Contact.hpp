#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <string>


class Contact
{
private:
    std::string name;
    std::string surname;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;

public:
    Contact();
    void setName(std::string n);
    void setSurname(std::string sn);
    void setNickname(std::string ta);
    void setPhoneNumber(std::string phoneNumber);
    void setDarkestSecret(std::string gb);

    std::string getName() const;
    std::string getSurname() const;
    std::string getNickname() const;
    std::string getPhoneNumber() const;
    std::string getDarkestSecret() const;
};

#endif
