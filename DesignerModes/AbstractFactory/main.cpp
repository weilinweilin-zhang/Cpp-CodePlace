#include "AbStractFactory.h"
#include <iostream>
using namespace std;
void ClientCode(const AbstracFactory &factory)
{
    const AbstractProductA *product_a = factory.CreateProductA();
    const AbstractProductB *product_b = factory.CreateProductB();
    std::cout<<product_b->UseFulFunctionB() <<std::endl;
    std::cout<<product_b->AnotherUsefulFunctionB(*product_a)<<std::endl;
    delete product_a;
    delete product_b;
}

int main()
{
    ConcreteFactory1 *f1 = new ConcreteFactory1();
    ClientCode(*f1);
    delete f1;
    std::cout <<std::endl;

    ConcreteFactory2 *f2 = new ConcreteFactory2();
    delete f2;
}