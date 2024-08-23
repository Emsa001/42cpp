/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:52:02 by escura            #+#    #+#             */
/*   Updated: 2024/07/06 17:11:52 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

std::string getInput(std::string str, int times = 1, std::string err_msg = "")
{
    for (int i = 0; i < times; i++)
    {
        std::string input;
        std::cout << str;
        std::getline(std::cin, input);
        if (std::cin.eof())
        {
            std::cin.clear();
            return "EXIT";
        }
        else if (input.length() > 0)
            return input;
    }
    if(err_msg.length() > 0)
        std::cout << err_msg << std::endl;
    return "";
}

void addContactProcedure(PhoneBook &book) {
    std::cout << "\n=============[ ADD NEW CONTACT ]=============\n";
    std::string fields[] = {
        "🖋️  First Name      : ", 
        "🖊️  Last Name       : ", 
        "🤓 Nickname        : ", 
        "📱 Phone Number    : ", 
        "🤫 Darkest Secret  : "
    };
    std::string errMsgs[] = {
        "❌ Cancelling...\n", 
        "❌ Cancelling...\n", 
        "❌ I need your nickname! 🫠\n", 
        "❌ This is phonebook, you have to add phone number you #$*!& 🤬🤬\n", 
        "❌ No secret ☹️ ain't adding that! 😤😡\n"};

    std::string inputs[5];
    for (int i = 0; i < 5; ++i) {
        inputs[i] = getInput(fields[i], 2, errMsgs[i]);
        if (inputs[i].length() == 0) return;
    }

    Contact newContact;

    newContact.setFirstName(inputs[0]);
    newContact.setLastName(inputs[1]);
    newContact.setNickName(inputs[2]);
    newContact.setPhoneNumber(inputs[3]);
    newContact.setDarkestSecret(inputs[4]);

    book.addContact(newContact);
    std::cout << "=============================================\n" << std::endl;
}

char *string_to_char(std::string str) {
    char *cstr = new char[str.length() + 1];
    strcpy(cstr, str.c_str());
    return cstr;
}

void hello(void){
    std::cout << "\n===================================================\n\n";
	std::cout << "          📚 Welcome to the Phonebook 📚            \n\n";
    std::cout << "   📖  Available commands: ";
    std::cout << BOLD("ADD") << ", "
              << BOLD("SEARCH") << ", "
              << BOLD("EXIT")
              << RST << "  📖    \n";
    std::cout << "\n===================================================\n" << std::endl;
}

void instruction(void){
	std::cout 
        << "\nℹ️  Available commands: "
        << BOLD("ADD") << RST << ", " 
        << BOLD("SEARCH") << RST << " or "
        << BOLD("EXIT") << "\n" << RST << std::endl;
}

int main() {
    PhoneBook book;

    hello();

    while (true) {
        std::string input = getInput("📘 What do you want to do? ‣ ");
        if (input == "ADD") {
            addContactProcedure(book);
        } else if (input == "SEARCH") {
            if (book.displayAll() > 0) {
                try {
                    input = getInput("🔍 Enter ID: ");
                    book.displayOne(atoi(string_to_char(input)));
                } catch (const std::exception &e) {
                    std::cerr << "❌ Invalid input or value out of range\n";
                }
            }
        } else if (input == "EXIT") {
            std::cout << "\n😭 OH NOOO I FORGOT ALL THE DATA\n";
            break;
        }else if(input != ""){
            instruction();
        }
    }

    return 0;
}