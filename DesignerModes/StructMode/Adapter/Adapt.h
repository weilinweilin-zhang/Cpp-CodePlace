#pragma once
#include <string>
#include <iostream>
using namespace std;

// 链接客户端的主要接口
class Target{
    public:
        virtual ~Target() = default;
        virtual std::string Request() const {
            return "target: the default target's behaviror";
        }

};

// 适配的目标
class  Adaptee
{
    public:
    std::string Specificrequest() const {
            return "eetpadA of behaviors";
    }
};


class Adapter:public Target{
    private:
    Adaptee *adaptee_;

    public:
        Adapter(Adaptee *adaptee) : adaptee_(adaptee){}
        std::string Request() const override{
            std::string to_reverse = this->adaptee_->Specificrequest();
            std::reverse(to_reverse.begin(), to_reverse.end());
            return "Adapter:(TRANSLATED)" + to_reverse;
        }
};

void ClientCode(const Target *target)
{
        std::cout << target->Request();
}

