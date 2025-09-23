#include "Contact.hpp"

Contact::Contact()
{
}

void Contact::setIsim(std::string n)
{
    this->isim = n;
}

void Contact::setSoyisim(std::string sn)
{
    this->soyisim = sn;
}

void Contact::setTakmaAd(std::string ta)
{
    this->takma_ad = ta;
}

void Contact::setTelefonNumarasi(std::string tn)
{
    this->telefonNumarasi = tn;
}
void Contact::setGizliBilgi(std::string gb)
{
    this->gizliBilgi = gb;
}
std::string Contact::getIsim() const
{
    return this->isim;
}

std::string Contact::getSoyisim() const
{
    return this->soyisim;
}

std::string Contact::getTakmaAd() const
{
    return this->takma_ad;
}

std::string Contact::getTelefonNumarasi() const
{
    return this->telefonNumarasi;
}

std::string Contact::getGizliBilgi() const
{
    return this->gizliBilgi;
}