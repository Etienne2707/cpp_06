#include "ScalarConverter.hpp"



int main(int ac, char **argv)
{
    if (ac != 2)
    {
        std::cout << "Argument Error" << std::endl;
            return (-1);
    }
            
   try
    {       
         ScalarConverter::Convert(argv[1]);
    }
   catch(const ScalarConverter::InputError & e)
   {
        std::cerr << e.what() << '\n';
   }
 
   
}