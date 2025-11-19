#pragma once

#include <iostream>
#include <memory>
#include <list>

class SubjectTemp;

class Observer
{
public:
    virtual ~Observer() = default;

    virtual void update(const SubjectTemp& subject) = 0;
};

class SubjectTemp
{
public:
    SubjectTemp(float temp) : temperature_(temp) { }
    ~SubjectTemp() = default;

    float getTemp() const
    {
        return temperature_;
    }

    void setTemp(float temp)
    {
        temperature_ = temp;
        notify();
    }

    void push(std::shared_ptr<Observer> obs)
    {
        registerObserver_.push_back(obs);
    }

private:
    void notify()
    {
        for (std::shared_ptr<Observer>& observer : registerObserver_)
        {
            observer->update(*this);
        }
    }

protected:
    std::list<std::shared_ptr<Observer>> registerObserver_;
    float temperature_;

};

class Phone : public Observer
{
public:
    Phone(int id) : id_(id) { }

    void update(const SubjectTemp& subject) override
    {
        std::cout << id_ << " phone : the temperature is " << subject.getTemp() << std::endl;
    }

protected:
    int id_;

};
