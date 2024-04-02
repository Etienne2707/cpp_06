#include "ScalarConverter.hpp"
#include <string>
#include <stdlib.h>

ScalarConverter::ScalarConverter()
{
    std::cout << yellow << " Default constructor called" << reset << std::endl;
}

ScalarConverter::ScalarConverter(std::string string) : _snum(string)
{
   std::cout << yellow << "Parametric Floatconstructor called" << reset <<  std::endl;
}

ScalarConverter::~ScalarConverter()
{
    std::cout << red <<  "Destructor called" << reset << std::endl;
}

ScalarConverter::ScalarConverter( ScalarConverter const & src ){
    std::cout << " Copy constructeur called" <<  reset << std::endl;
    *this = src;
}


ScalarConverter & ScalarConverter::operator=(ScalarConverter const & rhs)
{
    std::cout << "Assignment operator called" << std::endl;
    if (this != &rhs)
    {
        this->_char = rhs._char;
        this->_double = rhs._double;
        this->_float = rhs._float;
        this->_int = rhs._int;
    }
    return *this;
}


void    printInfinity(std::string inf)
{
    if (inf == "+inff")
        inf = "+inf";
    else if (inf == "-inff")
        inf = "-inf";  
    std::cout << yellow << "Char: Impossible" << std::endl;
    std::cout << "int: Impossible"  << std::endl;
    std::cout << "float: " << inf << "f" << std::endl;
    std::cout << "double: " << inf << reset << std::endl;
}

float    getFloat(std::string s_num)
{
    return  (std::atof(const_cast<char *>(s_num.c_str())));
}

char    getChar(std::string s_num)
{
    return (static_cast<char>(atof(const_cast<char *>(s_num.c_str()))));
}

int    getInt(std::string s_num)
{
   return (static_cast<int>(atof(const_cast<char *>(s_num.c_str()))));
}

double    getDouble(std::string s_num)
{
   return (strtod(const_cast<char *>(s_num.c_str()),NULL));
}

void    printFloat(std::string s)
{
    float f = getFloat(s);
    int n = static_cast<int>(f);

    if (f == n)
    {
        std::cout << "float: " << getFloat(s) << ".0f" << std::endl;
    }
    else
        std::cout << "float: " << getFloat(s) << std::endl;
}

void    printDouble(std::string s)
{
    double f = getDouble(s);
    int n = static_cast<int>(f);

    if (f == n)
    {
        std::cout << "double: " << getDouble(s) << ".0" << std::endl;
    }
    else
        std::cout << "double: " << getDouble(s) << std::endl;
}

void    printConverter(std::string s)
{
    if (getInt(s) >= 32 && getInt(s) <= 126)
        std::cout << yellow << "Char: " << getChar(s) << std::endl;
    else
        std::cout << yellow << "Char: " << "No printable " << std::endl;
    if (getInt(s) < -2147483647 || getInt(s) > 2147483647)
        std::cout << "int: " << "Integer limit exceed " << std::endl;
    else
        std::cout << "int: " << getInt(s) << std::endl;
    if (getFloat(s) < F_MIN || getFloat(s) > F_MAX)
        std::cout << "float: Float limit exceed" << std::endl;
    else
        printFloat(s);
    if (getDouble(s) < D_MIN || getDouble(s) > D_MAX)
        std::cout << "double : Double limit exceed" << std::endl;
    else
        printDouble(s);
}

void ScalarConverter::Convert(std::string s_num)
{
    int point = 0;
        if (s_num == "+inf" || s_num == "-inf" || s_num == "+inff" || s_num == "-inff" || s_num == "nan" )
        {
            printInfinity(s_num);
            return ;
        }
        else if (s_num.size() == 1 && (s_num[0] < 32 || s_num[0] > 126))
            throw InputError();
        else if (s_num.size() != 1)
        {
            for (size_t i = 0; i < s_num.length(); i++)
            {
                if (s_num[i] != '.' && s_num[i] != 'f' && s_num[i] != '-' && s_num[i] != '+' && (s_num[i] < '0' || s_num[i] > '9'))
                {
                    std::cout << "test " << s_num[i] << std::endl;
                    throw ScalarConverter::InputError();
                }
                else if ((s_num[i] == '-' && i != 0) || (s_num[i] == '+' && i != 0))
                    throw ScalarConverter::InputError();
                else if (s_num[i] == 'f' && i != (s_num.length() - 1))
                    throw ScalarConverter::InputError();
                else if (s_num[i] == '.' && (s_num[i + 1] < '0' || s_num[i + 1]  > '9'))
                    throw ScalarConverter::InputError();
            }
        }
    printConverter(s_num);
}
    

const  char * ScalarConverter::InputError::what()const throw()
{
    return ("Input Error try next time");
}