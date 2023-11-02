#pragma once
#include "IFactroy.h"
#include "ListLink.h"
#include "ListPage.h"
#include "ListTray.h"

// 子工厂规定生成的具体的产品
class ListFactory : public IFactory
{
    public:
        ILink *createLink(const std::string &caption, const std::string &url) override
        {
            return new ListLink(caption, url);
        }
        ITray *createTray(const std::string &caption) override
        {
            return new ListTray(caption);
        }
        IPage *createPage(const std::string &title, const std::string &author) override
        {
            return new ListPage(title, author);
        }
};

// 注册通常跟回调搭配
static auto ListFactoryInit = []() -> int
{
    IFactoryHelper::registerFactory("ListFactory", []()
                                    { return new ListFactory ;});
    return 0;
}();