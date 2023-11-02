#pragma once
using namespace std;
#include <iostream>
#include <string>

enum Type
{
    PROTOTYPE1 = 0,
    PROTOTYPE2 = 1
};

class Prototype{
    protected:
        string prototype_name;
        float prototype_field;
    public:     
        Prototype(){}
        Prototype(string prototype_name)
            :   prototype_name(prototype_name){}

        virtual ~Prototype() {}
        virtual Prototype *Clone() const = 0;
        virtual void Method(float prototype_field){
            this->prototype_field = prototype_field;
            std::cout << "call method from" << prototype_name << "with field:" << prototype_field << std::endl;
        }
};

class ConcretePrototype1:public Prototype{
    private:
        float concrete_prototype_field1_;
    public:
    ConcretePrototype1(string prototype_name,float concrete_prototype_filed)
        : Prototype(prototype_name),concrete_prototype_field1_(concrete_prototype_filed){}

        // 这个是浅拷贝如果没有重写operate = 的时候。
        Prototype *Clone() const override {
        // new 出一个指针在将this的类容 = 进去赋值 
            return new ConcretePrototype1(*this);
        }
};

class ConcretePrototype2 : public Prototype {
 private:
  float concrete_prototype_field2_;

 public:
  ConcretePrototype2(string prototype_name, float concrete_prototype_field)
      : Prototype(prototype_name), concrete_prototype_field2_(concrete_prototype_field) {
  }
  Prototype *Clone() const override {
    return new ConcretePrototype2(*this);
  }
};

#include <unordered_map>
class PrototypeFactory
{
    private:
        std::unordered_map<Type, Prototype *, std::hash<int>> Prototypes_;
    public:
        PrototypeFactory()
        {
            Prototypes_[Type::PROTOTYPE1] = new ConcretePrototype1("Prototype1", 50.f);
            Prototypes_[Type::PROTOTYPE2] = new ConcretePrototype1("Prototype2", 60.f);
        }
    ~PrototypeFactory()
    {
            delete Prototypes_[Type::PROTOTYPE1];
            delete Prototypes_[Type::PROTOTYPE2];
    }
    Prototype *CreatorPrototype(Type type)
    {
            return Prototypes_[type]->Clone();
    }

};

void client(PrototypeFactory &prototype_factory)
{
    std::cout << "lest's create a prototype " << std::endl;
    Prototype *prototype = prototype_factory.CreatorPrototype(Type::PROTOTYPE1);
    prototype->Method(90);
    delete prototype;
    std::cout << "\n";
    std::cout << "Let's create a Prototype 2 \n";
    prototype = prototype_factory.CreatorPrototype(Type::PROTOTYPE2);
    prototype->Method(10);
    delete prototype;
}