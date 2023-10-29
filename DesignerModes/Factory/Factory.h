#pragma once
#include <string.h>
class Product{
public:
    virtual ~Product() = default;
    virtual std::string Operation() const = 0;
};

class subProduct1 : public Product
{
public:
    std::string Operation() const override
    {
        return "{result of product1}";
    }
};

class subProduct2 : public Product
{
    public:
        std::string Operation() const override
        {
        return "{result of product2}";
        }
};

class Creator{
    public:
        virtual ~Creator() = default;
        virtual Product *FactoryMethod() const = 0;

    std::string Someoperation() const{
        // 这什么意思 每个创建者 读取自己的类进行创建product
        Product * product = this->FactoryMethod();
        std::string result = "creator" + product->Operation();
        delete product;
        return result;
    }
};

class concreateCreator1 : public Creator
{
    public:
    Product *FactoryMethod() const override{
        return new subProduct1();
    }
};

class concreateCreator2 :public Creator
{
    public:
    Product *FactoryMethod() const override
    {
        return new subProduct2;
    }
}

class Factory
{
    public:
        Factory();
        ~Factory() = default;
        
};