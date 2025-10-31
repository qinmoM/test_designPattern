#pragma once

#include <list>

class FlyweightBike
{
public:
    virtual ~FlyweightBike() = default;

public:
    virtual void apply() = 0;

    virtual void back() = 0;

    virtual bool isUse() = 0;

protected:
    int id;
    bool inUse;

};

class Yellow : public FlyweightBike
{
public:
    Yellow(int id)
    {
        FlyweightBike::id = id;
    }

public:
    void apply() override
    {
        FlyweightBike::inUse = true;
    }

    void back() override
    {
        FlyweightBike::inUse = false;
    }

    bool isUse() override
    {
        return FlyweightBike::inUse;
    }

};

class Factory
{
public:
    Factory(int count)
        : id_(0)
    {
        while (id_ < count)
        {
            list_.push_front(new Yellow(id_++));
        }
    }

    ~Factory()
    {
        for (FlyweightBike* temp : list_)
        {
            delete temp;
        }
    }

public:
    FlyweightBike* apply()
    {
        for (std::list<FlyweightBike*>::iterator it = list_.begin(); it != list_.end(); ++it)
        {
            if (!(*it)->isUse())
            {
                (*it)->apply();
                return (*it);
            }
        }
        return nullptr;
    }

    void back(FlyweightBike*& bike)
    {
        bike->back();
        bike = nullptr;
    }

protected:
    std::list<FlyweightBike*> list_;
    int id_;

};
