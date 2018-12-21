#include <iostream>

int main() {
    std::cout << "Enter Your Age: ";
    int iAge = 0;
    std::cin>>iAge;

    if ((iAge >= 1) && (iAge <= 18)){
        std::cout << "Your Birthday Is Important!!!\n";
    }else if (iAge == 21){
        std::cout << "Your Birthday Is Important!!!\n";
    }else if (iAge == 50){
        std::cout << "Your Birthday Is Important!!!\n";
    }else if (iAge >= 65){
        std::cout << "Your Birthday Is Important!!!\n";
    }else{
        std::cout << "Your Birthday Isn't Important LOL\n";
    }

    return 0;
}
