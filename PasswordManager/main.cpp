#include <iostream>
#include <mattgui.h>


using namespace std;
using namespace matt::gui;
void asciiEntanglement(std::string &a,const std::string &key){
    for(unsigned int i=0; i<a.size(); i++)
        a.at(i)+=key.at(i%key.length());
}
void asciiDetanglement(std::string &a,const std::string &key){
    for(unsigned int i=0; i<a.size(); i++)
        a.at(i)-=key.at(i%key.length());
}
bool fexists(string filename) {
  std::ifstream ifile(filename);
  bool fmss = bool(ifile);
  ifile.close();
  return fmss;
}
string customCin(){
    string a;
    int length=0;
    while(true){
        int f = _getch();
        if(f==13){
            if(a.size()==0)
                return "EMTPY";
            cout<<endl;
            break;
        }
        if(f!=8)
            cout<<"*";
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
int main()
{
    string charset ="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890`~!@#$%^&*()-=[]\\;\'./,_+{}|:\"<>?";
    int opt = gui("Create a new password/List your passwords/Find a specific password");
    if(opt==0)
    {
        string forWhat;
        system("cls");
        cout<<"What do you need this password for: ";
        cin>>forWhat;
        string thePass,masterPass;
        cout<<"Your password is: (Type auto to get a stupidly random 50 char pass)";
        thePass = customCin();
        if(thePass == "auto"){
            string pass="";
            for(int i=0;i<50;i++)
                pass+=charset[matt::core::random(0,charset.size()-1)];
            thePass = pass;
        }
        cout<<"What is your master password: (if the password is incorrect you won't be able to decode it)";
        masterPass = customCin();
        system("cls");
        int isSure = gui("I am sure about this/No no no! Cancel everything!/");
        if(isSure == 1){
            asciiEntanglement(thePass,masterPass);
            cout<<"Your password has been added to the database!"<<endl;
        }else{
            system("cls");

        }
    }
    return 0;
}
