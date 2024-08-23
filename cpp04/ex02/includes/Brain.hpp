/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 17:47:20 by escura            #+#    #+#             */
/*   Updated: 2024/08/18 22:31:20 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/Colors.hpp"

#define MAX_IDEAS 100

class Brain {
    protected:
        std::string _ideas[MAX_IDEAS];

    public:
        Brain();
        Brain(const Brain &src);
        ~Brain();

        Brain &operator=(const Brain &src);

        // functions
        void showIdeas() const;
        void putIdea(std::string idea);
};
