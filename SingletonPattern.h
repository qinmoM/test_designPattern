#pragma once

#include <iostream>


class SingletonPattern
{
public:
    static SingletonPattern* GetInstance()
    {
        return m_task;
    }

    void print()
    {
        std::cout << "Singleton Pattern" << std::endl;
    }

    ~SingletonPattern() = delete;

public:
    SingletonPattern& operator=(const SingletonPattern& single) = delete;
    SingletonPattern(const SingletonPattern& single) = delete;

private:
    SingletonPattern() = default;

private:
    static SingletonPattern* m_task;

};
SingletonPattern* SingletonPattern::m_task = new SingletonPattern();



class SingletonPattern1
{
public:
    static SingletonPattern1* GetInstance()
    {
        static SingletonPattern1 task;
        return &task;
    }

    void print()
    {
        std::cout << "Singleton Pattern" << std::endl;
    }

    ~SingletonPattern1() { }

public:
    SingletonPattern1& operator=(const SingletonPattern1& single) = delete;
    SingletonPattern1(const SingletonPattern1& single) = delete;

private:
    SingletonPattern1() = default;

};
