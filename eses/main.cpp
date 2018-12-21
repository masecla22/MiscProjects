#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#include<conio.h>
#include<strings.h>
char tempstr[20];
int user,cpu=0,i,j,usermv,cpumv,dmgmul,clk=0,a,k,c,c1,d,d1,e=0,e1=0;
char moves[20][20]={/*0*/"tackle",/*1*/"scratch",/*2*/"ember",/*3*/"water gun",/*4*/"vine whip",/*5*/"growl",/*6*/"tail whip",/*7*/"sand tomb",/*8*/"thundershock",/*9*/"hydro pump",/*10*/"fire blast",/*11*/"solar beam",/*12*/"thunder",/*13*/"earthquake",/*14*/"gust",/*15*/"sky attack",/*16*/"scary face",/*17*/"agility",/*18*/"aurora beam",/*19*/"ice beam"};
char atktyp[20]={'n','n','f','w','g','n','n','G','e','w','f','g','e','G','F','F','n','n','i','i'};
int atkpwr[20]={40,40,40,40,40,0,0,50,40,80,80,80,100,80,40,90,0,0,40,90};
int atkpp[20]={10,10,6,6,6,4,4,6,6,3,3,3,3,3,6,3,4,4,6,3};
int atkppuser[20]={10,10,6,6,6,4,4,6,6,3,3,3,3,3,6,3,4,4,6,3};
int atkppcpu[20]={10,10,6,6,6,4,4,6,6,3,3,3,3,3,6,3,4,4,6,3};
typedef struct {
    char name[20];
    float atk;
    float def;
    int spd;
    int hp;
    int moveset[4];
    char typ;
    } pokemon;
pokemon p[7]={{"pikachu",11,8,11,60,{0,6,8,12},'e'},{"sandshrew",10,12,8,60,{1,5,7,13},'G'},{"bulbasaur",11,9,10,60,{0,4,5,11},'g'},{"charmander",13,8,9,60,{1,2,5,10},'f'},{"squirtle",10,13,7,60,{0,3,6,9},'w'},{"pidgey",9,9,12,60,{0,17,14,15},'F'},{"seel",11,12,7,60,{0,16,18,19},'i'}};
    HANDLE in;
    HANDLE out;
    INPUT_RECORD input;
    COORD pos;
    DWORD info;
    CONSOLE_SCREEN_BUFFER_INFO screenInfo;
    CHAR_INFO logo[64];
    CHAR_INFO logo1[175];
    SMALL_RECT logobody={5,5,13,13};
    SMALL_RECT logo1body={25,7,60,12};
    COORD zerozero={0,0};
    COORD logosz={8,8};
    COORD logo1sz={35,5};

