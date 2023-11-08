#pragma once
#include <string>
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