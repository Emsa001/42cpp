/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:31:35 by escura            #+#    #+#             */
/*   Updated: 2024/10/16 16:13:45 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Colors.hpp"
#include <iostream>
#include <string>
#include <stdint.h>

typedef struct Data{
    std::string s1;
    std::string s2;
    int n;
} Data;

class Serializer{
    private:
        Serializer();
        Serializer(const Serializer &src);
    public:
        ~Serializer();
        Serializer &operator=(const Serializer &src);
        

        static uintptr_t serialize(Data *ptr);
        static Data* deserialize(uintptr_t raw);

}; 

#endif