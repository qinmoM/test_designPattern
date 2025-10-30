#pragma once

#include <string>
#include <vector>

class Component
{
public:
	virtual ~Component() = default;

public:
	virtual std::string getName() = 0;
	virtual int getSize() = 0;
	
	virtual void add(Component* com) = 0;
	virtual void remove(Component* com) = 0;

};

class Folder : public Component
{
public:
	Folder(const std::string& n)
		: name_(n)
		, size_(0)
	{ }
	
public:
	std::string getName() override
	{
		return name_;
	}
	
	int getSize() override
	{
		return size_;
	}

	void add(Component* com) override
	{
		for (auto temp : vec)
		{
			if (temp->getName() == com->getName())
			{
				throw "the name cannot be duplicate.";
			}
		}
		vec.push_back(com);
		size_ += com->getSize();
	}

	void remove(Component* com) override
	{
		for (int i = 0; i < vec.size(); ++i)
		{
			if (com->getName() == vec[i]->getName())
			{
				size_ -= vec[i]->getSize();
				vec.erase(vec.begin() + i);
			}
		}
	}

protected:
	std::string name_;
	int size_;
	std::vector<Component*> vec;

};

class File : public Component
{
public:
	File(const std::string& n, int size)
		: name_(n)
		, size_(size)
	{ }
	
public:
	std::string getName() override
	{
		return name_;
	}
	
	int getSize() override
	{
		return size_;
	}

	void add(Component* com) override
	{
		throw "is not folder!";
	}

	void remove(Component* com) override
	{
		throw "is not folder!";
	}
	
protected:
	std::string name_;
	int size_;

};