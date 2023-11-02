#pragma once
#include <iostream>
#include <vector>
#include "IItem.h"
#include <string>

// 这是独立的一零件
class IPage
{
public:
    virtual ~IPage() = default;
    IPage(const std::string &title,const std::string &author) : m_title(title),m_author(author){}

    void addItem(std::shared_ptr<IItem> item)
    {
        m_itemlist.push_back(item);
    }
    void output()
    {
        std::cout << makeHTML() << std::endl;
    }

    virtual std::string makeHTML() = 0;

protected:
    std::string m_title;
    std::string m_author;
    std::vector<std::shared_ptr<IItem>> m_itemlist;
};