#pragma once
#include "IItem.h"
#include "ILink.h"
#include "IPage.h"
#include "ITray.h"
#include <string>
#include <functional>
#include <unordered_map>
// 基类工厂提供架构，要创建的东西(各种产品零件) 
// 具体的子类工厂创建具体型号的零件
class IFactory
{
    public:
        virtual ~IFactory() = default;
        virtual ILink *createLink(const std::string &caption, const std::string &url) = 0;
        virtual ITray *createTray(const std::string &caption) = 0;
        virtual IPage *createPage(const std::string &title, const std::string &author) = 0;
};

class IFactoryHelper
{
    public:
    static void registerFactory(const std::string &name, std::function<IFactory *()> createCallback)
    {
        s_createrMap.insert(std::make_pair(name, createCallback));
    }
    static IFactory *getFactory(const std::string &name)
    {
        auto itor = s_createrMap.find(name);
        return itor->second();
    }
        // 注册容器，在托管帮助类这边就可以拿到所有子类的对象 （主要作用静态变量，但是释放是个问题）
    static std::unordered_map<std::string, std::function<IFactory *()>> s_createrMap;
};
// 定义并且分配内存空间
std::unordered_map<std::string, std::function<IFactory *()>> IFactoryHelper::s_createrMap;