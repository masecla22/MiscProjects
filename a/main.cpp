#include <iostream>
#include "bit.h"
#include <vector>

class dynInt {
    std::vector<bit> a;
    dynInt(std::vector<bit> a1){a=a1;}

};




int main() {
    bit a(0);
    !a;
    std::cout<<a;


    return 0;
}
