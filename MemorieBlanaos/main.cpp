#include <iostream>
#include <windows.h>
#include <vector>
#include <cstring>
#include <iomanip>
#include <ctime>
#include <conio.h>
#include <sstream>
#include <chrono>
using namespace std;
namespace matt {
namespace core {
int random(int min, int max) {
    if(min==max)
        return min;
    static bool first = true;
    if ( first ) {
        srand(time(NULL));
        first = false;
    }
    return min + rand() % (max - min);
}
void ShowConsoleCursor(bool showFlag) {
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO     cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}
void clear() {
    COORD p = { 0, 0 };
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), p );

}
}
namespace gui {
size_t getSlash(string a) {
    size_t ss=0;
    for(size_t i=0; i<a.length(); i++)
        ss+=(a.at(i)=='/'&&a[i+1]!='/');
    return ss;
}
void showArg(string a,size_t which) {
    size_t j=0;
    for(size_t i=0; i<a.length(); i++) {
        j+=(a.at(i)=='/');
        if(j==which&&a.at(i)!='/')
            cout<<a.at(i);
    }
}
void show(string opts,vector<int>vals) {
    for(size_t i=0; i<getSlash(opts); i++,cout<<"\t\n") {
        if(vals.at(i)==1)
            cout<<"> ";
        showArg(opts,i);
    }
}
int gui(string opts) {
    matt::core::clear();
    vector<int>vals;
    vals.push_back(1);
    for(size_t i=1; i<getSlash(opts); i++)
        vals.push_back(0);
    show(opts,vals);
    unsigned int pos=0;
    matt::core::ShowConsoleCursor(false);
    while(1) {
        size_t a=_getch();
        matt::core::clear();
        if(a==80)
            (pos==(getSlash(opts)-1))?pos=0:pos++;
        if(a==72)
            (pos==0)?pos=(getSlash(opts)-1):pos--;
        if(a==13) {
            matt::core::clear();
            break;
        }
        for(unsigned int i=0; i<getSlash(opts); i++)
            vals[i]=(pos==i);
        show(opts,vals);
    }
    return pos;
}
}
namespace benchmark {
class clock {
private:
    std::chrono::high_resolution_clock::time_point beginPoint;
    bool wasEnded=0;
public:
    double durs=0;
    clock(void) {
        beginPoint = std::chrono::high_resolution_clock::now();
    }
    void start() {
        beginPoint = std::chrono::high_resolution_clock::now();
    }
    void ends() {
        std::chrono::high_resolution_clock::time_point endPoint = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(endPoint- beginPoint);
        durs = time_span.count()*1000000;
    }
};
}
}
void toClipboard(const std::string &s) {
    OpenClipboard(0);
    EmptyClipboard();
    HGLOBAL hg=GlobalAlloc(GMEM_MOVEABLE,s.size());
    if (!hg) {
        CloseClipboard();
        return;
    }
    memcpy(GlobalLock(hg),s.c_str(),s.size());
    GlobalUnlock(hg);
    SetClipboardData(CF_TEXT,hg);
    CloseClipboard();
    GlobalFree(hg);
}
std::string GetClipboardText() {
    if (! OpenClipboard(nullptr))
        return "";
    HANDLE hData = GetClipboardData(CF_TEXT);
    if (hData == nullptr)
        return "";
    char * pszText = static_cast<char*>( GlobalLock(hData) );
    if (pszText == nullptr)
        return "";
    std::string text( pszText );
    GlobalUnlock( hData );
    CloseClipboard();
    return text;
}
void showTitle(std::string str) {
    for(unsigned int i=0; i<str.size(); i++) {
        char a = str[i];
        cout<<a;
        Sleep(50);
    }
}
long long stages[20] = {482,2869,72356,164532,2756734,81237654,136472938};
class StageResult {
public:
    int expected,recieved,time;
    StageResult(int expected1,int recieved1,int time1) {
        expected = expected1;
        recieved = recieved1;
        time = time1;
    }
};
std::string toint(int a) {
    std::string x;
    stringstream ss;
    ss<<a;
    ss>>x;
    return x;
}
void tochar(std::string a,char buffer[]) {
    for(unsigned int i=0; i<a.size(); i++)
        buffer[i]=a[i];
    buffer[a.size()]='\0';
}
void getReq(std::string url) {
    std::string cmd = "start gets.exe "+url;
    char buffer[300];
    tochar(cmd,buffer);
    system(buffer);
}
void submit(StageResult res) {
    std::string url = "http://infomass.zapto.org/projects/iynt/submitdata.php?ex="+toint(res.expected)+"^&res="+toint(res.recieved)+"^&time="+toint(res.time);
    getReq(url);
}
StageResult playStage(int stg) {
    cout<<"Press a key to start playing!"<<endl;
    _getch();
    system("cls");
    cout<<"\n\n\n\nPlease remember this number. You have 5 seconds.\n\n\t\t\t"<<stages[stg]<<endl;
    Sleep(5000);
    std::string clp = GetClipboardText();
    toClipboard("Stop cheating.");
    system("cls");
    matt::benchmark::clock a;
    a.start();
    cout<<"Please re-enter the number you were given: ";
    int resp;
    cin>>resp;
    a.ends();
    if(a.durs<1000000) {
        cout<<"Please stop cheating."<<endl;
        return playStage(stg);
    }
    toClipboard(clp);
    cout<<"You did it in "<<a.durs/1000000.0<<"s"<<endl;
    StageResult n = StageResult(stages[stg],resp,a.durs);
    submit(n);
    return n;
}
int main() {
    showTitle("Welcome to the Memory Game\n");
    showTitle("Press any key to continue");
    _getch();
    system("cls");
    int a = matt::gui::gui("Start the game  /Options  /");
    std::vector<StageResult> results;
    if(a==0) {
        system("cls");
        for(int i=0; i<7; i++)
            results.push_back(playStage(i));
    }
    if(a==1) {

    }
    return 0;
}
