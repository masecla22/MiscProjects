#pragma once
#include "globals.h"
#include "classes.h"

std::string getRandomString() {
    int howMuch = matt::core::random(minSizeForGroup,maxSizeForGroup);
    std::string toReturn="";
    for(int i=0; i<howMuch; i++)
        toReturn+=charset.at(matt::core::random(0,charset.size()-1));
    return toReturn;
}
int countSubstring(const std::string& str, const std::string& sub)
{
    int count = 0;
    if (sub.length() == 0) return 0;
    for (size_t offset = str.find(sub); offset != std::string::npos;offset = str.find(sub, offset + sub.length()))
        ++count;
    return count;
}




