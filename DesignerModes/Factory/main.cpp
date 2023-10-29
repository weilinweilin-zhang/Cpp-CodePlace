#include <stdio.h>
#include <iostream>
#include "Factory.h"
using namespace std;
void clientCode(const Creator & creator)
{
    std::cout << creator.Someoperation() << std::endl;
}
int main()
{

    std::cout << "we";
    return 0;
}