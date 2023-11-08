#include <algorithm>
#include <iostream>
#include <list>
#include <string>

class Component{
    protected:
        Component *parent_;
    public:
        virtual ~Component() {};
        void SetParent(Component *parent)
        {
            this->parent_ = parent;
        }
        Component *Getparent() const 
        {
            return this->Getparent();
        }
        virtual void Add (Component *component){}
    
        virtual void Remove(Component *Component){}

        virtual bool IsComposite() const 
        {
            return false;
        }
        virtual std::string Operation() const = 0;

};

class Leaf :public Component{
    public:
    std::string Operation () const override
    {
            return "Leaf";
    }
};

class Composite :public Component{
    protected :
        std::list<Component*> childeren_;
    public:
        void Add(Component *component) override
        {
            this->childeren_.push_back(component);
            component->SetParent(this);
        }
        void Remove(Component *Component) override
        {
            childeren_.remove(Component);
            Component->SetParent(nullptr);
        }
        bool IsComposite() const override
        {
            return true;
        }
        std::string Operation() const override
        {
            std::string result;
            for(const Component * c :childeren_){
                if(c == childeren_.back())
                {
                    result += c->Operation();
                }
                else{
                    result += c->Operation() + "+";
                }
            }
            return "Branch(" + result + ")";
        }
};

void clientCode(Component *Component)
{
        std::cout << "RESULT:" << Component->Operation();
}

void clientCode2(Component *component1,Component *component2)
{
    if(component1->IsComposite())
    {
        component1->Add(component2);
    }
    std::cout << "RESULT" << component1->Operation();
}

