#include <iostream>
#include <fstream>

using namespace std;

int main()
{
   ifstream fin("data.in");
   ofstream fout("data.out");
   string word;
   while(fin>>word){
        for(int i=0;i<word.length();i++){
            fout<<int(word.at(i))<<" ";
        }
        fout<<int(' ');
   }
    return 0;
}
