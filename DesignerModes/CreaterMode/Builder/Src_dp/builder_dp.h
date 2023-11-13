#pragma once
#include <vector>
#include <iostream>
using namespace std;
class Product1{
public:
    std::vector<std::string> parts_;
    
    void ListParts() const{
        std::cout << "product parts";
        for (size_t i = 0; i < parts_.size();i++)
        {
            if(parts_[i] == parts_.back())
            {
                std::cout << parts_[i];
            }
            else{
                std::cout << parts_[i] << ",";
            }
        }
        std::cout << std::endl;
    }
};

// 基类都是用来规定接口的
class Builder{
public:
    virtual ~Builder() = default;
    virtual void ProductPartA() const = 0;
    virtual void ProductPartB() const = 0;
    virtual void ProductPartC() const = 0;
};

class ConcreteBuilder1 : public Builder
{
    private:
        Product1 *product;
    public:
        ConcreteBuilder1() { this->Reset(); }
        ~ConcreteBuilder1() { delete product; }
        void Reset()
        {
            this->product = new Product1;
        }

        void ProductPartA()const override{
            this->product->parts_.push_back("PartA1");
        }
        void ProductPartB()const override{
            this->product->parts_.push_back("PartB1");
        }
        void ProductPartC()const override{
            this->product->parts_.push_back("PartC1");
        }
    Product1 *GetProduct(){
        Product1 *result = this->product;
        this->Reset();
        return result;
    }
};

// 主管类 ，管理生成顺序，在有订单或者配置的很有用
class Director{
    private:
        Builder *builder;
    public:

    void set_builder(Builder *builder)
    {
        this->builder = builder;
    }

    void buildMiniMaViableProduct()
    {
        this->builder->ProductPartA();
    }

    void buildFullFeatureProduct()
    {
        this->builder->ProductPartA();
        this->builder->ProductPartB();
        this->builder->ProductPartC();
    }
};


// 代码解读
// build 可以指定生成具体类型产品，product 也可以做成基类，适应多种产品
// 流程：
// 主管类 或者 自定义 可以指定 产品的生成流程
// 然后 具体的子生成器可以 绑定一种类型的产品 或者是产品的基类   比如哥特式的房子
// 再通过 方法生成自己想要的 装饰，比如 配游泳池的 ，配花园的，或者是组合的具体的哥特式房子 
void ClientCode(Director &director)
{
    ConcreteBuilder1 *builder = new ConcreteBuilder1();
    director.set_builder(builder);
    std::cout << "standard basic product";
    director.buildMiniMaViableProduct();
    
    Product1* p = builder->GetProduct();
    p->ListParts();
    delete p;

    std::cout<< "standard full feature product"<< std::endl;
    director.buildFullFeatureProduct();

    p = builder->GetProduct();
    p->ListParts();
    delete p;

    std::cout << "custom product";
    builder->ProductPartA();
    builder->ProductPartC();
    p = builder->GetProduct();
    p->ListParts();
    delete p;
}