#include "Serialization.hpp"
#include "Data.hpp"
#include <stdlib.h>


int main(void)
{
    t_data *d;
    uintptr_t u_ptr;

    d = (t_data *)malloc(sizeof(t_data));
    if (!d)
        return (-1);
    d->create = true;
    u_ptr = Serialization::serialize(d);
    // Affiche les valeurs de u_ptr et d
    std::cout << "Valeur de u_ptr : " << Serialization::deserialize(u_ptr) << std::endl;
    std::cout << "Adresse pointée par d : " << d << std::endl;
}