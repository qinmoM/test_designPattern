#pragma once

#include <iostream>
#include <string>

class LoggerBase
{
public:
    LoggerBase()
        : next(nullptr)
    { }
    virtual ~LoggerBase() = default;
public:
    void setNext(LoggerBase* next)
    {
        this->next = next;
    }

    virtual void logMessage(const std::string& msg) = 0;

protected:
    LoggerBase* next;

};

class SmallLogger : public LoggerBase
{
public:
    void logMessage(const std::string& msg) override
    {
        if (msg.size() <= 5)
        {
            std::cout << "Small logger." << std::endl;
            return;
        }
        if (next != nullptr)
        {
            next->logMessage(msg);
        }
    }
};

class LargeLogger : public LoggerBase
{
public:
    void logMessage(const std::string& msg) override
    {
        std::cout << "Large logger." << std::endl;
    }
};
