#include <stdio.h>
#include <iostream>
#include "Factory.h"
using namespace std;
void clientCode(const Creator & creator)
{
    std::cout << creator.Someoperation() << std::endl;
}

// 用不同的工厂创建不同的产品，一种一一对应的感觉有点冗余
int main()
{
    Creator* creator = new concreateCreator1();
    clientCode(*creator);
    Creator* creator2 = new concreateCreator2();
    clientCode(*creator2);
    return 0;
}