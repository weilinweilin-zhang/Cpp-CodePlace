#pragma once
#include <string>
using namespace std;
#include <iostream>
class Implementation
{
    public:
    virtual ~Implementation() = default;
    virtual std::string operatorImplementation() const = 0;
};


class ConcreteImplementationA : public Implementation
{
    public:
    std::string operatorImplementation() const override
    {
        return "ConCreteImplementationA here's";
    }
};

class ConcreteImplementationB : public Implementation
{
    public:
    std::string operatorImplementation() const override
    {
        return "ConCreteImplementationB here's";
    }
};

class Abstraction
{
    protected:
        Implementation *Implementation_;

    public:
        // 这边可以单独抓一个函数接收 implementation变量 增加灵活性 
        Abstraction(Implementation *implementation): Implementation_(implementation)
        {}

        virtual ~Abstraction(){}

        virtual std::string Operation()const {
        return "Abstraction : base operation with : " +
               this->Implementation_->operatorImplementation();
        }
};

class ExtendedAbstraction :public Abstraction{
    public:
    ExtendedAbstraction(Implementation* implementtation): Abstraction(implementtation){
    }
    std::string Operation() const override
    {
        return "ExtendedAbstaractio";
    }
};


void ClientCode(const Abstraction & absreaction)
{
    std::cout << absreaction.Operation() << std::endl;
}