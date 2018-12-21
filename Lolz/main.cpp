#include <iostream>
#include <fstream>
#include "mattgui.h"

using namespace std;
double abs(double a)
{
    if(a<0)
        return a*-1;
    return a;
}
double getProc(double a,double b)
{
    int p=100;
    p*=(b-a);
    p/=a;
    return p;
}
double lines()
{
    ifstream fin("data.in");
    double howmany=0;
    double aux;
    while(fin>>aux)
        howmany++;
    return howmany;
}
double getAvg()
{
    double n[255];
    double sum=0;
    double percs[255];
    for(int i=1; i<lines(); i++)
        percs[(i-1)]=getProc(n[(i-1)],n[i]);
    for(int i=0; i<(lines()-1); i++)
        sum+=percs[i];
    sum/=(lines()-1);
    return sum;

}
void feedData(double a)
{
    ofstream fout("data.in",ios::app);
    fout<<a<<endl;
}
double getLValue()
{
    double n;
    ifstream fin("data.in");
    while(fin>>n)
        double f;
    return n;

}
int main()
{
    ///GUI!
init:
    double guis=gui("Set Initial Value/Feed Data/Predictions/");
    if(guis==0)
    {
        cout<<"BE AWARE THAT THIS WILL WIPE ALL MY DATA SO FAR!"<<endl;
        Sleep(2000);
        system("cls");
        cout<<"WOULD YOU LIKE TO CONTINUE?\nPress a key."<<endl;
        getch();
        system("cls");
        double gui1=gui("Yes/No/");
        if(gui1==0)
        {
            ofstream fout("data.in");
            double a;
            cout<<"Input a new beggining data: ";
            cin>>a;
            fout<<a<<endl;
            cout<<"Got it!"<<endl;
            Sleep(1000);
            system("cls");
            goto init;
        }
        else
        {
            system("cls");
            goto init;
        }
    }
    if(guis==1)
    {
        cout<<"Here is your last value added: "<<getLValue();
        cout<<"\nWhat is the next one? (type -1 if you came here by mistake)"<<endl;
        double a;
        cin>>a;
        if(a==-1)
        {
            system("cls");
            goto init;
        }
        else
        {
            feedData(a);
            cout<<"Got it!"<<endl;
            Sleep(1000);
            system("cls");
            goto init;
        }
    }
    if(guis==2)
    {
        if(lines()<3)
            cout<<"Sorry! I don't have enough data to make accurate predictions!"<<endl;
        else
        {
            cout<<"Based on "<<lines()<<" pieces of data I can calculate this:"<<endl;
            double a=getLValue();
            cout<<"In the 1st collection it will go from "<<a<<" to "<<a+getProc(a,getAvg())<<endl;
            a+=getProc(a,getAvg());
            cout<<"In the 2nd collection it will go from "<<a<<" to "<<a+getProc(a,getAvg())<<endl;
            a+=getProc(a,getAvg());
            cout<<"In the 3rd collection it will go from "<<a<<" to "<<a+getProc(a,getAvg())<<endl;
            a+=getProc(a,getAvg());
            cout<<"Growing everytime by "<<getAvg()<<"% every generation!"<<endl;
            cout<<"Press any key to return to the mian menu..."<<endl;
            getch();
            system("cls");
            goto init;
        }
    }
    return 0;
}
