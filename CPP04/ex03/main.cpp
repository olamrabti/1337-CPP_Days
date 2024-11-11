
#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

void f()
{
    system("leaks interface");
}

int main()
{
    atexit(f);

    {
        std ::cout << "\n       TESTING Clone() :\n"
                   << std::endl;
        AMateria *test = new Ice;
        AMateria *test2;
        test2 = test->clone();
        std::cout << "test->type  : " << test2->getType() << std::endl;
        std::cout << "test2->type : " << test2->getType() << std::endl;
        delete (test);
        delete (test2);
    }
    {
        std ::cout << "\n       SUBJECT'S TEST:\n"
                   << std::endl;
        IMateriaSource *src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());
        ICharacter *me = new Character("me");
        AMateria *tmp;
        tmp = src->createMateria("ice");
        me->equip(tmp);
        tmp = src->createMateria("cure");
        me->equip(tmp);
        ICharacter *bob = new Character("bob");
        me->use(0, *bob);
        me->use(1, *bob);
        delete bob;
        delete me;
        delete src;
    }
    return 0;
}
