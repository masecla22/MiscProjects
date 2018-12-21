#include <iostream>
#include <windows.h>
#include <conio.h>
#define cls system("cls")
#include <cstdlib>
#include <cstdio>
#define echo cout
#include <ctime>
using namespace std;

int main()
{
            char results[255];
    int puncte = 0;
    cout<<"Buna!\n Care este numele tau de uitlizator?"<<endl;
    string name,pass;
    cin>>name;
    cout<<"Dar parola?"<<endl;
    cin>>pass;
    cls;
    if(name=="michele33" && pass=="marziali")
    {
        cout<<"\n\n\n\n\n\nTe rog sa astepti... Incarc toate exercitiile tale preferate"<<endl;
        Sleep(2000);
init:
        cls;
        cout<<"Acum ai "<<puncte<<" puncte"<<endl;
        cout<<"Scrie numarul exercitiului si apoi apasa pe ENTER"<<endl;
        cout<<"\n\n1 - Matematica"<<endl;



        int i;
        cin>>i;
        ///Matematica!
        if(i==1)
        {
            cls;
ex1:
            echo<<"\n\n\n\n             MATEMATICA!!!!\n\n";
            echo<<"\n";
            srand(time(NULL));
            int a = (rand()%20)+1;
            int b = (rand()%15)+1;
            int c = (rand()%100)+1;
            int result;
            echo<<"Pe moment ai "<<puncte<<" puncte"<<endl;
            echo<<"\nCare este raspunsul?\n\n!! Tine minte, daca raspunzi 99 atunci vei iesi din joculet...\n\n";
            if(c%2==0)
            {
                if(a>b)
                {
                    echo<<a<<"-"<<b<<"=";
                    cin.getline(results,255);
                    result = atoi(results);
                    if(result==99)
                    {
                        goto init;
                    }
                    else
                    {
                        if(result==(a-b))
                        {
                            cout<<"\n\nCORECT!!!"<<endl;
                            cout<<"Apasa pe SPACE pentru a continua...";
                            getch();
                            cls;
                            puncte++;
                            goto ex1;
                        }
                        else
                        {
                            cout<<"Offff... Gresit!! Incearca alta data... Rezultatul era "<<a-b<<" iar tu ai spus "<<result<<"!"<<endl;
                            cout<<"Apasa pe SPACE pentru a continua...";
                            getch();
                            cls;
                            if(puncte<5)
                            {
                                puncte = 0;
                            }
                            else
                                puncte-=5;
                            goto ex1;
                        }
                    }
                }
                else
                {
                    echo<<b<<"-"<<a<<"=";
                    cin.getline(results,255);
                    result = atoi(results);
                    if(result==99)
                    {
                        goto init;
                    }
                    else
                    {
                        if(result==(b-a))
                        {
                            cout<<"\n\nCORECT!!!"<<endl;
                            cout<<"Apasa pe SPACE pentru a continua...";
                            puncte++;
                            getch();
                            cls;
                            goto ex1;
                        }
                        else
                        {
                            cout<<"Offff... Gresit!! Incearca alta data... Rezultatul era "<<b-a<<" iar tu ai spus "<<result<<"!"<<endl;
                            cout<<"Apasa pe SPACE pentru a continua...";
                            getch();
                            cls;
                            if(puncte<5)
                            {
                                puncte = 0;
                            }
                            else
                                puncte-=5;
                            goto ex1;
                        }
                    }
                }
            }
            if(c%2==1)
            {
                echo<<a<<"+"<<b<<"=";
                cin>>result;
                if(result==99)
                {
                    goto init;
                }
                else
                {
                    if(result==(a+b))
                    {
                        cout<<"\n\nCORECT!!!"<<endl;
                        cout<<"Apasa pe SPACE pentru a continua...";
                        getch();
                        puncte++;
                        cls;
                        goto ex1;
                    }
                    else
                    {
                        cout<<"Offff... Gresit!! Incearca alta data... Rezultatul era "<<a+b<<" iar tu ai spus "<<result<<"!"<<endl;
                        cout<<"Apasa pe SPACE pentru a continua..."<<endl;
                        getch();
                        cls;
                        if(puncte<5)
                        {
                            puncte = 0;
                        }
                        else
                            puncte-=5;
                        goto ex1;
                    }
                }
            }
        }
    }
    else
    {
        cout<<"Esti sigur ca ai introdus datele corect?"<<endl;
    }
    return 0;
}
