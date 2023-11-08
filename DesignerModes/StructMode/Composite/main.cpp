#include "Composite.h"

int main()
{
    Component *simple = new Leaf;
    std::cout << "Client :i've got a simple component" << std::endl;
    clientCode(simple);
    std::cout << std::endl;

    Component *tree = new Composite;
    Component *branch1 = new Composite;

    Component *leaf_1 = new Leaf;
    Component *leaf_2 = new Leaf;
    Component *leaf_3 = new Leaf;
    branch1->Add(leaf_1);
    branch1->Add(leaf_2);

    Component *branch2 = new Composite;
    branch2->Add(leaf_3);
    tree->Add(branch1);
    tree->Add(branch2);
    std::cout << "client: Now I've got a Composite tree";
    clientCode(tree);
    std::cout << std::endl;

    std::cout << "client: i don't need to check the component classes even";
    clientCode2(tree, simple);
    std::cout << std::endl;

    delete simple;
    delete tree;
    delete branch1;
    delete branch2;
    delete leaf_1;
    delete leaf_2;
    delete leaf_3;

    return 0;
}