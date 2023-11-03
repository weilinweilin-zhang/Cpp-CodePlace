#include  "Adapt.h"
int main()
{
        std::cout << "client i can work tagert";
        Target *target = new Target;
        ClientCode(target);
        std:cout<<std::endl;
        Adaptee *adaptee = new Adaptee;
        std:: cout << "Adaptee" << adaptee->Specificrequest();
        std::cout << std::endl;
        Adapter *adapter = new Adapter(adaptee);
        ClientCode(adapter);
        delete target;
        delete adaptee;
        delete adapter;
        return 0;
}