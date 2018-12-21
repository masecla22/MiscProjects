#include <iostream>
#include <vector>

using namespace std;
string getDecrypt(string a) {
    for(int i = 0; i<a.size(); i++)
        a[i]-=18;
    return a;
}

int main() {
    cout<<getDecrypt("‡t‹†w2‰zww~ŠmEoM‡t‹†w2‰zww~‹mEoM‡t‹†w2‰zww~ŒM‡t‹†w2€w‰…{ŒwŠmEoM‡t‹†w2€w‰…{Œw‹mEoMuzs„2wx");


    return 0;
}
///char newframe;ubyte mouseleftx[3];ubyte mouselefty[3];ubyte mouserightx[3];ubyte mouserighty[3];ubyte wheelx[3];ubyte wheely[3];ubyte wheelzoom;ubyte newsizex[3];ubyte newsizey[3];char eof
