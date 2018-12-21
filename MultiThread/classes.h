#pragma once
#include <mattcore.h>
#include "functions.h"
#include "globals.h"



class botRule {
  public:
    std::string group;
    int multiplier;
    botRule(std::string group1,int multiplier1) {
        group = group1;
        multiplier = multiplier1;
    }
};




class Bot {
  public:
    std::vector<botRule> rules;
    int howManyRules;
    int succesRate;
    int probabilityRequired;
    Bot() {


    }
  private:

};
