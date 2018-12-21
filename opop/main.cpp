#include <iostream>
#include <fstream>

using namespace std;
std::string getIP(std::string another) {
    std::string result="";
    for(int i=0; i<another.size(); i++)
        if(another.at(i)==' ')
            break;
        else
            result+=another.at(i);
    return result;

}
int main() {
    std::ifstream fin("data.txt");
    std::ofstream fout("out.txt");

    std::string n;
    int curr = 0;
    while(fin>>n) {
        if(curr%3==0) {
            std::cout<<getIP(n)<<"\n";
            fout<<getIP(n)<<"\n";
        }
        curr++;
    }
    return 0;
}
