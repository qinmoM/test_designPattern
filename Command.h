#pragma once

#include <iostream>

class Light
{
public:
    void turnOn()
    {
        if (!light_)
        {
            std::cout << "turn on." << std::endl;
            light_ = !light_;
        }
        else
        {
            std::cout << "has been turn on." << std::endl;
        }
    }
    void turnOff()
    {
        if (light_)
        {
            std::cout << "turn off." << std::endl;
            light_ = !light_;
        }
        else
        {
            std::cout << "has been turn off." << std::endl;
        }
    }
private:
    bool light_ = false;
};

class Command
{
public:
    virtual ~Command() = default;

    virtual void execute(Light* light) = 0;
};

class CommandTurnOn : public Command
{
public:
    void execute(Light* light) override
    {
        light->turnOn();
    }
};

class CommandTurnOff : public Command
{
public:
    void execute(Light* light) override
    {
        light->turnOff();
    }
};

class Control
{
public:
    Control(Light* light) : light_(light) { }

    void switchover(Command* command)
    {
        current_ = command;
    }

    void execute()
    {
        if (current_)
        {
            current_->execute(light_);
        }
    }
private:
    Command* current_ = nullptr;
    Light* light_;
};
