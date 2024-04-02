#ifndef SERIALIZATION_H
#define SERIALIZATION_H

#include <iostream>
#include "Data.hpp"
#include <string>
#include <stdint.h>

const std::string red("\033[0;31m");
const std::string green("\033[1;32m");
const std::string yellow("\033[1;33m");
const std::string cyan("\033[0;36m");
const std::string magenta("\033[0;35m");
const std::string reset("\033[0m");

typedef struct Data
{
	std::string	name;
	size_t		age;
	Data		*next;
}				Data;


class Serialization
{
private:
    Serialization(); 
public:
    // default;
    ~Serialization();
    Serialization( Serialization const & src );

    Serialization & operator=(Serialization const & rhs);

    //Static function
    static uintptr_t serialize(t_data* ptr);
    static t_data* deserialize(uintptr_t raw);
};


#endif