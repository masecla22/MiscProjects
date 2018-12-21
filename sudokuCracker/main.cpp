#include <iostream>
#include <windows.h>
#include <vector>
#include <fstream>
#include <mattcore.h>

using namespace std;
void setConsoleColor(int which) {
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, which);
}
int getColor(int number,bool isHigh) {
    if(isHigh)
        return number+240;
    return number;
}
class spot {
  public:
    int inside;
    bool isHigh;
};
class table {
  public:
    vector<spot> numbers;
    table(string filename) {
        std::fstream fin;
        fin.open(filename,std::ifstream::in);
        for(int i=0; i<9; i++)
            for(int j=0; j<9; j++) {
                spot n;
                fin>> n.inside;
                n.isHigh = false;
                numbers.push_back(n);
            }
        fin.close();
    }
    int getAtPos(int x,int y) {
        return numbers.at(y*9+x).inside;
    }
    void setAtPos(int x,int y,int howMuch) {
        numbers.at(y*9+x).inside=howMuch;
    }
    void highlightAtPos(int x,int y,bool highlight) {
        numbers.at(y*9+x).isHigh = highlight;
    }
    bool isHighlightAtPos(int x,int y) {
        return numbers.at(y*9+x).isHigh;
    }
    spot getSAtPos(int x,int y) {
        return numbers.at(y*9+x);
    }
    void printIt() {
        for(int i=0; i<9; i++,cout<<"\n")
            for(int j=0; j<9; j++,cout<<"  ") {
                setConsoleColor(getColor(getAtPos(j,i)+3,isHighlightAtPos(j,i)));
                cout<<getAtPos(j,i);
                if(j!=8)
                    if(!isHighlightAtPos(j+1,i))
                        setConsoleColor(0);
                    else {
                        if(!isHighlightAtPos(j+1,i))
                            setConsoleColor(0);
                    }
            }
        setConsoleColor(0);
    }
    void highlightColumn(int which) {
        for(int i=0; i<9; i++)
            highlightAtPos(which,i,true);
    }
    void highlightRow(int which) {
        for(int i=0; i<9; i++)
            highlightAtPos(i,which,true);
    }
    void unhighlightColumn(int which) {
        for(int i=0; i<9; i++)
            highlightAtPos(which,i,false);
    }
    void unhighlightRow(int which) {
        for(int i=0; i<9; i++)
            highlightAtPos(i,which,false);
    }
    vector<spot> getRow(int which) {
        vector<spot> toReturn;
        for(int i=0; i<9; i++) {
            toReturn.push_back(getSAtPos(i,which));
        }
        return toReturn;
    }
    vector<spot> getColumn(int which) {
        vector<spot> toReturn;
        for(int i=0; i<9; i++) {
            toReturn.push_back(getSAtPos(which,i));
        }
        return toReturn;
    }
};
int howManyEmpty(vector<spot> a){
    int contor = 0;
    for(int i=0;i<9;i++)
        contor += (a.at(i).inside==0);
    return contor;
}
void solveRow(vector<spot> a){


}

int main() {
    table mains("data.in");
    matt::core::ShowConsoleCursor(false);
    for(int y=0; y<9; y++) {
        for(int x=0; x<9; x++) {
            mains.highlightColumn(x);
            mains.highlightRow(y);
            mains.printIt();
            Sleep(70);
            mains.unhighlightColumn(x);
            mains.unhighlightRow(y);
            matt::core::clear();
        }
        Sleep(700);
    }
    system("cls");
    return 0;
}
