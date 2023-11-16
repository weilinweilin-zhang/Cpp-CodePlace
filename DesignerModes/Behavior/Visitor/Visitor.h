#include <iostream>
#include <string>
using namespace std;
#include <array>
class ConcreteComponentA;
class ConcreteComponentB;

class Visitor {
 public:
  virtual void VisitConcreteComponentA(const ConcreteComponentA *element) const = 0;
  virtual void VisitConcreteComponentB(const ConcreteComponentB *element) const = 0;
};

/**
 * The Component interface declares an `accept` method that should take the base
 * visitor interface as an argument.
 */

class Component {
 public:
  virtual ~Component() {}
  virtual void Accept(Visitor *visitor) const = 0;
};

/**
 * Each Concrete Component must implement the `Accept` method in such a way that
 * it calls the visitor's method corresponding to the component's class.
 */
class ConcreteComponentA : public Component {
  /**
   * Note that we're calling `visitConcreteComponentA`, which matches the
   * current class name. This way we let the visitor know the class of the
   * component it works with.
   */
 public:
  void Accept(Visitor *visitor) const override {
    visitor->VisitConcreteComponentA(this);
  }
  /**
   * Concrete Components may have special methods that don't exist in their base
   * class or interface. The Visitor is still able to use these methods since
   * it's aware of the component's concrete class.
   */
  std::string ExclusiveMethodOfConcreteComponentA() const {
    return "A";
  }
};

class ConcreteComponentB : public Component {
  /**
   * Same here: visitConcreteComponentB => ConcreteComponentB
   */
 public:
  void Accept(Visitor *visitor) const override {
    visitor->VisitConcreteComponentB(this);
  }
  std::string SpecialMethodOfConcreteComponentB() const {
    return "B";
  }
};

/**
 * Concrete Visitors implement several versions of the same algorithm, which can
 * work with all concrete component classes.
 *
 * You can experience the biggest benefit of the Visitor pattern when using it
 * with a complex object structure, such as a Composite tree. In this case, it
 * might be helpful to store some intermediate state of the algorithm while
 * executing visitor's methods over various objects of the structure.
 */
class ConcreteVisitor1 : public Visitor {
 public:
  void VisitConcreteComponentA(const ConcreteComponentA *element) const override {
    std::cout << element->ExclusiveMethodOfConcreteComponentA() << " + ConcreteVisitor1\n";
  }

  void VisitConcreteComponentB(const ConcreteComponentB *element) const override {
    std::cout << element->SpecialMethodOfConcreteComponentB() << " + ConcreteVisitor1\n";
  }
};

class ConcreteVisitor2 : public Visitor {
 public:
  void VisitConcreteComponentA(const ConcreteComponentA *element) const override {
    std::cout << element->ExclusiveMethodOfConcreteComponentA() << " + ConcreteVisitor2\n";
  }
  void VisitConcreteComponentB(const ConcreteComponentB *element) const override {
    std::cout << element->SpecialMethodOfConcreteComponentB() << " + ConcreteVisitor2\n";
  }
};
/**
 * The client code can run visitor operations over any set of elements without
 * figuring out their concrete classes. The accept operation directs a call to
 * the appropriate operation in the visitor object.
 */
void ClientCode(std::array<const Component *, 2> components, Visitor *visitor) {
  // ...
  for (const Component *comp : components) {
    comp->Accept(visitor);
  }
  // ...
}




// other demo

class Element;
class CPU;
class VideoCard;
class MainBoard;
 
/*------------------*/
class Visitor {
public:
    Visitor(std::string name) {
        visitorName = name;
    }
    virtual void visitCPU( CPU* cpu ) {};
    virtual void visitVideoCard( VideoCard* videoCard ) {};
    virtual void visitMainBoard( MainBoard* mainBoard ) {};
 
 
    std::string getName() {
        return this->visitorName;
    };
private:
    std::string visitorName;
};
 
 
class Element {
public:
    Element( std::string name ) {
        eleName = name;
    }
    virtual void accept( Visitor* visitor ) {};
 
    virtual std::string getName() {
        return this->eleName;
    }
private:
    std::string eleName;
};
 
/*----------- Elements -------------*/
 
class CPU : public Element {
public:
    CPU(std::string name) : Element(name) {}
 
    void accept(Visitor* visitor) {
        visitor->visitCPU(this);
    }
};
 
class VideoCard : public Element {
public:
    VideoCard(std::string name) : Element(name) {}
 
    void accept(Visitor* visitor) {
        visitor->visitVideoCard(this);
    }
};
 
class MainBoard : public Element {
public:
    MainBoard(std::string name) : Element(name) {}
      
    void accept(Visitor* visitor) {
        visitor->visitMainBoard(this);
    }
};
 
/*----------- ConcreteVisitor -------------*/
 
class CircuitDetector : public Visitor {
public:
    CircuitDetector(std::string name) : Visitor(name) {}
 
    // checking cpu
    void visitCPU( CPU* cpu ) {
        std::cout << Visitor::getName() << " is checking CPU's circuits.(" << cpu->getName()<<")" << std::endl;
    }
 
    // checking videoCard
    void visitVideoCard( VideoCard* videoCard ) {
        std::cout << Visitor::getName() << " is checking VideoCard's circuits.(" << videoCard->getName()<<")" << std::endl;
    }
 
    // checking mainboard
    void visitMainBoard( MainBoard* mainboard ) {
        std::cout << Visitor::getName() << " is checking MainBoard's circuits.(" << mainboard->getName() <<")" << std::endl;
    }
 
};
 
class FunctionDetector : public Visitor {
public:
    FunctionDetector(std::string name) : Visitor(name) {}
    virtual void visitCPU( CPU* cpu ) {
        std::cout << Visitor::getName() << " is check CPU's function.(" << cpu->getName() << ")"<< std::endl;
    }
 
    // checking videoCard
    void visitVideoCard( VideoCard* videoCard ) {
        std::cout << Visitor::getName() << " is checking VideoCard's function.(" << videoCard->getName()<< ")" << std::endl;
    }
 
    // checking mainboard
    void visitMainBoard( MainBoard* mainboard ) {
        std::cout << Visitor::getName() << " is checking MainBoard's function.(" << mainboard->getName() << ")"<< std::endl;
    }
};
 
 
/*------------------------*/
 
class Computer {
public:
    Computer(CPU* cpu,
            VideoCard* videocard,
            MainBoard* mainboard) {
        elementList.push_back(cpu);
        elementList.push_back(videocard);
        elementList.push_back(mainboard);
    };
    void Accept(Visitor* visitor) {
        for( std::vector<Element*>::iterator i = elementList.begin(); i != elementList.end(); i++ )
        {
            (*i)->accept(visitor);
        }
    }; 
private:
    std::vector<Element*> elementList;
};