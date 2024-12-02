#include "Span.hpp"

int main()
{

    try
    {
        Span sp1 = Span(5);
        sp1.addNumber(6);
        sp1.addNumber(3);
        sp1.addNumber(17);
        sp1.addNumber(9);
        sp1.addNumber(11);
        std::cout << sp1.shortestSpan() << std::endl;
        std::cout << sp1.longestSpan() << std::endl;
        sp1.print_all();
        // sp1.addNumber(10);
        Span sp2 = Span(30000);
        sp2.addNumbers(sp1.begin(), sp1.end());
        sp2.print_all();
        std::cout << sp2.shortestSpan() << std::endl;
        std::cout << sp2.longestSpan() << std::endl;

        std::vector<int> vec;

        for (int i = 0; i <= 12000; i++)
        {
            vec.push_back(i);
        }
        sp2.addNumbers(vec.begin(), vec.end());
        // sp2.print_all();
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
