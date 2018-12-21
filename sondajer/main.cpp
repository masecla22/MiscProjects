#include <iostream>
#include <fstream>
#include <windows.h>
#include <cstring>

using namespace std;

int main()
{
    int nres,crit;
    string crits[5];
    int pers[6];
    string title,nume;
    cout<<"Sondajer V1.0"<<endl;
    cout<<"\n\n\n\n\n\n\n\n"<<endl;
    cout<<"Care este numele sondajului?"<<endl;
    cin>>title;
    cout<<"Care este numele dumneavoastra?"<<endl;
    cin>>nume;
    cout<<"Care este numarul de subiecti?"<<endl;
    cin>>nres;
    cout<<"Clasificat in functie de cate criterii?"<<endl;
    cin>>crit;
    int i=0;
    while(i<crit)
    {
        cout<<"Care este criteriul numarul "<<i+1<<endl;
        cin>>crits[i];
        cin;
        cout<<"Din care cati "<<crits[i]<<endl;
        cin>>pers[i];
        cin;
        i++;
    }
    ofstream fout("rezult.out");
    fout<<"************************************"<<endl;
    fout<<"         "<<title<<endl;
    fout<<"             de "<<nume<<endl;
    fout<<"\n\n\n"<<endl;
    fout<<"Date cunoscute"<<endl;
    fout<<"\nNumar subiecti: "<<nres<<endl;
    fout<<"Din care:"<<endl;
    fout<<pers[0]<<" "<<crits[0]<<" adica "<<pers[0]/nres*100<<endl;
    if(crit>1)
        fout<<pers[1]<<" "<<crits[1]<<" adica "<<pers[1]/nres*100<<endl;
    if(crit>2)
        fout<<pers[2]<<" "<<crits[2]<<" adica "<<pers[2]/nres*100<<endl;
    if(crit>3)
        fout<<pers[3]<<" "<<crits[3]<<" adica "<<pers[3]/nres*100<<endl;
    if(crit>4)
        fout<<pers[4]<<" "<<crits[4]<<" adica "<<pers[4]/nres*100<<endl;
    fout<<"************************************"<<endl;

    return 0;
}
