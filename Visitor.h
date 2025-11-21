#pragma once

#include <iostream>
#include <string>
#include <memory>

class Element;
class Shop;
class Community;

class Visitor
{
public:
    virtual ~Visitor() = default;

    virtual void serveShop(Shop& shop) = 0;
    virtual void serveCommunity(Community& community) = 0;
};

class Cleaner : public Visitor
{
public:
    void serveShop(Shop& shop) override;
    void serveCommunity(Community& community) override;
};

class Repairman : public Visitor
{
public:
    void serveShop(Shop& shop) override;
    void serveCommunity(Community& community) override;
};

class Element
{
public:
    Element(const std::string& s) : name_(s) { }
    virtual ~Element() = default;

    std::string getName()
    {
        return name_;
    }

    virtual void accept(std::shared_ptr<Visitor> visitor) = 0;
protected:
    std::string name_;
};

class Shop : public Element
{
public:
    Shop(const std::string& s) : Element(s) { }

    void accept(std::shared_ptr<Visitor> visitor) override
    {
        visitor->serveShop(*this);
    }
};

class Community : public Element
{
public:
    Community(const std::string& s) : Element(s) { }

    void accept(std::shared_ptr<Visitor> visitor) override
    {
        visitor->serveCommunity(*this);
    }
};

void Cleaner::serveShop(Shop& shop)
{
    std::cout << "Cleaning the " << shop.getName() << " shop." << std::endl;
}

void Cleaner::serveCommunity(Community& community)
{
    std::cout << "Cleaning the " << community.getName() << " community." << std::endl;
}

void Repairman::serveShop(Shop& shop)
{
    std::cout << "Repairing the " << shop.getName() << " shop." << std::endl;
}

void Repairman::serveCommunity(Community& community)
{
    std::cout << "Repairing the " << community.getName() << " community." << std::endl;
}