int chkspd(int userspd,int cpuspd)
{
    srand(time(NULL));
    if(userspd>cpuspd)
        return 1;
    if(cpuspd>userspd)
        return 2;
}
int calcdmgmul(int pktyp,int atktyp)
{
    switch(pktyp)
    {
    case 101:
        switch(atktyp)
        {
        case 101:
            return 1;
            break;
        case 71:
            return 3;
            break;
        case 103:
            return 2;
            break;
        case 102:
            return 2;
            break;
        case 119:
            return 2;
            break;
        case 110:
            return 2;
            break;
        case 70:
            return 1;
            break;
        case 105:
            return 2;
            break;
        }
        break;
    case 71:
        switch(atktyp)
        {
        case 101:
            return 1;
            break;
        case 71:
            return 2;
            break;
        case 103:
            return 3;
            break;
        case 102:
            return 1;
            break;
        case 119:
            return 3;
            break;
        case 110:
            return 2;
            break;
        case 70:
            return 2;
            break;
        case 105:
            return 3;
            break;
        }
        break;
    case 103:
        switch(atktyp)
        {
        case 101:
            return 2;
            break;
        case 71:
            return 2;
            break;
        case 103:
            return 1;
            break;
        case 102:
            return 3;
            break;
        case 119:
            return 2;
            break;
        case 110:
            return 2;
            break;
        case 70:
            return 3;
            break;
        case 105:
            return 3;
            break;
        }
        break;
    case 102:
        switch(atktyp)
        {
        case 101:
            return 2;
            break;
        case 71:
            return 3;
            break;
        case 103:
            return 1;
            break;
        case 102:
            return 1;
            break;
        case 119:
            return 3;
            break;
        case 110:
            return 2;
            break;
        case 70:
            return 2;
            break;
        case 105:
            return 1;
            break;
        }
        break;
    case 119:
        switch(atktyp)
        {
        case 101:
            return 3;
            break;
        case 71:
            return 2;
            break;
        case 103:
            return 3;
            break;
        case 102:
            return 1;
            break;
        case 119:
            return 1;
            break;
        case 110:
            return 2;
            break;
        case 70:
            return 2;
            break;
        case 105:
            return 1;
            break;

        }
        break;
    case 70:
         switch(atktyp)
        {
        case 101:
            return 2;
            break;
        case 71:
            return 2;
            break;
        case 103:
            return 2;
            break;
        case 102:
            return 3;
            break;
        case 119:
            return 2;
            break;
        case 110:
            return 2;
            break;
        case 70:
            return 2;
            break;
        case 105:
            return 1;
            break;

        }
        break;
    case 105:
         switch(atktyp)
        {
        case 101:
            return 3;
            break;
        case 71:
            return 1;
            break;
        case 103:
            return 1;
            break;
        case 102:
            return 2;
            break;
        case 119:
            return 2;
            break;
        case 110:
            return 2;
            break;
        case 70:
            return 2;
            break;
        case 105:
            return 3;
            break;

        }
        break;
    }
}
void typdisplay(int typch)
{
    switch(typch)
    {
        case 101:
            printf("electric\t");
            break;
        case 71:
            printf("ground\t");
            break;
        case 103:
            printf("grass\t");
            break;
        case 102:
            printf("fire\t");
            break;
        case 119:
            printf("water\t");
            break;
        case 110:
            printf("normal\t");
            break;
        case 70:
            printf("flying\t");
            break;
        case 105:
            printf("ice\t");
            break;
    }
}
void delay(int a)
{
    clock_t start;
    start=clock();
    while(clock() - start < a)
    {

    }
}
int main()
{
    int w[22]={2,3,4,5,10,11,12,13,16,17,22,23,24,26,29,31,48,55,56,57,62,63};
    int y[69]={0,1,2,10,13,16,17,18,35,38,41,42,45,47,50,53,55,59,62,63,66,69,70,71,72,75,78,80,81,85,87,88,90,91,93,94,96,99,101,102,104,105,110,113,115,117,120,125,127,129,131,134,136,138,139,140,146,147,150,153,156,157,158,160,164,167,168,171,174};
    int poketypcol[7]={14,6,10,12,9,15,11};
    char pokedisp[7][15]={"1.pikachu","2.sandshrew","3.bulbasaur","4.charmander","5.squirtle","6.pidgey","7.seel"};
    in=GetStdHandle(STD_INPUT_HANDLE);
    out=GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(out, &screenInfo);
    //SetConsoleMode(in, ENABLE_PROCESSED_INPUT| ENABLE_MOUSE_INPUT);
    for(i=0;i<64;i++)
    {
        logo[i].Char.AsciiChar=-37;
        logo[i].Attributes=FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY;
    }
    for(i=0;i<22;i++)
    {
        logo[w[i]].Attributes=00;
    }
    logo[41].Attributes=FOREGROUND_RED|FOREGROUND_INTENSITY;
    logo[46].Attributes=FOREGROUND_RED|FOREGROUND_INTENSITY;
    for(i=0;i<175;i++)
    {
        logo1[i].Char.AsciiChar=-37;
        logo1[i].Attributes=00;
    }
    for(i=0;i<69;i++)
    {
        logo1[y[i]].Attributes=FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY;
    }
    WriteConsoleOutput(out,logo,logosz,zerozero,&logobody);
    WriteConsoleOutput(out,logo1,logo1sz,zerozero,&logo1body);
    pos.X=30;
    pos.Y=15;
    SetConsoleCursorPosition(out,pos);
    printf("Pokemon: Battle of 7");
    pos.Y++;
    SetConsoleCursorPosition(out,pos);
    printf("Written By: Shivam Shekhar");
    pos.Y=19;
    SetConsoleCursorPosition(out,pos);
    printf("Press any key to continue.....");
    getch();
    system("cls");
    pos.X=30;
    pos.Y=7;
    for(i=0;i<7;i++)
    {
        SetConsoleCursorPosition(out,pos);
        SetConsoleTextAttribute(out,poketypcol[i]);
        printf("%s",pokedisp[i]);
        pos.Y++;
    }
    SetConsoleCursorPosition(out,pos);
    SetConsoleTextAttribute(out,7);
    printf("choose your pokemon: ");
    scanf("%d", &user);
    user=user-1;
    srand(time(NULL));
    while(cpu==user)
    {cpu=rand()%7;}
    system("cls");
    pos.X=20;
    pos.Y=7;
     SetConsoleCursorPosition(out,pos);
     SetConsoleTextAttribute(out,poketypcol[user]);
    printf("you chose %s", p[user].name);
    pos.Y+=2;
    SetConsoleCursorPosition(out,pos);
    SetConsoleTextAttribute(out,poketypcol[cpu]);
    printf("cpu chose %s",p[cpu].name);
    pos.Y+=2;
    SetConsoleCursorPosition(out,pos);
    SetConsoleTextAttribute(out,7);
    system("pause");
    system("cls");
    c=p[cpu].hp;
    c1=c;
    d=p[user].hp;
    d1=d;
    for(a=0;;a++)
    {

        printf("%s\nHP: %d\n", p[cpu].name,p[cpu].hp);
       if(a==0)
        {
            for(i=0;i<(p[cpu].hp);i++)
            {printf("%c",177);
            delay(20);}
            e1=1;
        }
        else
        {
           for(i=0;i< c - p[cpu].hp;i++)
            {
                printf("\r");
                for(k=0;k<c1;k++)
                {
                    printf("%c",177);
                }
                for(i=0;i<c-c1;i++)
                    printf(" ");
                c1--;
                delay(20);
                e1=1;
            }
        }
        if(e1==0)
        {
            for(i=0;i<p[cpu].hp;i++)
                printf("%c", 177);
        }
        printf("\n\n");
        printf("%s\nHP: %d\n", p[user].name,p[user].hp);
        if(a==0)
        {
            for(i=0;i<p[user].hp;i++)
            {
                printf("%c",177);
                delay(20);
            }
            e=1;
        }
        else
        {
            for(i=0;i< d - p[user].hp;i++)
            {
                printf("\r");
                for(k=0;k<d1;k++)
                    printf("%c",177);
                for(i=0;i<d-d1;i++)
                    printf(" ");
                d1--;
                delay(20);
                e=1;
            }
        }
        if(e==0)
        {
            for(i=0;i<p[user].hp;i++)
                printf("%c",177);
        }
        printf("\n");
         c=p[cpu].hp;
        c1=c;
        d=p[user].hp;
        d1=d;
        e=0;
        e1=0;
        for(i=0;i<4;i++)
        {
            printf("%d: %d/%d ", i+1,atkppuser[p[user].moveset[i]],atkpp[p[user].moveset[i]]);
            typdisplay(atktyp[p[user].moveset[i]]);
            puts(moves[p[user].moveset[i]]);
        }
        scanf("%d", &usermv);
        while(usermv > 4 || usermv < 1)
        {
            printf("invalid input try again\n");
            scanf("%d",&usermv);
        }
        while(atkppuser[p[user].moveset[usermv-1]]==0)
        {
            if(atkppuser[p[user].moveset[usermv-1]]==0)
                printf("no pp left. try again\n");
            scanf("%d", &usermv);
        }
        usermv=usermv-1;
        cpumv=rand()%4;
        while(atkppcpu[p[cpu].moveset[cpumv]]==0)
        {
            cpumv=rand()%4;
        }
        system("cls");
        if(chkspd(p[user].spd,p[cpu].spd)==1)
        {
            printf("\n\n%s used ", p[user].name);
            puts(moves[p[user].moveset[usermv]]);
            atkppuser[p[user].moveset[usermv]]--;
            dmgmul=calcdmgmul(p[cpu].typ,atktyp[p[user].moveset[usermv]]);
            p[cpu].hp = p[cpu].hp - (((p[user].atk*atkpwr[p[user].moveset[usermv]])/(p[cpu].def*20))*dmgmul);
            if(p[user].moveset[usermv]==5)
               {
                   p[cpu].atk--;
                   printf("\n%s attack fell",p[cpu].name);
               }
            if(p[user].moveset[usermv]==6)
                {
                    p[cpu].def--;
                    printf("\n%s defense fell",p[cpu].name);
                }
                if(p[user].moveset[usermv]==16)
               {
                   p[cpu].spd--;
                   printf("\n%s speed fell",p[cpu].name);
               }
               if(p[user].moveset[usermv]==17)
               {
                   p[user].spd++;
                   printf("\n%s speed rose",p[user].name);
               }
            if(p[cpu].hp<=0)
            {printf("\n\n%s fainted\n\nYou win\n\n", p[cpu].name);
            break;
            }
            printf("\n\n%s used ",p[cpu].name);
            puts(moves[p[cpu].moveset[cpumv]]);
            atkppcpu[p[cpu].moveset[cpumv]]--;
            dmgmul=calcdmgmul(p[user].typ,atktyp[p[cpu].moveset[cpumv]]);
            p[user].hp = p[user].hp - (((p[cpu].atk*atkpwr[p[cpu].moveset[cpumv]])/(p[user].def*20))*dmgmul);
            if(p[cpu].moveset[cpumv]==5)
                {
                    p[user].atk--;
                    printf("\n%s attack fell",p[user].name);
                }
            if(p[cpu].moveset[cpumv]==6)
                {
                    p[user].def--;
                    printf("\n%s defense fell",p[user].name);
                }
                if(p[cpu].moveset[cpumv]==16)
               {
                   p[user].spd--;
                   printf("\n%s speed fell",p[user].name);
               }
               if(p[cpu].moveset[cpumv]==17)
               {
                   p[cpu].spd++;
                   printf("\n%s speed rose",p[cpu].name);
               }
            printf("\n\n");
        }
        else
        {
            printf("\n\n%s used ",p[cpu].name);
            puts(moves[p[cpu].moveset[cpumv]]);
            atkppcpu[p[cpu].moveset[cpumv]]--;
            dmgmul=calcdmgmul(p[user].typ,atktyp[p[cpu].moveset[cpumv]]);
           p[user].hp = p[user].hp - (((p[cpu].atk*atkpwr[p[cpu].moveset[cpumv]])/(p[user].def*20))*dmgmul);
            if(p[cpu].moveset[cpumv]==5)
               {
                   p[user].atk--;
                   printf("\n%s attack fell",p[user].name);
               }
            if(p[cpu].moveset[cpumv]==6)
                {
                    p[user].def--;
                    printf("\n%s defense fell",p[user].name);
                }
                if(p[cpu].moveset[cpumv]==16)
               {
                   p[user].spd--;
                   printf("\n%s speed fell",p[user].name);
               }
               if(p[cpu].moveset[cpumv]==17)
               {
                   p[cpu].spd++;
                   printf("\n%s speed rose",p[cpu].name);
               }
            if(p[user].hp<=0)
            {printf("\n\n%s fainted\n\nYou lose\n\n", p[user].name);
            break;}
            printf("\n\n%s used ", p[user].name);
            puts(moves[p[user].moveset[usermv]]);
            atkppuser[p[user].moveset[usermv]]--;
            dmgmul=calcdmgmul(p[cpu].typ,atktyp[p[user].moveset[usermv]]);
           p[cpu].hp = p[cpu].hp - (((p[user].atk*atkpwr[p[user].moveset[usermv]])/(p[cpu].def*20))*dmgmul);
            if(p[user].moveset[usermv]==5)
                {
                    p[cpu].atk--;
                    printf("\n%s attack fell",p[cpu].name);
                }
            if(p[user].moveset[usermv]==6)
               {
                   p[cpu].def--;
                   printf("\n%s defense fell",p[cpu].name);
               }
               if(p[user].moveset[usermv]==16)
               {
                   p[cpu].spd--;
                   printf("\n%s speed fell",p[cpu].name);
               }
               if(p[user].moveset[usermv]==17)
               {
                   p[user].spd++;
                   printf("\n%s speed rose",p[user].name);
               }
            printf("\n\n");
        }
        if(p[user].hp<=0)
            {printf("%s fainted\nYou lose", p[user].name);
        break;}
        if(p[cpu].hp<=0)
            {printf("%s fainted\nYou win", p[cpu].name);
        break;
        }/*printf("press enter to continue.......");
        fflush(stdin);
        gets(tempstr);
        */
    }
    return 0;
}
