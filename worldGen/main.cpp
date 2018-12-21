#include <iostream>
#include <vector>
#include <fstream>


using namespace std;
string charSet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
string convTS(vector<int> theN)
{
    string name = "";
    for(int i=0; i<theN.size(); i++)
        name.push_back(charSet[theN[i]]);
    return name;
}
bool isOnlyA(string thingy)
{
    for(int i=0; i<thingy.size(); i++)
        if(thingy[i]!='A')
            return false;
    return true;
}
int main()
{
    int length = 0;
    cout<<"Cate litere sa aibe lumea: ";
    cin>>length;
    vector<int> theName;
    string filename;
    int contor=0;
    cout<<"In ce fisier le vrei: ";
    cin>>filename;
    ofstream fout(filename);
    for(int i=0; i<length; i++)
        theName.push_back(0);
    while(true)
    {
        if(isOnlyA(convTS(theName)) && contor!=0)
            break;
        theName.at(0)++;
        for(int i=0; i<length; i++)
        {
            if(theName.at(i)==charSet.size())
            {
                theName[i]=0;
                theName[i+1]++;
            }
        }
        fout<<convTS(theName)<<endl;
        contor++;
    }
    cout<<"Am generat "<<contor<<" lumi"<<endl;

    return 0;
}
