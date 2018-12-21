#include "includer.h"
using namespace std;

int main ()
{

    /** SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | BACKGROUND_INTENSITY);
     SetConsoleTextAttribute(hConsole, saved_colors);
     */
    ///LOGIN;REGISTER screen
INIT:
    char GLuser[255];
    int a = BeginScreen();
    if(a==1)
    {
        system("cls");
        string user,pass;
        RegisterScreen(user,pass);
        char user1[255],pass1[255];
        strtchr(user1,user);
        strtchr(pass1,pass);
        int err = registers(user1,pass1);
        if(err==1)
        {
            cout<<"\n\nSuccesfuly registered!"<<endl;
        }
        else
        {
            cout<<"\n\nAn error has occured! Maybe the username is taken?"<<endl;
        }
        Sleep(2000);
        goto INIT;
    }
    if(a==0)
    {
        system("cls");
        string user,pass;
        LoginScreen(user,pass);
        char user1[255],pass1[255];
        strtchr(user1,user);
        strtchr(pass1,pass);
        int err = login(user1,pass1);
        if(err==1)
        {
            cout<<"\n\nSuccesfully logged in! Welcome "<<user<<endl;
            Sleep(2000);
            strcpy(GLuser,user1);
            goto logged;
        }
        else
        {
            cout<<"\n\nAn error occured! Maybe wrong usernme and password or missing Internet?"<<endl;
        }

    }





    if(1==2)
    {
logged:
        cout<<"User: "<<GLuser<<endl;
        int ems;
        char FileNM[255];
        strcpy(FileNM,"Accs\\");
        strcat(FileNM,GLuser);
        strcat(FileNM,".txt");
        fstream file(FileNM, ios::in | ios::out | ios::app);
        char GLpass[255];
        file.getline(GLpass,255);
        file>>ems;
        int i =0;
        char emails[255][100];
        while(i<ems)
        {
            file.getline(emails[i],255);
            i++;
        }
        i=0;
        while(i<ems)
        {
            cout<<emails[i]<<endl;
            i++;
        }
    }
        return 0;
}
