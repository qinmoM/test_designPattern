#pragma once

#include <memory>
#include <string>
#include <sstream>
#include <vector>

class Expression
{
public:
    virtual ~Expression() = default;

    virtual int interpret() = 0;
};

class NumberExpression : public Expression
{
    int val_;
public:
    NumberExpression(int val) : val_(val) { }

    int interpret() override
    {
        return val_;
    }
};

class AddExpression : public Expression
{
    std::unique_ptr<Expression> a_;
    std::unique_ptr<Expression> b_;
public:
    AddExpression(std::unique_ptr<Expression> a, std::unique_ptr<Expression> b) : a_(std::move(a)), b_(std::move(b)) { }

    int interpret() override
    {
        return a_->interpret() + b_->interpret();
    }
};

std::unique_ptr<Expression> build(const std::string& expr)
{
    std::stringstream ss(expr);
    std::string temp;

    std::vector<int> vec;

    while (std::getline(ss, temp, '+'))
    {
        vec.push_back(std::stoi(temp));
    }

    std::unique_ptr<Expression> root = std::make_unique<NumberExpression>(vec[0]);

    for (size_t i = 1; i < vec.size(); ++i)
    {
        root = std::make_unique<AddExpression>(std::move(root), std::make_unique<NumberExpression>(vec[i]));
    }

    return root;
}
