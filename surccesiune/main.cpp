#include <fstream>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>


using namespace std;
bool checkValidity(std::string s) {
    int ones = 0;
    int twos = 0;
    for(int i=0; i<s.size(); i++) {
        if(s[i]=='1')
            ones++;
        if(s[i]=='2')
            twos++;
    }
    if((ones+twos)%2==0) {
        return ones==twos;
    } else {
        return (ones-1)==twos;
    }
}
int getOnes(std::string s) {
    int ones = 0;
    for(int i=0; i<s.size(); i++) {
        if(s[i]=='1')
            ones++;
    }
    return ones;
}
int getTwos(std::string s) {
    int twos = 0;
    for(int i=0; i<s.size(); i++) {
        if(s[i]=='2')
            twos++;
    }
    return twos;
}
int doesXWin(std::string s) {
    int x[25] = {0,0,0,1,1,1,2,2,2,0,1,2,0,1,2,0,1,2,0,1,2,0,1,2};
    int y[25] = {0,1,2,0,1,2,0,1,2,0,0,0,1,1,1,2,2,2,0,1,2,2,1,0};

    for(int i=0; i<24; i++)
        if(s[x[i]+y[i]*3] == s[x[i+1]+y[i+1]*3]
                && s[x[i+2]+y[i+2]*3] == s[x[i+1]+y[i+1]*3]
                && s[x[i]+y[i]*3]=='1'
          )
            return true;
    return false;
}

int doesOWin(std::string s) {
    int x[25] = {0,0,0,1,1,1,2,2,2,0,1,2,0,1,2,0,1,2,0,1,2,0,1,2};
    int y[25] = {0,1,2,0,1,2,0,1,2,0,0,0,1,1,1,2,2,2,0,1,2,2,1,0};

    for(int i=0; i<24; i++)
        if(s[x[i]+y[i]*3] == s[x[i+1]+y[i+1]*3]
                && s[x[i+2]+y[i+2]*3] == s[x[i+1]+y[i+1]*3]
                && s[x[i]+y[i]*3]=='2'
          )
            return true;
    return false;
}
bool isDraw(std::string s) {
    for(int i=0;i<s.size();i++)
        if(s[i]=='0')
            return false;
    if(!(doesOWin(s) && doesXWin(s)))
        return true;
    return false;
}
/**
002112112

__O
XXO
XXO

*/

int main() {
    ifstream fin("output3.txt");
    //ofstream fout("output4.txt");
    int contX = 0,contO = 0,draws = 0;
    while(!fin.eof()) {
        std::string s;
        getline(fin,s);
        if(doesOWin(s))
            contO++;
        if(doesXWin(s))
            contX++;
        if(isDraw(s))
            draws++;

    }
    cout<<"Wins O "<<contO<<endl;
    cout<<"Wins X "<<contX<<endl;
    cout<<"Wins DRAW "<<draws<<endl;
}
