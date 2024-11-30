#include "MutantStack.hpp"
#include <list>

int main()
{
    {
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << "MutantStack size : " << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::stack<int> s(mstack);
    }
    {
        std::cout << "test2 : " << std::endl;
        std::list<int> mylist;
        mylist.push_back(5);
        mylist.push_back(17);
        std::cout << "list size : " << mylist.size() << std::endl;
        mylist.push_back(3);
        mylist.push_back(5);
        mylist.push_back(737);
        mylist.push_back(0);
        std::list<int>::iterator it = mylist.begin();
        std::list<int>::iterator ite = mylist.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
    }
    return 0;
}