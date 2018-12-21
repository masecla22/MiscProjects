#include <stdio.h>
#include <string.h>
#include <iostream>
#include <mattcore.h>
#include <bits/stdc++.h>
using namespace std;
unsigned long hashcode = 0x21DD09EC;
unsigned long check_password(const char* p){
        int* ip = (int*)p;
        int i;
        int res=0;
        for(i=0; i<5; i++){
                res += ip[i];
        }
        return res;
}
void gen_random(char *s, const int len) {
    static const char alphanum[] =
        "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < len; ++i) {
        s[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    s[len] = 0;
}
int main(int argc, char* argv[]){
    while(true)
    {
        char buffer[255];
        gen_random(buffer,5);
        cout<<buffer<<" "<<check_password(buffer)<<" "<<hashcode<<"  \r";
        matt::core::ShowConsoleCursor(false);
        if(abs(check_password(buffer)-hashcode)<20000)
            cout<<endl;

    }
        return 0;
}

