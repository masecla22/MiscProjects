#pragma once
#include "mattcore.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;
namespace matt{namespace settings{
int lines(const string &a){
    int number_of_lines = 0;
    string line;
    ifstream myfile(a);
    while (getline(myfile, line))
        ++number_of_lines;
    return number_of_lines;
}
void newSetting(const string &file,const string &name,const int &value){
    ofstream fout(file,ios::app);
    fout<<name<<" : "<<value<<endl;
}
int getValue(string file, string name){
    string key;char separator;int value;
    ifstream fin(file);
    while (fin>>key>>separator>>value)
        if (key==name)
            return value;
    return 0;
}
int getLine(string file,string a){
    string name;int aux;
    ifstream fin(file);
    for(int i=0; i<lines(file); i++){
        getline(cin,name);
        for(int j=0; j<name.length(); j++)
            if(name.at(j)==':')
                name.at(j-1)='\0';
        if(name==a)
            return i;
    }
}
void doValue(string &a,int value)
{
    for(size_t i=0;i<a.length();i++)
        if(a[i]==':')
            a[i--]='\0';
    string val=matt::core::stoa(value);
    a+=" : "+val;
}
void clFiles(string a)
{
    ofstream fin(a);
    fin.close();
}
int chgValue(string file,string name,int value){
    fstream fin(file,ios::app|ios::in|ios::out);
    vector<string> setts;
    int f=lines(file);
    while(!fin.eof()&&!fin.badbit){
        std::string buf;
        std::getline(fin, buf);
        setts.push_back(buf);
    }
    int a = getLine(file,name);
    doValue(setts[a],value);
    clFiles(file);
    ofstream fout(file,ios::app);
    for(int i=0; i<f; i++)
        fout<<setts[i]<<endl;
}
}
}
