/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuikim <yuikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:55:02 by yuikim            #+#    #+#             */
/*   Updated: 2023/07/28 17:55:04 by yuikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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