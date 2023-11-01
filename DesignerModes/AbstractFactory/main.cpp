#include "AbStractFactory.h"
#include "src/IFactroy.h"
#include <cassert>
#include <memory>
#include <iostream>
using namespace std;
void ClientCode(const AbstracFactory &factory)
{
    const AbstractProductA *product_a = factory.CreateProductA();
    const AbstractProductB *product_b = factory.CreateProductB();
    std::cout<<product_b->UseFulFunctionB() <<std::endl;
    std::cout<<product_b->AnotherUsefulFunctionB(*product_a)<<std::endl;
    delete product_a;
    delete product_b;
}

int main()
{
    // 第一种工厂demo
    if(0)
    {
        ConcreteFactory1 *f1 = new ConcreteFactory1();
        ClientCode(*f1);
        delete f1;
        std::cout <<std::endl;

        ConcreteFactory2 *f2 = new ConcreteFactory2();
        delete f2;
    }
    // 第二种工厂
    if(1)
    {
        std::shared_ptr<IFactory> factory(IFactoryHelper::getFactory("ListFactory"));
        assert(factory != nullptr);
        // 将生成的指针RAII方式，托管智能指针
        std::shared_ptr<ILink> people(factory->createLink("people", "www.people"));
        std::shared_ptr<ILink> gmw(factory->createLink("people", "www.people"));

        std::shared_ptr<ILink> us_yahoo(factory->createLink(u8"us_yahoo", u8"http://www.yahoo.com/"));
        std::shared_ptr<ILink> jp_yahoo(factory->createLink(u8"jp_yahoo", u8"http://www.yahoo.com.jp/"));
        std::shared_ptr<ILink> google(factory->createLink(u8"google", u8"http://www.google.com"));

        std::shared_ptr<ITray> trayNews(factory->createTray("news"));
        trayNews->addItem(people);
        trayNews->addItem(gmw);

        std::shared_ptr<ITray> trayyahoo(factory->createTray("yahoo"));
        trayyahoo->addItem(us_yahoo);
        trayyahoo->addItem(jp_yahoo);

        std::shared_ptr<ITray> traysearch(factory->createTray("traysearch"));
        traysearch->addItem(trayyahoo);
        traysearch->addItem(google);

        std::shared_ptr<IPage> page(factory->createPage("LINKPage", "we"));
        page->addItem(trayNews);
        page->addItem(traysearch);
        page->output();
        return 0;
    }
}