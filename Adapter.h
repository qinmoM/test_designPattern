#pragma once

#include <string>


// class adapter
# if 0
class PNGProcessor
{
public:
    virtual ~PNGProcessor() = default;

public:
    virtual std::string processPNG()
    {
        return "PNG image";
    }

};

class JPGProcessor
{
public:
    virtual ~JPGProcessor() = default;

public:
    virtual std::string processJPG()
    {
        return "JPG image";
    }

};

class AdapterJPG : public PNGProcessor, public JPGProcessor
{
public:
    std::string processPNG() override
    {
        return "PNG image from JPG image";
    }

};
# endif




// object adapter
class Image
{
public:
    virtual ~Image() = default;

public:
    // The format of the image is png.
    virtual std::string getImage() = 0;

};

class Processor_ImagePNG
{
public:
    Processor_ImagePNG(std::string path)
        : path(path)
    { }

    ~Processor_ImagePNG() = default;

public:
    std::string getImage()
    {
        return path + " is PNG format.";
    }

protected:
    std::string path;

};

class Processor_ImageJPG
{
public:
    Processor_ImageJPG(std::string path)
        : path(path)
    { }

    ~Processor_ImageJPG() = default;

public:
    std::string getImage()
    {
        return path + " to be PNG format.";
    }

protected:
    std::string path;

};

class AdapterPNG : public Image
{
public:
    AdapterPNG(std::string path)
        : processor(new Processor_ImagePNG(path))
    { }

    ~AdapterPNG()
    {
        delete processor;
    }

public:
    std::string getImage() override
    {
        return processor->getImage();
    }

protected:
    Processor_ImagePNG* processor;

};

class AdapterJPG : public Image
{
public:
    AdapterJPG(std::string path)
        : processor(new Processor_ImageJPG(path))
    { }

    ~AdapterJPG()
    {
        delete processor;
    }

public:
    std::string getImage() override
    {
        // convert the image to png format
        std::string toPNG = processor->getImage() + "It is PNG format now.";
        return toPNG;
    }

protected:
    Processor_ImageJPG* processor;

};
