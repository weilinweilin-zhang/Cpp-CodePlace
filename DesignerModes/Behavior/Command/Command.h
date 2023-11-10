#include <string>
using namespace std;
#include <iostream>

class Command{
    public:
    virtual ~Command(){}
    virtual void Execute() const = 0;
};

class SimpleCommand : public Command{
    private:
        std::string pay_load_;
    public:
        explicit SimpleCommand(std::string pay_load): pay_load_(pay_load){}

        void Execute() const override{
        std::cout << "simpleCommand see ,i can do simple things" + this->pay_load_;
        }
};


class Receiver
{
    public:
    void DoSomething(const ::std::string &a)
    {
        std::cout << "receive : working on" << a << std::endl;
    }
    void DoSomethingElse(const ::std::string &a)
    {
        std::cout << "receive also: working on else " << a << std::endl;
    }
};


class ComplexCommand:public Command
{
    private:
    Receiver * receiver_;
    std::string a_;
    std::string b_;
    public:
    ComplexCommand(Receiver *receiver,std::string a,std::string b)
        : receiver_(receiver),a_(a),b_(b)
        {
        }
        void Execute() const override
        {
            std::cout
            << "complexcommand:  complex stff should be done by a receive" << std::endl;
            this->receiver_->DoSomething(this->a_);
            this->receiver_->DoSomethingElse(this->b_);
        }
};

class Invoker{
private:
    Command *on_start_;
    Command *on_finish_;
public:
    ~Invoker(){
        delete on_start_;
        delete on_finish_;
    }

    void SetOnstart(Command *command)
    {
        this->on_start_ = command;
    }
    void SetOnFinish(Command *command)
    {
        this->on_finish_ = command;
    }
    void DoSomethingImportant() {
    std::cout << "Invoker: Does anybody want something done before I begin?\n";
    if (this->on_start_) {
      this->on_start_->Execute();
    }
    std::cout << "Invoker: ...doing something really important...\n";
    std::cout << "Invoker: Does anybody want something done after I finish?\n";
    if (this->on_finish_) {
      this->on_finish_->Execute();
    }
  }
};

int main() {
    Invoker *invoker =new Invoker;
    invoker->SetOnstart(new SimpleCommand("say hi !"));
    Receiver *receiver = new Receiver;
    invoker->SetOnFinish(new Complexcommand(receiver, "send email", "save report"));
    invoker->DoSomethingImportant();
    delete invoker;
    delete receiver;
    return 0;
}

