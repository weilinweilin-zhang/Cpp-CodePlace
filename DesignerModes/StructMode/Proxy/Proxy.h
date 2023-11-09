#pragma once
#include <string>
#include <iostream>
using namespace std;

class Subject
{
    public:
        virtual void Request() const = 0;
};

class RealSubject : public Subject
{
    public:
    void Request() const override{
        std::cout << "RealSubject: handling request\n";
    }
};

// 继承的话，方便在重构的时候，最小的影响到程序

// 可以在这边做 判断、拦截、缓存的操作
class Proxy: public Subject{
private:
    RealSubject *real_subject;
    bool CheckAccess() const
    {
        std::cout << "proxy: checking access prior to firing a real request \n";
        return true;
    }
    
    void LogAccess() const{
        std::cout << "proxy : logging the time of request";
    }
    Proxy(RealSubject *real_subject) : real_subject(new RealSubject(*real_subject)) {
  }
    ~Proxy() {
        delete real_subject;}

    void Request() const override {
    if (this->CheckAccess()) {
      this->real_subject->Request();
      this->LogAccess();
    }
  }
};


