#include <iostream>
#include <fstream>
#include "mattcrypt.h"
#include <mattcore.h>

int main()
{
    std::fstream fin;
    std::string key = "666666666";
    fin.open("test.txt",std::ifstream::in);
    std::fstream fout;
    matt::core::clFile("out.txt");
    fout.open("out.txt",std::ofstream::out);
    std::string word;
    while(!fin.eof()){
        getline(fin,word);
        if(!(word=="")){
        doEncrypt(word,key);
        fout<<word<<std::endl;
        }
    }
    return 0;
}
