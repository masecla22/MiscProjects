#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;
int tabLevel=0;
int shouldBeAdded=0;
int getPointPos(string n) {
    int pos = -1;
    for(int i=0; i<n.size(); i++)
        if(n.at(i)=='.')
            pos=i;
        else if(n.at(i)=='{')
            shouldBeAdded=1;
        else if(n.at(i)=='}')
            tabLevel--;
    return pos;
}
void findAndReplaceAll(std::string & data, std::string toSearch, std::string replaceStr){
	size_t pos = data.find(toSearch);
	while( pos != std::string::npos){
		data.replace(pos, toSearch.size(), replaceStr);
		pos=data.find(toSearch, pos + toSearch.size());
	}
}
int getBrackPos(string n) {
    int pos = -1;
    for(int i=0; i<n.size(); i++)
        if(n.at(i)=='{')
            pos=i;
    return pos;
}
string getTabs() {
    string res = "";
    for(int i=0; i<tabLevel; i++)
        res+="\t";
    return res;
}
bool isBroke(string n) {
    if(getPointPos(n)==(n.size()-1))
        return true;
    return false;
}
bool isBracketsAlone(string n) {
    if(getBrackPos(n)==-1)
        return false;
    for(int i=0; i<n.size(); i++)
        if(n.at(i)!=' ' || n.at(i)!='\t' || n.at(i)!='{' || n.at(i)!='}')
            return false;
        return true;
}
int main() {
    fstream fin,fout;
    fin.open("murdar.in",ios::in);
    fout.open("clean.out",ios::out);
    while(!fin.eof()) {
        string n;
        getline(fin,n);
        findAndReplaceAll(n,"\302"," ");
        findAndReplaceAll(n,"\240"," ");
        findAndReplaceAll(n,"{","{\n");
        if(n!="" && !isBroke(n)) {
            if(shouldBeAdded==1){
                fout<<getTabs()+n+"\n";
                tabLevel--;
            }
            else
                fout<<getTabs()+n+"\n";
        }
    }
    fin.close();
    fout.close();
    return 0;
}




