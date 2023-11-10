#pragma once
#include <string>
#include <iostream>
using namespace std;
class Subsystem1{
    public:
     std::string Operation1() const{
         return "Subsystem1 : Ready! \n";
     }

    std::string OperationN() const{
         return "Subsystem1: go! \n";
    }
};

class Subsystem2{
 public:
     std::string Operation1() const{
         return "Subsystem : Get ready!\n";
     }
     std::string OperationZ() const {
         return "SubSytem2 : Fire! \n";
     }
};

class Facade
{
    protected:
        Subsystem1 *Subsystem1_;
        Subsystem2 *Subsystem2_;
    public:

    Facade(Subsystem1 *subsystem1 = nullptr,
           Subsystem2 *subsystem2 = nullptr)
           {
            this->Subsystem1_ = subsystem1 ?subsystem1 : new Subsystem1;
            this->Subsystem2_ = subsystem2 ?subsystem2 : new Subsystem2;
           }
    ~Facade()
    {
        delete Subsystem1_;
        delete Subsystem2_;
    }
    std::string Operation() {
    std::string result = "Facade initializes subsystems:\n";
    result += this->Subsystem1_->Operation1();
    result += this->Subsystem2_->Operation1();
    result += "Facade orders subsystems to perform the action:\n";
    result += this->Subsystem1_->OperationN();
    result += this->Subsystem2_->OperationZ();
    return result;
  }
};