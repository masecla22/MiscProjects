#include <iostream>
#include <cmath>

using namespace std;
/**
    <tip de date returnat> <nume functie>(<tip data 1> <identificator 1>,<tip data 2> <identificator 2>){
        cod

        return <valoare>;
    }
*/



int dubleaza(int x) {
    return x*2;
}

bool estePrim(int numar) {
    int i=3;
    if(numar%2==0 || numar==1)
        return false;
    while(i<sqrt(numar)) {
        if(numar%i==0)
            return false;
        i+=2;
    }
    return true;
}



int main() {
    int a;
    cin>>a;
    if(estePrim(a)==true)
        cout<<"a e prim";


    return 0;
}
