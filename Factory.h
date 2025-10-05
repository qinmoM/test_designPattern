#pragma once

#include <iostream>

class Father
{
public:
    virtual void introduce() = 0;

    virtual ~Father() = default;
};

class Child1 : public Father
{
public:
    void introduce() override
    {
        std::cout << "I am a child1." << std::endl;
    }

};

class Child2 : public Father
{
public:
    void introduce() override
    {
        std::cout << "I am a child2." << std::endl;
    }
};



class SimpleFactory
{
public:
    virtual Father* create() = 0;

    virtual ~SimpleFactory() = default;
};

class Child1Factory : public SimpleFactory
{
public:
    Father* create() override
    {
        return new Child1();
    }
};

class Child2Factory : public SimpleFactory
{
public:
    Father* create() override
    {
        return new Child2();
    }
};
