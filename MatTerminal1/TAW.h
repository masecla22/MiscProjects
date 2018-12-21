#pragma once
#include <iostream>
#include <mattcore.h>
#include <sstream>
#include <utility>
#include <vector>
#include <string>
#include "globals.h"
using namespace std;
string customCin(){
    string a;
    int length=0;
    while(true){
        int f = _getch();
        if(f==13){
            if(a.size()==0)
                return errorCode;
            cout<<endl;
            break;
        }
        if(f!=8)
            cout<<char(f);
        a.push_back(f);
        if(f==8){
            if(length!=0){
            cout<<"\b  \b\b";
            length--;
            a=a.substr(0,a.size()-2);
            }
        }
        else
            length++;

    }
    return a;
}
bool fexists(string filename) {
  std::ifstream ifile(filename);
  bool fmss = bool(ifile);
  ifile.close();
  return fmss;
}
bool dirExists(const std::string& dirName_in)
{
  DWORD ftyp = GetFileAttributesA(dirName_in.c_str());
  if (ftyp == INVALID_FILE_ATTRIBUTES)
    return false;  //something is wrong with your path!

  if (ftyp & FILE_ATTRIBUTE_DIRECTORY)
    return true;   // this is a directory!

  return false;    // this is not a directory!
}
string ExePath() {
    char buffer[MAX_PATH];
    GetModuleFileName( NULL, buffer, MAX_PATH );
    string::size_type pos = string( buffer ).find_last_of( "\\/" );
    return string( buffer ).substr( 0, pos);
}
string getCommand(string command){
    int pos=-1;
    for(unsigned int i=0;i<command.length()-1;i++)
        if(command.at(i)==' ')
            {pos=i;break;}
    return (pos==-1)?command:command.substr(0,pos);
}
int getNotLastSlash(string a)
{
    int trus=0;
    for(unsigned int i=a.size()-1;i>=0;i--)
        if(a.at(i)=='\\'){
            if(trus==0)
                trus=1;
            else
                return i;
        }
    return -1;
}
vector<string> explode(string const & s, char delim){
    vector<string> result;
    istringstream iss(s);
    for (string token;getline(iss, token, delim);){
        result.push_back(move(token));
    }

    return result;
}
string getArgs(string command,int which){
    return explode(command,' ').at(which);
}
int howManyArgs(string command){
    return explode(command,' ').size();
}
string errorMessage(int expected, int recieved)
{
    return "Wrong amount of args! Expected: "+to_string(expected)+" Recieved: "+to_string(recieved);
}
string charset="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
int charToNum(char a){
    switch(a)
    {
    case '1':
        return 1;
        break;
    case '2':
        return 2;
        break;
    case '3':
        return 3;
        break;
    case '4':
        return 4;
        break;
    case '5':
        return 5;
        break;
    case '6':
        return 6;
        break;
    case '7':
        return 7;
        break;
    case '8':
        return 8;
        break;
    case '9':
        return 9;
        break;
    case '0':
        return 0;
        break;
    default:
        return -1;
        break;
    }
}
void encrypt1(std::string &a){
    for(unsigned int i=0; i<a.size(); i++)
        a.at(i)++;
}
void decrypt1(std::string &a){
    for(unsigned int i=0; i<a.size(); i++)
        a.at(i)--;
}
void encrypt2(std::string &a){
    std::reverse(a.begin(),a.end());
}
void decrypt2(std::string &a){
    std::reverse(a.begin(),a.end());
}
void encrypt3(std::string &a){
    for(unsigned int i=0; i<a.size()-2; i+=2)
        swap(a.at(i),a.at(i+1));
}
void decrypt3(std::string &a){
    for(unsigned int i=0; i<a.size()-2; i+=2)
        swap(a.at(i),a.at(i+1));
}
void encrypt4(std::string &a,const std::string &key){
    for(unsigned int i=0; i<a.size(); i++)
        a.at(i)+=key.at(i%key.length());
}
void decrypt4(std::string &a,const std::string &key){
    for(unsigned int i=0; i<a.size(); i++)
        a.at(i)-=key.at(i%key.length());
}
void encrypt5(std::string &a){
    for(unsigned int i=0; i<a.size(); i++)
        a.at(i)+=i;
}
void decrypt5(std::string &a){
    for(unsigned int i=0; i<a.size(); i++)
        a.at(i)-=i;
}
void encrypt6(std::string &a){
    string b;
    for(unsigned int i=0; i<a.size(); i++)
    {
        b.push_back(a.at(i));
        b.push_back(charset.at(matt::core::random(0,charset.size()-1)));
    }
    a=b;
}
void decrypt6(std::string &a){
    string b;
    for(unsigned int i=0; i<a.size(); i+=2)
        b.push_back(a.at(i));
    a=b;
}
void doEncrypt(std::string &a,const std::string &key){
    for(auto&zz:key){
        switch(zz){
        case '1':
            encrypt1(a);
            break;
        case '2':
            encrypt2(a);
            break;
        case '3':
            encrypt3(a);
            break;
        case '4':
            encrypt4(a,key);
            break;
        case '5':
            encrypt5(a);
            break;
        case '6':
            encrypt6(a);
            break;
        }
    }
}
void doDecrypt(std::string &a,const std::string &key){
    std::string key1 = key;
    encrypt2(key1);
    for(auto&zz:key1){
        switch(zz){
        case '1':
            decrypt1(a);
            break;
        case '2':
            decrypt2(a);
            break;
        case '3':
            decrypt3(a);
            break;
        case '4':
            decrypt4(a,key);
            break;
        case '5':
            decrypt5(a);
            break;
        case '6':
            decrypt6(a);
            break;
        }
    }
}
void getNextKey(std::string &a){
    int sizes = a.size()-1;
    a.at(0)++;
    for(int i=0;i<sizes;i++){
        if(a.at(i)=='7'){
            a.at(i)='1';a.at(i+1)++;
        }
    }
    if(a.at(sizes)=='7'){
        a.push_back('1');
        for(int i=0;i<sizes+1;i++)
            a.at(i)='1';
    }
}
