#pragma once

#include <string>

class Color
{
public:
    virtual ~Color() = default;

public:
    virtual std::string getColor() = 0;

};

class Red : public Color
{
public:
    std::string getColor() override
    {
        return "Red";
    }

};

class Green : public Color
{
public:
    std::string getColor() override
    {
        return "Green";
    }

};

class Shape
{
public:
    virtual ~Shape() = default;

public:
    virtual std::string getShape() = 0;

};

class Circle : public Shape
{
public:
    std::string getShape() override
    {
        return "Circle";
    }

};

class Body
{
public:
    Body(Color* color, Shape* shape)
        : color(color)
        , shape(shape)
    { }

    virtual ~Body()
    {
        delete color;
        delete shape;
    }

public:
    std::string display()
    {
        return "Color : " + color->getColor() + "   Shape : " + shape->getShape();
    }

protected:
    Color* color;
    Shape* shape;

};
