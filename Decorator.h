#pragma once

#include <string>

class MilkTea
{
public:
    virtual ~MilkTea() = default;

public:
    virtual int getPrice() = 0;

    virtual std::string ingredientsList() = 0;

};

class IcedMilkTea : public MilkTea
{
public:
    virtual ~IcedMilkTea() = default;

public:
    virtual int getPrice() override
    {
        return 5;
    }

    virtual std::string ingredientsList() override
    {
        return "Ingredients list of Iced Milk Tea:\n - Ice\n - Milk\n - Tea\n";
    }

};

class HotMilkTea : public MilkTea
{
public:
    virtual ~HotMilkTea() = default;

public:
    virtual int getPrice() override
    {
        return 5;
    }

    virtual std::string ingredientsList() override
    {
        return "Ingredients list of Hot Milk Tea:\n - Milk\n - Tea\n";
    }

};

class MilkTeaDecorator : public MilkTea
{
public:
    MilkTeaDecorator(MilkTea* body)
        : body(body)
    { }

    virtual ~MilkTeaDecorator()
    {
        delete body;
    }

public:
    virtual int getPrice() override
    {
        return body->getPrice();
    }

    virtual std::string ingredientsList() override
    {
        return body->ingredientsList();
    }

protected:
    MilkTea* body;

};

class Orange : public MilkTeaDecorator
{
public:
    Orange(MilkTea* body)
        : MilkTeaDecorator(body)
    { }

public:
    int getPrice() override
    {
        return money + MilkTeaDecorator::getPrice();
    }

    std::string ingredientsList() override
    {
        return MilkTeaDecorator::ingredientsList() + " - orange\n";
    }

protected:
    static constexpr int money = 1;

};

class Lemon : public MilkTeaDecorator
{
public:
    Lemon(MilkTea* body)
        : MilkTeaDecorator(body)
    { }

public:
    int getPrice() override
    {
        return money + MilkTeaDecorator::getPrice();
    }

    std::string ingredientsList() override
    {
        return MilkTeaDecorator::ingredientsList() + " - Lemon\n";
    }

protected:
    static constexpr int money = 2;

};
