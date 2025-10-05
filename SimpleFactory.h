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

enum class ChildType : char
{
    Child1,
    Child2
};

class SimpleFactory
{
public:
    Father* create(ChildType type)
    {
        switch(type)
        {
        case ChildType::Child1:
            return new Child1;
        case ChildType::Child2:
            return new Child2;
        default:
            return nullptr;
        }
    }
};
