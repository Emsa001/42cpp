/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:56:35 by escura            #+#    #+#             */
/*   Updated: 2024/08/19 21:31:48 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/AMateria.hpp"
#include "./includes/Types.hpp"
#include "./includes/Character.hpp"
#include "./includes/MateriaSource.hpp"

static void nl(){
    std::cout << std::endl;
}

static void test_title(std::string title){
    std::cout 
        << "\n\n" BG_STONE200 GRAY900"[ " BOLD << title << RESET BG_STONE200 GRAY900" ]" RESET "\n\n" 
        << std::endl;
}

void test_subject(){
    test_title("TEST SUBJECT");

    MateriaSource* src = new MateriaSource();
    nl();

    src->learnMateria(new Ice());
    nl();
    src->learnMateria(new Cure());
    
    nl();

    ICharacter* me = new Character("me");
    AMateria* tmp;
    nl();

    tmp = src->createMateria("ice");
    me->equip(tmp);

    tmp = src->createMateria("cure");
    me->equip(tmp);

    nl();

    ICharacter* bob = new Character("bob");
    nl();

    me->use(0, *bob);
    me->use(1, *bob);

    nl();
    delete bob;
    delete me;
    nl();
    delete src;
}

void test_operators(){
    test_title("TEST OPERATORS");

    MateriaSource* src = new MateriaSource();
    MateriaSource dest;
    nl();

    dest = *src;

    nl();
    delete src;
}


void test_deep_copy_character(){
    test_title("TEST DEEP COPY CHARACTER");

    Character* original = new Character("original");
    Character* copy = new Character("copy");
    nl();
    
    AMateria* ice = new Ice();
    AMateria* cure = new Cure();
    nl();

    original->equip(ice);
    original->equip(cure);
    nl();

    *copy = *original; 
    nl();

    std::cout << "Original:" << std::endl;
    original->use(0, *copy);
    original->use(1, *copy);

    nl();

    std::cout << "Copy:" << std::endl;
    copy->use(0, *original);
    copy->use(1, *original);

    nl();
    delete original;
    delete copy;
}

void test_materia_source_limit(){
    test_title("TEST MATERIA SOURCE LIMIT");

    MateriaSource* src = new MateriaSource();
    nl();

    src->learnMateria(new Ice());nl();
    src->learnMateria(new Cure());nl();
    src->learnMateria(new Ice());nl();
    src->learnMateria(new Cure());nl();

    nl();
    // This should not be learned
    src->learnMateria(new Ice());
    nl();

    nl();
    delete src;
}

void test_create_nonexistent_materia(){
    test_title("TEST CREATE NON-EXISTENT MATERIA");

    MateriaSource* src = new MateriaSource();
    nl();

    src->learnMateria(new Ice());

    AMateria* tmp = src->createMateria("fire");  // fire does not exist
    nl();

    if (!tmp) {
        std::cout << "Correctly returned NULL for non-existent Materia" << std::endl;
    }

    delete src;
}

void test_unequip_materia(){
    test_title("TEST UNEQUIP MATERIA");

    ICharacter* me = new Character("Paulo");
    AMateria* ice = new Ice();
    AMateria* cure = new Cure();
    nl();

    me->equip(ice);
    me->equip(cure);

    nl();
    me->use(0, *me); // Use ice

    me->unequip(0); // Unequip ice
    me->unequip(10); // Unequip not existing
    delete ice;     // Manually delete unequipped Materia to avoid memory leak
    nl();

    std::cout << "After unequipping Ice:" << std::endl;
    me->use(0, *me); // Should not do anything, as slot 0 is now empty
    me->use(1, *me); // Should use Cure

    nl();
    delete me;
}

void test_memory_leaks(){
    test_title("TEST MEMORY LEAKS");

    nl();
    MateriaSource* src = new MateriaSource();
    nl();
    ICharacter* me = new Character("me");
    ICharacter* bob = new Character("bob");
    nl();

    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    nl();

    AMateria* tmp = src->createMateria("ice");
    nl();
    me->equip(tmp);
    nl();

    tmp = src->createMateria("cure");
    nl();
    me->equip(tmp);
    nl();

    me->use(0, *bob);
    me->use(1, *bob);
    nl();

    delete bob;
    delete me;
    delete src;
}

int main()
{
    test_subject();
    test_operators();
    test_deep_copy_character();
    test_materia_source_limit();
    test_create_nonexistent_materia();
    test_unequip_materia();
    test_memory_leaks();
    nl();
    return 0;
}
