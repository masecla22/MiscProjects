#include <iostream>
#include <fstream>


using namespace std;
int getSpace(std::string which){
    for(unsigned int i=0;i<which.size();i++)
        if(which.at(i)==' ')
            return i;
    return -1;
}
std::string getIp(std::string thing){
    if(getSpace(thing)!=-1)
        return thing.substr(0,getSpace(thing));
    else
        return " ";

}
int main()
{
    std::ifstream fin("data.txt");
    while(fin.eof()){

    }
    return 0;
}
