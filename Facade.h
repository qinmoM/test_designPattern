#pragma once

#include <string>

class TV
{
public:
    std::string turnOn()
    {
        return "The TV is turned on.";
    }

};

class SpeakerBluetooth
{
public:
    std::string turnOn()
    {
        return "The bluetooth speaker is turned on.";
    }

};

class Housekeeper
{
public:
    std::string watchTV(TV* tv, SpeakerBluetooth* sb)
    {
        return tv->turnOn() + "\n" + sb->turnOn();
    }

};
