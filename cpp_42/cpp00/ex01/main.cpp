/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuikim <yuikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:55:08 by yuikim            #+#    #+#             */
/*   Updated: 2023/07/28 17:55:27 by yuikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
// #include <stdlib.h>
#include "PhoneBook.hpp"

int main(void) {
    std::string input;
    PhoneBook phoneBook;
    while (input.compare("EXIT")) {
        std::cout << "Enter the Commands: ";
        std::cin >> input;
        if (input.compare("ADD") == 0) phoneBook.add();
        else if (input.compare("SEARCH") == 0) phoneBook.display();
    }
    // system("leaks phoneBook");
    return 0;
}