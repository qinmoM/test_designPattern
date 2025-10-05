#pragma once

#include <iostream>

class HDD
{
public:
    virtual void size() = 0;

    virtual ~HDD() { }
};

class LowHDD : public HDD
{
public:
    void size()
    {
        std::cout << "HDD is 128GB" << std::endl;
    }
};

class HighHDD : public HDD
{
public:
    void size()
    {
        std::cout << "HDD is 1TB" << std::endl;
    }
};

class RAM
{
public:
    virtual void size() = 0;

    virtual ~RAM() { }
};

class LowRAM : public RAM
{
public:
    void size()
    {
        std::cout << "RAM is 4GB" << std::endl;
    }
};

class HighRAM : public RAM
{
public:
    void size()
    {
        std::cout << "RAM is 16GB" << std::endl;
    }
};

class Computer
{
public:
    Computer(HDD* hdd, RAM* ram) 
        : hdd_(hdd)
        , ram_(ram)
    { }

    ~Computer()
    {
        delete hdd_;
        delete ram_;
    }

    void display()
    {
        hdd_->size();
        ram_->size();
    }

protected:
    HDD* hdd_;
    RAM* ram_;
};

class AbstractFactory
{
public:
    virtual Computer* createComputer() = 0;

    virtual ~AbstractFactory() { }
};

class BasicFactory : public AbstractFactory
{
    Computer* createComputer()
    {
        HDD* hdd = new LowHDD();
        RAM* ram = new LowRAM();
        return new Computer(hdd, ram);
    }
};

class StandardFactory : public AbstractFactory
{
public:
    Computer* createComputer()
    {
        HDD* hdd = new HighHDD();
        RAM* ram = new HighRAM();
        return new Computer(hdd, ram);
    }
};
