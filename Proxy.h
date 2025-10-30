#pragma once

#include <string>

class Image
{
public:
	virtual ~Image() = default;
	
public:
	virtual void loadImage(const std::string& user, const std::string& path) = 0;
	virtual std::string render(const std::string& user) = 0;
	
protected:
	std::string path_;

};

class RealImage : Image
{
public:
	void loadImage(const std::string& user, const std::string& path) override
	{
		Image::path_ = path;
	}
	
	std::string render(const std::string& user) override
	{
		return user + " render : " + Image::path_;
	}

};

class ProxyImage : Image
{
public:
	ProxyImage(const std::string s)
		: user_(s)
		, real_(new RealImage())
	{ }
	
	~ProxyImage()
	{
		delete real_;
	}

public:
	void loadImage(const std::string& user, const std::string& path) override
	{
		if (user_ == user)
		{
			return real_->loadImage(user_, path);
		}
		else
		{
			throw "is not manager!";
		}
	}
	
	std::string render(const std::string& user) override
	{
		if (user_ == user)
		{
			return real_->render(user_);
		}
		else
		{
			return "is not manager!";
		}
	}

protected:
	RealImage* real_;
	std::string user_;

};