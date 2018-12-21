#include <iostream>

using namespace std;

int main() {
    int num;
    cin>>num;
    int ogl = num%10; ///1
    int copieNum = num/10;  ///32
    while(copieNum!=0) {
        ogl*=10;
        ogl+=copieNum%10;
        copieNum/=10;
    }



    bool numarulEstePrim = true;

    int i=3;
    if(num%2!=0) {
        while(i<num) {
            if(num%i==0)
                numarulEstePrim = false;
            i+=2;
        }
    } else {
        numarulEstePrim = false;
    }

    bool oglEsteP = true;
    i=3;
    if(ogl%2!=0) {
        while(i<ogl) {
            if(ogl%i==0)
                oglEsteP = false;
            i+=2;
        }
    } else {
        oglEsteP = false;
    }

    if(numarulEstePrim && oglEsteP) {
        cout<<"DA";
    } else {
        cout<<"NU";
    }



    return 0;
}
