#pragma once

#include <string>

class Light;

class State
{
public:
    virtual ~State() = default;

public:
    virtual std::string getState() = 0;
    virtual void pressSwitch(Light* light) = 0;

};

class OnState : public State
{
public:
    void pressSwitch(Light* light) override;
    std::string getState() override;
};

class OffState : public State
{
public:
    void pressSwitch(Light* light) override;
    std::string getState() override;
};

class Light
{
public:
    Light()
    {
        state_ = new OffState();
    }

    ~Light()
    {
        delete state_;
    }

public:
    void pressSwitch()
    {
        state_->pressSwitch(this);
    }

    void setState(State* state)
    {
        delete state_;
        state_ = state;
    }

    std::string getState()
    {
        return state_->getState();
    }

private:
    State* state_;

};

void OnState::pressSwitch(Light* light)
{
    light->setState(new OffState());
}

std::string OnState::getState()
{
    return "on";
}

void OffState::pressSwitch(Light* light)
{
    light->setState(new OnState());
}

std::string OffState::getState()
{
    return "off";
}
