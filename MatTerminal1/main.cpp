#include <iostream>
#include <sstream>
#include <utility>
#include <vector>
#include <string>
#include <algorithm>
#include "TAW.h"
#include "globals.h"
using namespace std;

class caller{
public:
    bool isConsole;
    string fileCall;
    caller(bool isConsole1=1,string fileCall1=notFile){
        isConsole=isConsole1;
        fileCall=fileCall1;
    }
};
bool interpret(string a,caller file){
    int ok=1;
    string command=getCommand(a);
    if(a==errorCode)
        cout<<"Command not found! You most likely mistyped me.";
    else if (command=="sleep"||command=="delay"){
        if(howManyArgs(a)!=2)
            cout<<errorMessage(1,howManyArgs(a)-1);
        else
            Sleep(stoi(getArgs(a,1)));
    }
    else if (command=="parity"){
        if(howManyArgs(a)!=2)
            cout<<errorMessage(1,howManyArgs(a)-1);
        else
            (stoi(getArgs(a,1))%2)?cout<<"The number is odd."<<endl:cout<<"The number is even."<<endl;
        return true;
    }
    else if(command=="cls"||command=="clear"){
        if(howManyArgs(a)!=1)
            cout<<errorMessage(0,howManyArgs(a)-1);
        else
            system("cls");
    }
    else if(command=="cd"){
        if(howManyArgs(a)!=2)
            cout<<errorMessage(1,howManyArgs(a)-1);
        else{
            if(getArgs(a,1)=="..")
                if(path!="C:\\"){
                    path = path.substr(0,getNotLastSlash(path));
                    path+='\\';
                }
                else
                    cout<<"Whom in fuck do you want me to go?"<<endl;
            else if(getArgs(a,1)==".")
                path = "C:\\";
            else
                if(dirExists(path+getArgs(a,1)))
                    path+=getArgs(a,1)+"\\";
                else
                    cout<<"Whom in fuck do you want me to go?"<<endl;
        }
    }
    else if(command=="callerInfo"){
        if(howManyArgs(a)!=1)
            cout<<errorMessage(0,howManyArgs(a)-1);
        else{
            cout<<"CALLER INFO:\n\tisConsole: "<<file.isConsole<<"\n\tCaller: "<<file.fileCall<<endl;
        }
    }
    else if(command=="loadScript"){
        if(howManyArgs(a)!=2)
            cout<<errorMessage(1,howManyArgs(a)-1);
        if(file.fileCall==getArgs(a,1)){
            cout<<"File cannot call itself!"<<endl;
            return 1;
        }
        else if(!fexists(path+'\\'+getArgs(a,1))){
            cout<<"File doesn't exist!\n"<<path+'\\'+getArgs(a,1)<<endl;
        }
        else{
            string line;ifstream fin(path+'\\'+getArgs(a,1));
            while(!fin.eof()){
                getline(fin,line);
                interpret(line,caller(false,getArgs(a,1)));
            }
        }
    }
    else if(command=="encryptMe"){
        if(howManyArgs(a)!=3)
            cout<<errorMessage(2,howManyArgs(a)-1);
        else{
            string text = getArgs(a,1);
            string key = getArgs(a,2);
            doEncrypt(text,key);
            cout<<"\nYour result: "<<text<<endl;
            cout<<"Your key: "<<key<<endl<<endl;
        }
    }
    else if(command=="decryptMe"){
        if(howManyArgs(a)!=3)
            cout<<errorMessage(2,howManyArgs(a)-1);
        else{
            string text = getArgs(a,1);
            string key = getArgs(a,2);
            doDecrypt(text,key);
            cout<<"\nYour result: "<<text<<endl;
            cout<<"Your key: "<<key<<endl<<endl;
        }
    }
    else if(command=="palindrome"){
         if(howManyArgs(a)!=2)
            cout<<errorMessage(1,howManyArgs(a)-1);
        else{
            string f = getArgs(a,1);
            std::reverse(f.begin(),f.end());
            if(f==getArgs(a,1)){
                cout<<"That is a palindrome! "<<endl;
            }
            else{
                cout<<"That is not a palindrome!"<<endl;
            }
        }
    }
    else if(command=="isPrime"){
         if(howManyArgs(a)!=2)
            cout<<errorMessage(1,howManyArgs(a)-1);
        else{
            int param = stoi(getArgs(a,1));
            int ok=1;
            if(param%2!=0){
                for(int i=3;i<sqrt(param);i+=2)
                        if(param%i==0){ok=0;break;}
            }
            else
                ok=0;
            if(ok==1)
                cout<<"Number is prime!"<<endl;
            else
                cout<<"Numebr is not prime!"<<endl;
        }
    }
    else
        ok=0;
    return ok;
}
int main(){
    path = "C:\\Users\\megatron\\Desktop";
    cout<<"MatTerminal "<<version<<endl;
    while(true){
        cout<<path<<"> ";
        string command = customCin();
        int i = interpret(command,caller());
        if(i==false){
            cout<<"Fug you want from me?"<<endl;
        }
        cout<<endl;
    }
    return 0;
}
