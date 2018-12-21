#include <iostream>
#include <mattmark.h>
#include <mattgui.h>
#include <windows.h>
#include "TAW.h"
int main()
{
    /**
    std::string f="Hello World!";
    std::string fa="1111";
    doEncrypt(f,fa);
    cout<<f;
    */
    string key="1";
    while(key.size()!=5){
    std::string f="Lipps$[svph%";
    std::string aa=f;
    doDecrypt(aa,key);
    cout<<aa<<"   "<<key<<endl;
    getNextKey(key);
    }
    return 0;
}

