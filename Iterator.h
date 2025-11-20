#pragma once

#include <string>

class Iterator
{
public:
    virtual ~Iterator() = default;

    virtual bool hasNext() = 0;
    virtual std::string next() = 0;
};

class List
{
public:
    struct Node
    {
        Node(const std::string& s) : s_(s), next_(nullptr) { }

        std::string s_;
        Node* next_;
    };

public:
    List()
    {
        head_ = new Node("");
        tail_ = head_;
    }

    void add(const std::string& s)
    {
        tail_->next_ = new Node(s);
        tail_ = tail_->next_;
    }

    Node* getHead()
    {
        return head_;
    }

private:
    Node* head_;
    Node* tail_;
};

class ListIterator : Iterator
{
public:
    ListIterator(List::Node* node) : node_(node) { }

    bool hasNext()
    {
        return node_->next_;
    }

    std::string next()
    {
        node_ = node_->next_;
        return node_->s_;
    }
private:
    List::Node* node_;
};
