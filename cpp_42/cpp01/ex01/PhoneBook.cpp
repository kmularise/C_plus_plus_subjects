#include "PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook() {
    for(int i = 0; i < 8; i++) contacts[i] = Contact();
    this->targetId = 0;
}

void PhoneBook::add() {
    this->contacts[this->targetId %8].add();
    this->targetId++;
}

void PhoneBook::showColumns() {
    std::cout << "     index" << "|" << "first name" << "|" << " last name" << "|" << "  nickname" << "|" << '\n';
}

void PhoneBook::display() {
    int index;
    int size = std::min(8, this->targetId);
    this->showColumns();
    for (int i = 0; i < size; i++) this->contacts[i].displayWithTenChars(i + 1);
    std::cout << "Enter the index you want!";
    std::cin >> index;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cout << "Not number!" << '\n';
        return ;
    }
    index -= 1;
    if (0 <= index && index < 8 && index < this->targetId) {
        contacts[index].displayFull();
    } else {
        std::cout << "Out of range" << '\n';
    }
}

