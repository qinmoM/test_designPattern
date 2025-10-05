#pragma once

#include <string>

class Computer
{
protected:
    std::string m_cpu;
    std::string m_memory;
    std::string m_disk;

public:
    void setCpu(const std::string& cpu)
    {
        m_cpu = cpu;
    }

    void setMemory(const std::string& memory)
    {
        m_memory = memory;
    }

    void setDisk(const std::string& disk)
    {
        m_disk = disk;
    }

    std::string display()
    {
        return "CPU: " + m_cpu + "\nMemory: " + m_memory + "\nDisk: " + m_disk;
    }

};

class Builder
{
public:
    virtual void builderCpu() = 0;
    virtual void builderMemory() = 0;
    virtual void builderDisk() = 0;
    virtual void reset() = 0;
    virtual Computer* getComputer() = 0;

    virtual ~Builder() = default;

protected:
    Computer* m_computer;

};

class OfficeBuilder : public Builder
{
public:
    void builderCpu() override
    {
        m_computer->setCpu("i5-12490F");
    }

    void builderMemory() override
    {
        m_computer->setMemory("16GB");
    }

    void builderDisk() override
    {
        m_computer->setDisk("512GB");
    }

    void reset() override
    {
        m_computer = new Computer();
    }

    Computer* getComputer() override
    {
        Computer* computer = m_computer;
        m_computer = nullptr;
        return computer;
    }

    ~OfficeBuilder() override
    {
        delete m_computer;
    }

};

class GameBuilder : public Builder
{
public:
    void builderCpu() override
    {
        m_computer->setCpu("9800x3D");
    }

    void builderMemory() override
    {
        m_computer->setMemory("32GB");
    }

    void builderDisk() override
    {
        m_computer->setDisk("2TB");
    }

    void reset() override
    {
        m_computer = new Computer();
    }

    Computer* getComputer() override
    {
        Computer* computer = m_computer;
        m_computer = nullptr;
        return computer;
    }

    ~GameBuilder() override
    {
        delete m_computer;
    }

};

class Director
{
public:
    Computer* construct(Builder* builder)
    {
        builder->reset();
        builder->builderCpu();
        builder->builderMemory();
        builder->builderDisk();
        return builder->getComputer();
    }
};
