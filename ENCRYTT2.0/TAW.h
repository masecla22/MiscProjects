#include <vector>
#include <iostream>
#include <algorithm>
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
    for(int i=0; i<a.size()-2; i+=2)
        swap(a.at(i),a.at(i+1));
}
void decrypt3(std::string &a){
    for(int i=0; i<a.size()-2; i+=2)
        swap(a.at(i),a.at(i+1));
}
void encrypt4(std::string &a,const std::string &key){
    for(int i=0; i<a.size(); i++)
        a.at(i)+=key.at(i%key.length());
}
void decrypt4(std::string &a,const std::string &key){
    for(int i=0; i<a.size(); i++)
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
    for(int i=0; i<a.size(); i++)
    {
        b.push_back(a.at(i));
        b.push_back(charset.at(matt::core::random(0,charset.size()-1)));
    }
    a=b;
}
void decrypt6(std::string &a){
    string b;
    for(int i=0; i<a.size(); i+=2)
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
