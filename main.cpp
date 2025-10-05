#include <iostream>
// #include "SingletonPattern.h"
// #include "SimpleFactory.h"
// #include "Factory.h"
#include "AbstractFactory.h"

int main()
{
    // SingletonPattern* sp1 = SingletonPattern::GetInstance();
    // sp1->print();
    // SingletonPattern* sp2 = SingletonPattern::GetInstance();
    // sp2->print();
    // std::cout << "sp1 : " << sp1 << "sp2 : " << sp2 << std::endl;

    // Simple Factory
    // SimpleFactory* factory = new SimpleFactory;
    // Father* child1 = factory->create(ChildType::Child1);
    // child1->introduce();
    // Father* child2 = factory->create(ChildType::Child2);
    // child2->introduce();
    // delete factory;

    // Factory Method
    // SimpleFactory* factory = new Child1Factory();
    // Father* child1 = factory->create();
    // child1->introduce();
    // delete factory;
    // factory = new Child2Factory();
    // Father* child2 = factory->create();
    // child2->introduce();
    // delete factory;
    // delete child1;
    // delete child2;

    // Abstract Factory
    AbstractFactory* factory = new StandardFactory();
    Computer* computer = factory->createComputer();
    computer->display();
    delete factory;
    delete computer;
    factory = new BasicFactory();
    computer = factory->createComputer();
    computer->display();
    delete factory;
    delete computer;

    return 0;
}