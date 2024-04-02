#include "Base.hpp"
#include <stdlib.h> 
#include <time.h>       
#include <iostream>
#include <string>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void)
{
    int i;
    srand (time(NULL));

    i =  rand() % 3 + 1;
    Base *base = NULL;
    std::cout << yellow << "Le choix sera de i : " << i << std::endl;  
	if (i == 1)
		base = dynamic_cast<Base *>(new A);
	else if (i == 2)
		base = dynamic_cast<Base *>(new B);
	else if (i == 3)
		base = dynamic_cast<Base *>(new C);
    return (base);
}

void    identify(Base *p)
{
    try
    {
        	if (dynamic_cast<A *>(p))
			std::cout << "A" << "\n";
		else if (dynamic_cast<B *>(p))
			std::cout << "B" << "\n";
		else if (dynamic_cast<C *>(p))
			std::cout << "C" << "\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}

void    identify(Base &p)
{
    try
    {
        	if (dynamic_cast<A *>(&p))
			std::cout << "A" << "\n";
		else if (dynamic_cast<B *>(&p))
			std::cout << "B" << "\n";
		else if (dynamic_cast<C *>(&p))
			std::cout << "C" << "\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}

int main()
{
    identify(generate());
    identify(*generate());
}