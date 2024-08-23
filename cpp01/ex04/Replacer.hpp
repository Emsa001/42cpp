/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 21:06:53 by escura            #+#    #+#             */
/*   Updated: 2024/08/01 21:49:20 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACER_HPP
#define REPLACER_HPP

#include <iostream>
#include <string>
#include <fstream>

#define BLUE "\033[1;34m"
#define AQUA "\033[1;36m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define RED "\033[1;31m"
#define PURPLE "\033[1;35m"
#define RESET "\033[0m"

class Replacer
{
    private:
        std::string filename;
        std::string old_word;
        std::string new_word;

    public:
        Replacer(std::string filename, std::string old_word, std::string new_word);

        void run();
};

#endif
