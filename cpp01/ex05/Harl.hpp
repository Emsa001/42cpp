/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 21:07:01 by escura            #+#    #+#             */
/*   Updated: 2024/08/02 22:15:20 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <vector>
#include <map>

#define BLUE "\033[1;34m"
#define AQUA "\033[1;36m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define RED "\033[1;31m"
#define PURPLE "\033[1;35m"
#define RESET "\033[0m"

class Harl
{
	private:
			void debug(void);
			void info(void);
			void warning(void);
			void error(void);
			void unknown(std::string level);

			std::string _levels[4];
			void (Harl::*_functions[4])(void);
		public:
			Harl();
			~Harl();

			void complain(std::string level);
};

typedef void (Harl::*HarlFn)(void); 

#endif
