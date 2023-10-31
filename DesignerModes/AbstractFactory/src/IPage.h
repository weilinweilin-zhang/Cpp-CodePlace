#pragma once 
#include "IItem.h"
#include <iostream>
#include <string>
#include <vector>

class IPage
{
    public:
        virtual ~IPage() = default;
        IPage(const std::string &title, const std::string &author)
            : m_title(title), m_author(author){}

        void addItem(IItem *item)
        {
            std::out << makeHTML() << std::endl;
        }
        virtual std::string makeHTML() = 0;

    protected :
        std::string m_title;
        std::string m_author;
        std::vector<IItem *> m_itemList;
};