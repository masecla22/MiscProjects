#include <fstream>
#include <iostream>
#include "mattcore.h"
#pragma once

const int DELIMITATOR_NOT_FOUND = 409;



class option
{
private:
    std::string name;
    std::string value;
    friend option parseFromString(std::string toParse);
public:
    std::string getName()
    {
        return name;
    }
    std::string getValue()
    {
        return value;
    }
    void setName(std::string name1)
    {
        name = name1;
    }
    void setValue(std::string value1)
    {
        value = value1;
    }
    std::string toString(){
        return name+" : "+value;
    }
};

option parseFromString(std::string toParse)
{
    option a;
    bool wasFound = false;
    std::string name = "",value = "";
    for(int i = 0; i < toParse.size(); i++)
    {
        if(wasFound)
            value+=toParse.at(i);
        else
            name+=toParse.at(i);
        if(toParse.at(i)==':')
            wasFound = true;
    }
    if(!wasFound)
    {
        throw DELIMITATOR_NOT_FOUND;
    }
    name = name.substr(0,name.size()-2);
    a.setName(name);
    a.setValue(value);
    return a;
}


namespace matt
{
namespace settings
{

}
}
