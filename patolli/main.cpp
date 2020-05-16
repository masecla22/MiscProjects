#include <iostream>
#include <algorithm>
#include <vector>
#include <conio.h>
#include <fstream>

using namespace std;
std::vector<int> verticals = {1,2,7,12,17,22,23,24,25,27,28,29,30,35,40,45,50,51};
std::vector<int> horizontals = {3,4,5,6,8,9,10,11,13,14,15,16,18,19,20,21,26,31,32,33,34,36,37,38,39,41,42,43,44,46,47,48,49};
///First three are mine, next are his
int mar[6] = {0,0,0,0,0,0};
bool isPrime(int i) {
    if(i<2 || (i>2 && i%2==0))
        return false;
    for(int d=3; d*d<=i; d+=2)
        if(i%d==0)
            return false;
    return true;
}
bool isVertical(int applied) {
    return binary_search(verticals.begin(),verticals.end(),applied);
}
bool isHorizontal(int applied) {
    return binary_search(horizontals.begin(),horizontals.end(),applied);
}
bool isPerfectSquare(int x) {
    double sr = sqrt(x);
    return sr == int(sr);
}

bool satisfiesRule9(std::vector<int> appliedMoves) {
    bool verti = false;
    bool horiz = false;
    for(int c : appliedMoves) {
        if(isHorizontal(c))
            horiz=true;
        if(isVertical(c))
            return horiz;
    }
    return false;
}

bool isOccupied(int pos,int forWho) {
    for(int i=0; i<6; i++) {
        if(i==forWho) /// Ignore own marker
            continue;
        if(mar[i]==pos)
            return true;
    }
    return false;
}

int lowestMarkerPlayer() {
    int c = min(mar[0],min(mar[1],mar[2]));
    /// Shut up, i get 10 minutes of execution
    for(int i=0; i<3; i++)
        if(c==mar[i])
            return i;
}


void applyMove(int p, int diceroll) {

    int possiblePosition = mar[p]+diceroll;

    std::vector<int> appliedMoves;
    for(int i=mar[p]; i<possiblePosition; i++)
        appliedMoves.push_back(i); /// Generate all applied moves.

    /// Rule 4
    ///Check if the position is occupied.
    if(isOccupied(possiblePosition,p))
        return;

    /// Rule 5
    /// If the position is larger than 52 the dice roll can be ignored
    if(possiblePosition>52)
        return;

    /// Rule 6
    /// If the position is 52, mark as done.
    if(possiblePosition==52) {
        mar[p]=696969;
        return;
    }

    /// Rule 7, apply prime magic;
    if(isPrime(possiblePosition)) {
        int endUp = possiblePosition;
        for(int i=0; i<6; i++) {
            endUp++;
            if(isOccupied(endUp,p)) {
                endUp--;
                break;
            }
        }
        mar[p]=endUp;
        return ;
    }

    /// Rule 8, apply square magic;
    if(isPerfectSquare(possiblePosition)) {
        int endUp = possiblePosition;
        for(int i=0; i<6; i++) {
            endUp--;
            if(isOccupied(endUp,p)) {
                endUp++;
                break;
            }
        }
        mar[p]=endUp;
        return ;
    }

    /// Rule 9 Magic doohikey thing
    if(satisfiesRule9(appliedMoves)) {
        /// Work backwards to find the optimal move in 9's bounds
        int result = mar[p]; /// Initialize with initial position, if 9 fails, it's unchanged
        for(int i=possiblePosition; i>mar[p]; i--) {
            if(i%diceroll!=0)
                continue; /// Not a multiple. Ignore;
            if(isOccupied(i,p))
                continue; /// Occupied, ignore.
            result = i;
        }
        mar[p]=result; /// Move it
        return ;
    }
    /// Should end up here if 9 died
    /// At this stage, after applying all that, the game
    /// Should start making a bit of sense
    /// So we move the marker by the dice roll
    /// No need to check if occupied, see Rule 4
    mar[p]+=diceroll;
    return ; /// <3
}


int main() {

    ifstream fin("int-sample-input.txt");
    for(int i=0; i<5; i++) {
        fin>>mar[3]>>mar[4]>>mar[5]>>mar[0]>>mar[1]>>mar[2];
        int diceRoll = 0;
        fin>>diceRoll;
        for(int j=0; j<diceRoll; j++) {
            int crdice = 0;
            fin>>crdice;
            applyMove(lowestMarkerPlayer(),crdice);
        }
        std::vector<int> toShow;
        for(int i=0; i<3; i++)
            if(mar[i]!=696969)
                toShow.push_back(mar[i]);
        sort(toShow.begin(),toShow.end());
        if(toShow.size()==0)
            cout<<"GAME OVER";
        else
            for(int i : toShow)
                cout<<i<<" ";
        cout<<endl;
    }

    return 0;
}
