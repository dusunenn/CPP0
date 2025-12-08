#include "Contact.hpp"


//setters & getters:
//SETTER(ayarlayıcı): fonksiyonları dışarıdan gelen bilgiyi alır ;
//contact nesnesinin içindeki private olan değişkenine kaydeder

//GETTER(okuyucu): get fonk'ları private old için doğrudan erişilemeyen bilgiyi dışarıya döndürür
//NEDENİ --> "search" fonksiyonunda bu bilgilere erişip ekrana yazdırmak için

//this burada kullaanılmayabilirdi  cünkü işret ettigimiz degiskennin adı farklı;
//yani sadecce return name/surname dedigimiz durumda adlar aynı olmadıgı icin 
//hangisinin parametre hangisinin sınıf oldugunu karıstırmayacaktır.

//Özetle, kodda this-> kullanmak, "Bu yerel bir değişken değil,
//sınıfın kendi değişkenidir" diye vurgu yapmak için iyi bir alışkanlıktır.
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

void Contact::setPhoneNumber(std::string tn)
{
    this->phoneNumber = tn;
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