#pragma once
#include <string>
#include <iostream>
using namespace std;
class Component
{
    public:
    virtual ~Component(){}
    virtual std::string Operation() const = 0;
};

class ConcreteComponent : public Component{
    public:
        std::string Operation() const override{
            return "ConcreteComponent";
        }
};

class Decorator:public Component
{
    protected:
        Component *component_;
    public:
        Decorator(Component *component) : component_(component){}

    std::string Operation() const override
    {
        return this->component_->Operation();
    }
};

class ConcreteDecoratorA : public Decorator
{
    public:
    ConcreteDecoratorA(Component *component):Decorator(component){}
    std::string Operation () const override
    {
        return "ConcreteDecoratorA" + Decorator::Operation() + ")";
    }
};

class ConcreteDecoratorB : public Decorator{
    public:
    ConcreteDecoratorB(Component *component) : Decorator(component){}

    std::string Operation() const override 
    {
        return "ConcreteDecoratorB" + Decorator::Operation() + ")";
    }
};

void clientCode(Component * component)
{
    std::cout << "Result" << component->Operation();
}
