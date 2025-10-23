#pragma once

#include <string>

class Character
{
public:
    virtual Character* clone() const = 0;
    virtual std::string display() const = 0;

    virtual ~Character() = default;

protected:
    unsigned int HP = 0;

};

class Minion : public Character
{
public:
    Minion()
    {
        HP = 200;
    }

    Minion(const Minion& other) = default;
    Minion& operator=(const Minion& other) = default;

    std::string display() const override
    {
        return "HP = " + std::to_string(HP);
    }

    Minion* clone() const override
    {
        return new Minion(*this);
    }

};

class Boss : public Character
{
public:
    Boss()
    {
        HP = 5000;
    }

    Boss(const Boss& other) = default;
    Boss& operator=(const Boss& other) = default;

    std::string display() const override
    {
        return "HP = " + std::to_string(HP);
    }

    Boss* clone() const override
    {
        return new Boss(*this);
    }

};
