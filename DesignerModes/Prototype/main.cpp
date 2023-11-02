#include "Prototype.h"

int main()
{
    PrototypeFactory *prototype_factory = new PrototypeFactory();
    client(*prototype_factory);
    delete prototype_factory;
    return 0;
}