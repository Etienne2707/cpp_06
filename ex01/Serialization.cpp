#include "Serialization.hpp"

Serialization::Serialization()
{
    std::cout << yellow << " Default constructor called" << reset << std::endl;
}

Serialization::~Serialization()
{
    std::cout << red <<  "Destructor called" << reset << std::endl;
}

Serialization::Serialization( Serialization const & src ){
    std::cout << " Copy constructeur called" <<  reset << std::endl;
    *this = src;
}


Serialization & Serialization::operator=(Serialization const & rhs)
{
    std::cout << "Assignment operator called" << std::endl;
    return *this;
}

uintptr_t Serialization::serialize(t_data *ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}


t_data*  Serialization::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<t_data *>(raw));
}