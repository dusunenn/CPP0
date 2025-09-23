#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
private:
    std::string isim;
    std::string soyisim;
    std::string takma_ad;
    std::string telefonNumarasi;
    std::string gizliBilgi;

public:
    Contact();
    void setIsim(std::string n);
    void setSoyisim(std::string sn);
    void setTakmaAd(std::string ta);
    void setTelefonNumarasi(std::string tn);
    void setGizliBilgi(std::string gb);

    std::string getIsim() const;
    std::string getSoyisim() const;
    std::string getTakmaAd() const;
    std::string getTelefonNumarasi() const;
    std::string getGizliBilgi() const;
};

#endif
