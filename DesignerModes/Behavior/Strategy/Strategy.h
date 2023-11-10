#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

class Strategy
{
    public:
        virtual ~Strategy() = default;
        virtual std::string doAlgorithm(std::string_view data) const = 0;
};

class Context
{
    private:
        std::unique_ptr<Strategy> strategy_;
    public:
        explicit Context(std::unique_ptr<Strategy> &&strategy = {}) 
        : strategy_(std::move(strategy)){}
        void set_strategy(std::unique_ptr<Strategy> &&strategy)
        {
            strategy_ = std::move(strategy);
        }
        void doSomeBusinessLogic()const 
        {
            if(strategy_)
            {
                std::cout << "context:Sortingdatausingthestrategy ();" << std::endl;
            }
        }
};

class ConcreteStrategyA:public Strategy
{
    public:
    std::string doAlgorithm(std::string_view data) const override 
    {
        std::string result(data);
        std::sort(std::begin(result), std::end(result));
        return result;
    }
};

class ConcreteStrategyB : public Strategy
{
    std::string doAlgorithm(std::string_view data) const override
    {
        std::string result(data);
        std::sort(std::begin(result), std::end(result), std::greater<>());
        return result;
    }
};

void clientCode()
{
    Context context(std::make_unique<ConcreteStrategyA>());
    std::cout << "Client: Strategy is set to normal sorting.\n";
    context.doSomeBusinessLogic();
    std::cout << "\n";
    std::cout << "Client: Strategy is set to reverse sorting.\n";
    context.set_strategy(std::make_unique<ConcreteStrategyB>());
    context.doSomeBusinessLogic();
}


int main()
{
    clientCode();
    return 0;
}