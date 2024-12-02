#include "MutantStack.hpp"
#include <list>

int main()
{
    {
        std::cout << "---------------------- test1 --------------------" << std::endl;
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << mstack.top() << std::endl;
        mstack.pop();
        std::cout << "MutantStack mstack size : " << mstack.size() << std::endl;
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

        std::cout << "---------------------- test2 --------------------" << std::endl;
        std::cout << "Iterate over a Const MutantStack (copy of mstack) : " << std::endl;
        MutantStack<int> test(mstack);
        test.pop();
        const MutantStack<int> numbers(mstack);
        MutantStack<int>::const_iterator c_it = numbers.begin();

        while (c_it != numbers.end())
        {
            std::cout << *c_it << std::endl;
            ++c_it;
        }
        std::cout << std::endl;
    }
    {
        std::cout << "---------------------- test3 --------------------" << std::endl;
        std::list<int> mylist;
        mylist.push_back(5);
        mylist.push_back(17);
        std::cout << mylist.back() << std::endl;
        mylist.pop_back();
        std::cout << "(Compare against a list) size : " << mylist.size() << std::endl;
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