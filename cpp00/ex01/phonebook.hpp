/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:52:00 by escura            #+#    #+#             */
/*   Updated: 2024/07/06 16:59:01 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <string.h>
#include <stdlib.h>

#define RST  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

#define FRED(x) KRED x RST
#define FGRN(x) KGRN x RST
#define FYEL(x) KYEL x RST
#define FBLU(x) KBLU x RST
#define FMAG(x) KMAG x RST
#define FCYN(x) KCYN x RST
#define FWHT(x) KWHT x RST

#define BOLD(x) "\x1B[1m" x RST
#define UNDL(x) "\x1B[4m" x RST

#define MAX_CONTACTS 8
#define SEP std::string(47, '=')

class Contact {
    private:
        std::string truncate(const std::string& s) const {
            return s.length() > 10 ? s.substr(0, 9) + "." : s;
        }

    public:
        std::string firstName, lastName, nickName, phoneNumber, darkestSecret;

        Contact () {} //default constructor

        void setFirstName(const std::string &str){
            firstName = str;
        }

        void setLastName(const std::string &str){
            lastName = str;
        }

        void setNickName(const std::string &str){
            nickName = str;
        }

        void setPhoneNumber(const std::string &str){
            phoneNumber = str;
        }

        void setDarkestSecret(const std::string str){
            darkestSecret = str;
        }

        void show() const {
            std::cout << "\n" << SEP << "\n";
            if (!firstName.empty()) {
                std::cout 
                    << "🖋️  First Name      : " << firstName << "\n"
                    << "🖊️  Last Name       : " << lastName << "\n"
                    << "🤓 Nickname        : " << nickName << "\n"
                    << "📱 Phone Number    : " << phoneNumber << "\n"
                    << "🤫 Darkest Secret  : " << darkestSecret << "\n";
            } else {
                std::cout << "🧐 User not found\n";
            }
            std::cout << SEP << "\n\n";
        }

        void row(int id) const {
            std::cout << "|" << std::setw(10) << id
                    << "|" << std::setw(10) << truncate(firstName)
                    << "|" << std::setw(10) << truncate(lastName)
                    << "|" << std::setw(10) << truncate(nickName)
                    << "|\n";
        }
    };

class PhoneBook {
    private:
        Contact contacts[MAX_CONTACTS];
        int index;

    public:
        PhoneBook() : index(0) {} // default constructor

        void addContact(const Contact& contact) {
            contacts[index++ % MAX_CONTACTS] = contact;
        }

        int displayAll() {
            std::cout << "\n" << SEP << "\n"
                    << "|" << std::setw(10) << "Index"
                    << "|" << std::setw(10) << "FirstName"
                    << "|" << std::setw(10) << "LastName"
                    << "|" << std::setw(10) << "Nickname"
                    << "|\n" << SEP << "\n";

            for (int i = 0; i < index && i < MAX_CONTACTS; ++i) {
                contacts[i].row(i + 1);
            }
            if(index == 0){
                std::cout.width(37);
                std::cout << "📚 Phonebook is empty\n";
            }
            std::cout << SEP << "\n\n";
            return index;
        }

        void displayOne(int id) const {
            contacts[id - 1].show();
        }
};

#endif