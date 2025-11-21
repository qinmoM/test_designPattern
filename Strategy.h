#pragma once

#include <iostream>
#include <memory>

class Strategy
{
public:
    virtual ~Strategy() = default;

    virtual void pay(double amount) = 0;
};

class AlipayStrategy : public Strategy
{
public:
    void pay(double amount) override
    {
        std::cout << "alipay : " << amount << std::endl;
    }
};

class WechatStrategy : public Strategy
{
    void pay(double amount) override
    {
        std::cout << "wechat : " << amount << std::endl;
    }
};

class Order
{
public:
    void setStrategy(std::unique_ptr<Strategy> p)
    {
        strategy_ = std::move(p);
    }

    void pay(double amount)
    {
        if (nullptr != strategy_)
        {
            strategy_->pay(amount);
        }
        else
        {
            std::cout << "Choose your payment method." << std::endl;
        }
    }

private:
    std::unique_ptr<Strategy> strategy_;
};
