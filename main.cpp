#include <iostream>
// #include "SingletonPattern.h"
// #include "SimpleFactory.h"
// #include "Factory.h"
// #include "AbstractFactory.h"
// #include "Builder.h"
// #include "Prototype.h"
// #include "Adapter.h"
// #include "Bridge.h"
// #include "Facade.h"
#include "Decorator.h"

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
    // AbstractFactory* factory = new StandardFactory();
    // Computer* computer = factory->createComputer();
    // computer->display();
    // delete factory;
    // delete computer;
    // factory = new BasicFactory();
    // computer = factory->createComputer();
    // computer->display();
    // delete factory;
    // delete computer;

    // Builder
    // Director* director = new Director();
    // Builder* builder_office = new OfficeBuilder();
    // Builder* builder_game = new GameBuilder();
    // Computer* computer_office = director->construct(builder_office);
    // Computer* computer_game = director->construct(builder_game);
    // std::cout << "Office Computer : " << computer_office->display() << std::endl;
    // std::cout << "Game Computer : " << computer_game->display() << std::endl;
    // delete director;
    // delete builder_office;
    // delete builder_game;
    // delete computer_office;
    // delete computer_game;

    // Prototype
    // Character* minion = new Minion();
    // Character* boss = new Boss();
    // Character* copy1 = minion->clone();
    // Character* copy2 = boss->clone();
    // std::cout << "Minion HP : " << minion->display() << std::endl;
    // std::cout << "Boss HP : " << boss->display() << std::endl;
    // std::cout << "Copy1 HP : " << copy1->display() << std::endl;
    // std::cout << "Copy2 HP : " << copy2->display() << std::endl;
    // delete minion;
    // delete boss;
    // delete copy1;
    // delete copy2;

    // Adapter Class
    // PNGProcessor* image1 = new AdapterJPG();
    // PNGProcessor* image2 = new PNGProcessor();
    // std::cout << image1->processPNG() << std::endl;
    // std::cout << image2->processPNG() << std::endl;
    // delete image1;
    // delete image2;
    // Adapter Object
    // Image* img1 = new AdapterJPG("/res/image.jpg");
    // Image* img2 = new AdapterPNG("/res/image.png");
    // std::cout << "img1 : " << img1->getImage() << std::endl;
    // std::cout << "img2 : " << img2->getImage() << std::endl;
    // delete img1;
    // delete img2;

    // Bridge
    // Body* body1 = new Body(new Red(), new Circle());
    // Body* body2 = new Body(new Green(), new Circle());
    // std::cout << "Body1 : " << body1->display() << std::endl;
    // std::cout << "Body2 : " << body2->display() << std::endl;
    // delete body1;
    // delete body2;

    // Facade
    // TV* tv = new TV();
    // SpeakerBluetooth* sb = new SpeakerBluetooth();
    // Housekeeper* hk = new Housekeeper();
    // std::cout << hk->watchTV(tv, sb) << std::endl;
    // delete tv;
    // delete sb;
    // delete hk;

    // Decorator
    MilkTea* step1 = new IcedMilkTea();
    MilkTea* step2 = new Lemon(step1);
    step1 = nullptr;
    MilkTea* step3 = new Orange(step2);
    step2 = nullptr;
    std::cout << "The price is " << step3->getPrice() << ".\n" << std::endl;
    std::cout << step3->ingredientsList() << std::endl;
    delete step3;

    return 0;
}
