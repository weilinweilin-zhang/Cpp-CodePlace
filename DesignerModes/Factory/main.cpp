#include <stdio.h>
#include <iostream>
#include "Factory.h"
using namespace std;
void clientCode(const Creator & creator)
{
    std::cout << creator.Someoperation() << std::endl;
}

// �ò�ͬ�Ĺ���������ͬ�Ĳ�Ʒ��һ��һһ��Ӧ�ĸо��е�����
int main()
{
    Creator* creator = new concreateCreator1();
    clientCode(*creator);
    Creator* creator2 = new concreateCreator2();
    clientCode(*creator2);
    return 0;
}