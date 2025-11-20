#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <string>

class Mediator
{
public:
    virtual ~Mediator() = default;

    virtual void send(int id, const std::string& s) = 0;
};

class User
{
public:
    virtual ~User() = default;

    User(int id, std::shared_ptr<Mediator> mediator) : id_(id), mediator_(mediator)
    {
        mediator_ = mediator;
    }

    int getID()
    {
        return id_;
    }

    virtual void send(const std::string& s) = 0;
    virtual void receive(int id, const std::string& s) = 0;

protected:
    std::weak_ptr<Mediator> mediator_;
    int id_;
};

class ChatRoom : public Mediator
{
public:
    void send(int id, const std::string& s) override
    {
        for (std::shared_ptr<User>& user : userList_)
        {
            if (user->getID() != id)
            {
                user->receive(id, s);
            }
        }
    }

    void add(std::shared_ptr<User>& user)
    {
        userList_.push_back(user);
    }

protected:
    std::vector<std::shared_ptr<User>> userList_;
};

class Colleague : public User
{
public:
    Colleague(int id, std::shared_ptr<Mediator> mediator) : User(id, mediator) { }

    void send(const std::string& s) override
    {
        if (auto temp = mediator_.lock())
        {
            temp->send(id_, s);
        }
    }

    void receive(int id, const std::string& s) override
    {
        std::cout << id_ << " : received message : " << s << "--from:" << id << std::endl;
    }
};
