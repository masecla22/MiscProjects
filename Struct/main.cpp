#include <iostream>

using namespace std;
struct car {
int color;
int sizes;
string brand;
int showInfo()
{
    cout<<"COLOR: "<<color<<endl;
    cout<<"BRAND: "<<brand<<endl;
    cout<<"SIZE: "<<sizes<<endl;
}

};
int main()
{
    car myCar;
    myCar.color=3;
    myCar.brand="TMH";
    myCar.sizes=30;
    myCar.showInfo();

    return 0;
}
