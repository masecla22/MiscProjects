#include <iostream>
#include <mattgui.h>
using namespace matt::gui;

int main()
{
    int vOpt = gui("1.8/1.8.3/1.8.8/1.9/1.9.2/1.9.4/1.10.2/1.11/1.11.2/1.12/1.12.1/1.12.2/1.13/");
    system("cls");
    int cORs = gui("CraftBukkit  /Spigot  /Back  /");
    std::string path = "\"G:\\Desktop\\Server Tester\\Servers\\ActualServerData\\";
    system("cls");if(vOpt==0)path+="1.8";if(vOpt==1)path+="1.8.3";
    if(vOpt==2)path+="1.8.8";if(vOpt==3)path+="1.9";if(vOpt==4)path+="1.9.2";
    if(vOpt==5)path+="1.9.4";if(vOpt==6)path+="1.10.2";if(vOpt==7)path+="1.11";
    if(vOpt==8)path+="1.11.2";if(vOpt==9)path+="1.12";if(vOpt==10)path+="1.12.1";
    if(vOpt==11)path+="1.12.2";if(vOpt==12)path+="1.13";string jar = "";if(cORs==0)jar+="craftbukkit-";
    else if(cORs==1)jar+="spigot-";else main();if(vOpt==0)jar+="1.8";if(vOpt==1)jar+="1.8.3";if(vOpt==2)jar+="1.8.8";if(vOpt==3)jar+="1.9";
    if(vOpt==4)jar+="1.9.2";if(vOpt==5)jar+="1.9.4";if(vOpt==6)jar+="1.10.2";
    if(vOpt==7)jar+="1.11";if(vOpt==8)jar+="1.11.2";if(vOpt==9)jar+="1.12";
    if(vOpt==10)jar+="1.12.1";if(vOpt==11)jar+="1.12.2";if(vOpt==12)jar+="1.13";
    jar+=".jar";system("cls");std::string cmd = "java -jar "+path;std::ofstream fout("run.bat");
    fout<<"cd "+path<<std::endl;fout<<"java -jar "+jar<<endl;system("start run.bat");
    system("cls");cout<<"Started the server!"<<endl;Sleep(5000);main();



    return 0;
}
