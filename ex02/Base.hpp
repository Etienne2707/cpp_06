#ifndef BASE_H
#define BASE_H
#include <string>

class A;
class B;
class C;

const std::string red("\033[0;31m");
const std::string green("\033[1;32m");
const std::string yellow("\033[1;33m");
const std::string cyan("\033[0;36m");
const std::string magenta("\033[0;35m");
const std::string reset("\033[0m");

class Base
{
private:
    /* data */
public:
    virtual ~Base(){}

};


#endif