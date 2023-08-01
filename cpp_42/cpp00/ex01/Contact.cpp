/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuikim <yuikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:54:53 by yuikim            #+#    #+#             */
/*   Updated: 2023/08/01 15:04:06 by yuikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>

Contact::Contact() {
    this->firstName = "";
    this->lastName = "";
    this->nickName = "";
    this->phoneNumber = "";
    this->darksetSecret = "";
}

Contact::Contact(std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber
, std::string darksetSecret) {
    this->firstName = firstName;
    this->lastName = lastName;
    this->nickName = nickName;
    this->phoneNumber = phoneNumber;
    this->darksetSecret = darksetSecret;
}

Contact::~Contact() {
    ;
}

void Contact::add() {
    std::cout << "Enter the user's first name:" << "\n";
    std::cin >> this->firstName;
    std::cout << "Enter the user's last name:" << "\n";
    std::cin >> this->lastName;
    std::cout << "Enter the user's nickname:" << "\n";
    std::cin >> this->nickName;
    std::cout << "Enter the user's phone number:" << "\n";
    std::cin >> this->phoneNumber;
    std::cout << "Enter the user's darkset secret:" << "\n";
    std::cin >> this->darksetSecret;
    std::cout << "Save Success!" << '\n';
}

std::string Contact::getTenChars(std::string target) {
    int size = target.length();
    if (size <= 10) {
        return std::string(10 - size, ' ') + target;
    }
    return target.substr(0, 9) + ".";
}

void Contact::displayWithTenChars(int index) {
    std::cout << getTenChars(std::to_string(index)) << "|"
    << getTenChars(this->firstName) << "|" << getTenChars(this->lastName) << "|"
    << getTenChars(this->nickName) << "\n";

    
}

void Contact::displayFull() {
    std::cout << "first name : " << this->firstName << "\n";
	std::cout << "last name : " << this->lastName << "\n";
	std::cout << "nickname : " << this->nickName << "\n";
	std::cout << "phone number : " << this->phoneNumber << "\n";
	std::cout << "darkest secret : " << this->darksetSecret << "\n";

}