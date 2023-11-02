#pragma once
#include "IItem.h"
#include <vector>
class ITray : public IItem
{
public:
    virtual ~ITray() {}
    ITray(const std::string &caption) : IItem(caption) {}
    void addItem(std::shared_ptr<IItem> item)
    {
       m_itemList .push_back(item);
    }

protected:
    // 最好不用原始指针，因为.get出来的原指针不参与引用计数
    // 有概率变成野指针
    std::vector<std::shared_ptr<IItem>> m_itemList;
};