/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:44:51 by escura            #+#    #+#             */
/*   Updated: 2024/10/11 17:08:03 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", "home", 145, 137)
{
    std::cout
        << BG_GREEN600 "[ CONSTRUCTOR ]" RESET
        << LIME400 " ShrubberyCreationForm" RESET " "
        << "Default Constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", target, 145, 137)
{
    std::cout
        << BG_GREEN600 "[ CONSTRUCTOR ]" RESET
        << LIME400 " ShrubberyCreationForm" RESET " "
        << "Parameter Constructor called with type: "
        << PINK300 << target 
        << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(src)
{
    std::cout
        << BG_GREEN600 "[ CONSTRUCTOR ]" RESET
        << LIME400 " ShrubberyCreationForm" RESET " "
        << "Copy Constructor called" << std::endl;

    this->operator=(src);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout
        << BG_RED600 "[ DESTRUCTOR  ]" RESET
        << RED400 " ShrubberyCreationForm" RESET " "
        << "Destructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
    if (this == &src)
        return *this;

    std::cout
        << BG_GREEN500 "[  OPERATOR   ]" RESET
        << LIME400 " Bureaucrat" RESET " "
        << "Copy Assignment operator called" << std::endl;

    return *this;
}


void ShrubberyCreationForm::executeImpl(Bureaucrat const &executor) const
{
    (void)executor;

    std::string fileName = executor.getName() + "_shrubbery.txt";
    std::ofstream outfile(fileName.c_str());
    if (!outfile.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }

    outfile << "\n"
        "                                                                                          \n"
        "                                 ,*/.   .**/((,(/((#                            \n"
        "                            *(//*(#*////*((*/((#(#(#%/(/,                       \n"
        "                     ,((*/*/#/*/(##%#&##(#(((###(((##%%/#*                      \n"
        "                    /((#(/#%%%%#%%#(////##/#%#((%(###%%##%#(                    \n"
        "                  //((##%%((%%##%%%#%%%/##(% %*%%%%##%##(#(.                    \n"
        "                 ,(////#(#%##%#%%##%#%%###%#%#%&%%%#%&%%%#                      \n"
        "                **/(//(%##(%%%(%((%##(%*#(%%#&%%%&#%%%%%%%/.                    \n"
        "                 /(##%%&#%&/#%(%%(##%#%(((#((%(&%#&&%%&%%%%(#(*                 \n"
        "                *#(#%%#%#%##(&&%##*%%/((//#((#%%(%#/(#%%(###&(#*                \n"
        "              /((/(%#%%#%%#%%/(* &(/(##%%#(%###%#%##(#(###&&#%%(,               \n"
        "               (#%%%#%#*/%%(#(%#%%/#%%&&%%&##*%(%&%&%#%/%##(#%###((             \n"
        "            ,*///(#%#&%((%#&##(*#%(((((/##%/%##%#((#%#%#%(#(%%%#(%#,            \n"
        "          ,*%%##(/(//((/%#&&#(#%#((/#&#&%%&#&#&&#%%&&&%%%##%%##%(%%(            \n"
        "         ./(%#(/#((#%%#(%%#/*(&#/((/%%(%%%%&&%#(%&%#(%#&%%##%#* %##((           \n"
        "         *(#*(*(##(%#((#%&#(*((#(##((%#%&%(%##%%&##%%%%%%%%%%%%##(##((          \n"
        "          (%%/(##%&&#&(%%((///(/((%%#(%#(%#%#%&%&%&&&&%%%%%&%&%%&%%#&%          \n"
        "          ,((/#(%%#(#/%#&**/#(%(%&###%####(#(%##&,%###/%##/%#&&%%%%%            \n"
        "            *#(/##(#%//%*/##*(#%#%%%%#%&%%%#%##(%###(###(#%##(%%%##             \n"
        "          *((/(#(#((##%#(((###%%%###&%#%&%/%%#%&%%&&&%&%%%###%#(#               \n"
        "           .((((%%(%(.#%%%#%/(*#/%(%%%(%%&%%##&(%%%%(#%%# *#%%%##               \n"
        "             *####%%(##&#%&%%%%&%%%%%((&&%%%%/%*,,/,,%#%% .( (                  \n"
        "                 ,(%%#%.#%#%%&%#& *%%%%%%&(#%/                                  \n"
        "                      (%/((%%#%%  /    %%% .                                    \n"
        "                         #(           .#%&                                      \n"
        "                                       %#%                                      \n"
        "                                       #%&                                      \n"
        "                                       #(%                                      \n"
        "                                       ##%                                      \n"
        "                                      ,#%%                                      \n"
        "                                      *%%%                                      \n"
        "                                     %&&%%%/  \n"
        "\n";
    outfile.close();
}
