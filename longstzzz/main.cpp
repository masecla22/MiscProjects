#include <iostream>
#include <algorithm>
#include <fstream>
#include <mattmark.h>
#include <mattcore.h>
#include <mattgui.h>
using namespace std;
using namespace matt::core;

int main()
{
    size_t f=matt::gui::gui("1/2/");
    if(f==0){
    matt::benchmark::clock a;
    ifstream fin("data.txt");
    vector<int> vals;
    int h;
    while(fin>>h)
        vals.push_back(h);
    a.start();
    sort(vals.begin(),vals.end());
    a.ends();
    cout<<a.durs<<endl;
    for(auto&a:vals)
        cout<<a<<" ";
    }
    if(f==1){
    ofstream f("data.txt");
    for(int i=0;i<1000;i++)
        if(random(1,100)>90)
            f<<endl;
        else
            f<<random(1,1000)<<" ";
    }
    return 0;
}
