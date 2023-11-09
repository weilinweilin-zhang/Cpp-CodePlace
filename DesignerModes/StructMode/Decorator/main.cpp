#include "Decorator.h"

int main() 
{
    Component *simple = new ConcreteComponent;
    std::cout << "clienet : i've got a simple component";
    clientCode(simple);
    std::cout << std::endl;
    // 这种指针的浅拷贝，得注意生命周期
    Component *decorator1 = new ConcreteDecoratorA(simple);
    Component *decorator2 = new ConcreteDecoratorB(decorator1);
    std::cout << "client : now i've got a decorated component";
    clientCode(decorator2);
    std::cout <<std::endl;

    delete simple;
    delete decorator1;
    delete decorator2;
    return 0;
}