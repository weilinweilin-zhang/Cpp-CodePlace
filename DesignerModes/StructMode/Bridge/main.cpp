#include "Bridge.h"

int main()
{
    Implementation *imp = new ConcreteImplementationA;
    Abstraction *abs = new Abstraction(imp);
    ClientCode(*abs);
    std::cout << std::endl;
    delete imp;
    delete abs;
    imp = new ConcreteImplementationB;
    abs = new ExtendedAbstraction(imp);
    ClientCode(*abs);
    delete imp;
    delete abs;
    return 0;
}