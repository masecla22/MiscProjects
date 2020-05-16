#include <iostream>
#include <mattcore.h>
#include <sstream>
#include <fstream>
#include <mattgui.h>

using namespace std;
vector<string> split (const string &s, char delim) {
    vector<string> result;
    stringstream ss (s);
    string item;

    while (getline (ss, item, delim)) {
        result.push_back (item);
    }

    return result;
}

class Account {
public:
    std::string email;
    int minionCount;
    int collectedAmount;
    Account(std::string fromFile) {
        std::vector<std::string> data = split(fromFile,' ');
        email = data[0];
        std::stringstream x;
        x<<data[1]<<" "<<data[2];
        x>>minionCount>>collectedAmount;
    }

    Account(std::string iemail, int iminionCount,int icollectedAmount){
        email = iemail;
        minionCount = iminionCount;
        collectedAmount = icollectedAmount;
    }

    std::string convertToString(){
        std::stringstream x;
        x<<email<<" "<<minionCount<<" "<<collectedAmount;
        std::string c;
        getline(x,c);
        return c;
    }
};

std::vector<Account> loadFromFile() {
    ifstream fin("accounts.txt");
    std::vector<Account> result;
    while(!fin.eof()) {
        std::string s;
        getline(fin,s);
        if(s.size()<5)
            continue;
        result.push_back(Account(s));
    }
    fin.close();
    return result;
}

int main() {

    std::vector<Account> acc = loadFromFile();

    std::string lists = "";
    for(Account a : acc)
    {
        lists+=a.email+"  /";
    }



    int accSel = matt::gui::gui(lists);
    return 0;
}
