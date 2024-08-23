/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 13:46:34 by escura            #+#    #+#             */
/*   Updated: 2024/08/19 16:20:59 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIALSOURCE_HPP
#define MATERIALSOURCE_HPP

#include "./AMateria.hpp"
# define SOURCES_SIZE 4

class IMateriaSource
{
    public:
        virtual ~IMateriaSource() {}
        virtual void learnMateria(AMateria*) = 0;
        virtual AMateria* createMateria(std::string const & type) = 0;
};

class MateriaSource : public IMateriaSource
{
    protected:
        AMateria *_sources[SOURCES_SIZE];

    public:
        MateriaSource();
        MateriaSource(const MateriaSource &src);
        ~MateriaSource();

        MateriaSource &operator=(MateriaSource const &src);

        void learnMateria(AMateria *src);
        AMateria* createMateria(std::string const &type);
};

#endif 