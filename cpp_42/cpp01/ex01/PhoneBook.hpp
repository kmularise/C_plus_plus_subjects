#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"

class PhoneBook
{
    private:
        Contact contacts[8];
        int     targetId;
        void    showColumns();
    
    public:
        PhoneBook();
        void add();
        void display();


};

#endif