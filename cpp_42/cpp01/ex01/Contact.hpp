#ifndef CONTACT_HPP
# define CONTACT_HPP
#include <string>

class Contact {
    private:
        std::string firstName;
        std::string lastName;
        std::string nickName;
        std::string phoneNumber;
        std::string darksetSecret;
        void showTenChars();
        void showFull(std::string target);
        std::string getTenChars(std::string target);

    public:
        Contact();
        Contact(std::string firstName, std::string lastName, std::string nickName, std::string phoneNumer
, std::string darksetSecret);
        ~Contact();
        void add();
        void displayWithTenChars(int index);
        void displayFull();

};

#endif