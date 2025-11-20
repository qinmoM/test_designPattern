#include <iostream>
#include <memory>
// #include "SingletonPattern.h"
// #include "SimpleFactory.h"
// #include "Factory.h"
// #include "AbstractFactory.h"
// #include "Builder.h"
// #include "Prototype.h"
// #include "Adapter.h"
// #include "Bridge.h"
// #include "Facade.h"
// #include "Decorator.h"
// #include "Proxy.h"
// #include "Composite.h"
// #include "Flyweight.h"
// #include "ChainResponsibility.h"
// #include "State.h"
// #include "Observer.h"
#include "Memento.h"

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
    // MilkTea* step1 = new IcedMilkTea();
    // MilkTea* step2 = new Lemon(step1);
    // step1 = nullptr;
    // MilkTea* step3 = new Orange(step2);
    // step2 = nullptr;
    // std::cout << "The price is " << step3->getPrice() << ".\n" << std::endl;
    // std::cout << step3->ingredientsList() << std::endl;
    // delete step3;

    // Proxy
    // ProxyImage* proxy = new ProxyImage("jenny");
	// proxy->loadImage("jenny", "D:/download/0.png");
	// std::cout << proxy->render("join") << std::endl;
	// std::cout << proxy->render("jenny") << std::endl;
	// delete proxy;

    // Composite
    // Component* file1 = new File("10001.png", 12);
	// Component* file2 = new File("11.wav", 1476);
	// Component* folder = new Folder("res");
	// folder->add(file1);
	// folder->add(file2);
	// std::cout << folder->getSize() << std::endl;
	// folder->remove(file1);
	// folder->remove(file2);
	// std::cout << folder->getSize() << std::endl;
	// delete file1;
	// delete file2;
	// delete folder;

    // Flyweight
    // Factory* fact = new Factory(2);
    // for (int i = 0; i < 3; ++i)
    // {
    //     FlyweightBike* temp = fact->apply();
    //     if(temp)
    //     {
    //         std::cout << i << " application is successful.";
    //     }
    //     else
    //     {
    //         std::cout << i << " application isn't successful.";
    //     }
    //     std::cout << std::endl;
    // }
    // delete fact;

    // chain of responsibility
    // LoggerBase* base = new SmallLogger();
    // LoggerBase* large = new LargeLogger();
    // base->setNext(large);
    // base->logMessage("");
    // base->logMessage("hhhhhhhhhhhhhhhhhhhhhhhh");
    // delete large;
    // delete base;

    // state
    // Light* light = new Light();
    // std::cout << light->getState() << std::endl;
    // light->pressSwitch();
    // std::cout << light->getState() << std::endl;

    // observer
    // std::shared_ptr<SubjectTemp> station = std::make_shared<SubjectTemp>(28.0f);
    // std::shared_ptr<Phone> phoneA = std::make_shared<Phone>(1);
    // std::shared_ptr<Phone> phoneB = std::make_shared<Phone>(2);
    // station->push(phoneA);
    // station->push(phoneB);
    // station->setTemp(22.5f);
    // station->setTemp(20.5f);

    // memento
    std::unique_ptr<TextEditor> editor = std::make_unique<TextEditor>("1234");
    editor->save();
    editor->setText(editor->getText() + "56");
    std::cout << editor->getText() << std::endl;
    editor->undo();
    std::cout << editor->getText() << std::endl;

    return 0;
}
