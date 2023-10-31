#pragma once
#include <string>
using namespace std;
class AbstractProductA{
public:
    virtual ~AbstractProductA() = default;
    virtual std::string UsefulFunctionA() const = 0;
};

class ConcreateProductA1 : public AbstractProductA
{
    public:
    std::string UsefulFunctionA() const override{
        return "return result of productA1";
    }
};

class ConcreateProductA2 :public AbstractProductA
{
    std::string UsefulFunctionA() const override
    { 
        return "return result of productA2";
    } 
};

// 另外一个产品
class AbstractProductB{
    public:
    virtual ~AbstractProductB() = default;
    virtual std::string UseFulFunctionB() const = 0;
    virtual std::string AnotherUsefulFunctionB(const AbstractProductA &collaborator) const = 0;
};

class concreateProductB1 :public AbstractProductB{
    public:
    std::string UseFulFunctionB() const override
    {
        return "The result of the product B1";
    }

    std::string AnotherUsefulFunctionB(const AbstractProductA &colllaborate) const override
    {
        const std::string result = colllaborate.UsefulFunctionA();
        return "The result of the B1 collaborating with (" + result + ")";
    }
};


class ConcreteProductB2 : public AbstractProductB {
 public:
  std::string UseFulFunctionB() const override {
    return "The result of the product B2.";
  }
  
  std::string AnotherUsefulFunctionB(const AbstractProductA &collaborator) const override {
    const std::string result = collaborator.UsefulFunctionA();
    return "The result of the B2 collaborating with ( " + result + " )";
  }
};

// 在定义一个抽象工厂，这个工厂中的一个产品就是一系列产品
class AbstracFactory
{
    public:
    virtual AbstractProductA *CreateProductA() const = 0;
    virtual AbstractProductB *CreateProductB() const = 0;
};

// 子项的工厂知道自己要创建什么类型的产品
// 每个子工程创建一系列产品
// 但是在自己的工厂里面就决定着，要创建什么类型的子类了
// 具体的子类
// 相比普通的工厂就是每一个工厂可以多种产品。
class ConcreteFactory1 : public AbstracFactory{
   public:
   AbstractProductA *CreateProductA() const override{
        return new ConcreateProductA1();
   } 
   AbstractProductB *CreateProductB() const override
   {
        return new concreateProductB1();
   }
};


class ConcreteFactory2 : public AbstracFactory{
    public:
    AbstractProductA *CreateProductA() const override{
        return new ConcreateProductA2();
    }
    AbstractProductB *CreateProductB() const override{
        return new ConcreteProductB2();
    }
};