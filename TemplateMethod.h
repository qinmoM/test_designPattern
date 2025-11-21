#pragma once

#include <iostream>

class AbstractClass
{
public:
    virtual ~AbstractClass() = default;

    virtual void templateMethod() final
    {
        step1();
        step2();
        step3();
    }
protected:
    void step1()
    {
        std::cout << "father class : Fixed step1." << std::endl;
    }

    void step3()
    {
        std::cout << "father class : Fixed step3." << std::endl;
    }

    virtual void step2() = 0;
};

class Component : public AbstractClass
{
protected:
    void step2()
    {
        std::cout << "variable step2." << std::endl;
    }
};
