#include <iostream>
#include <windows.h>
#include <vector>
#include <cmath>

using namespace std;


namespace monitorDetection {

std::vector<HMONITOR> monitors;

BOOL CALLBACK MonitorEnumProc(HMONITOR hMonitor, HDC hdcMonitor, LPRECT lprcMonitor, LPARAM dwData) {
    monitors.push_back(hMonitor);
    return true;
}

}

void showRECT(RECT obj) {
    cout<<"   "<<obj.top<<endl;
    cout<<obj.left<<"   "<<obj.right<<endl;
    cout<<" "<<obj.bottom<<endl;
}

int closestPerfectSquare(int a) {
    for(int i=0; true; i++) {
        int o1 = a+i;
        double os1 = sqrt(o1);
        if(os1==int(os1))
            return o1;
    }
    return -1;
}

int main() {

    cout<<"Scanning for the modded minecraft versions...\n";
    std::vector<HWND> processesFound;
    for (HWND hwnd = GetTopWindow(NULL); hwnd != NULL; hwnd = GetNextWindow(hwnd, GW_HWNDNEXT)) {
        if (!IsWindowVisible(hwnd))
            continue;
        int length = GetWindowTextLength(hwnd);
        if (length == 0)
            continue;
        char* title = new char[length+1];
        GetWindowText(hwnd, title, length+1);
        if (title == "Program Manager")
            continue;
        if(strcmp(title,"Minecraft 1.12.2")!=0)
            continue;
        processesFound.push_back(hwnd);
    }

    EnumDisplayMonitors(NULL, NULL, monitorDetection::MonitorEnumProc, NULL);
    int countOfMonitors = monitorDetection::monitors.size();

    if(processesFound.size()==0) {
        cout<<"No minecraft sessions exist!"<<endl;
        return 0;
    }

    cout<<"Found "<<processesFound.size()<<" minecraft instances open"<<endl;
    cout<<"Scanning for number of monitors: "<<countOfMonitors<<endl;

    int monitorToUse = 1;
    if(countOfMonitors!=1) {
        monitorToUse = -1;
        while(monitorToUse<1 || monitorToUse>countOfMonitors) {
            cout<<"Which monitor do you want to use? (1-"<<countOfMonitors<<"): ";
            cin>>monitorToUse;
            if(monitorToUse<1 || monitorToUse>countOfMonitors)
                cout<<"Invalid input!"<<endl;
        }
    }
    cout<<"Getting information on monitor number "<<monitorToUse<<"\n";
    monitorToUse--;
    MONITORINFO result;
    result.cbSize = sizeof(MONITORINFO);

    int gridSize = closestPerfectSquare(processesFound.size());

    GetMonitorInfoA(monitorDetection::monitors.at(monitorToUse),&result);

    POINT workspace;
    workspace.x = abs(result.rcWork.left-result.rcWork.right);
    workspace.y = abs(result.rcWork.top-result.rcWork.bottom);

    POINT sizeOfWindow;
    sizeOfWindow.x = workspace.x/sqrt(gridSize);
    sizeOfWindow.y = workspace.y/sqrt(gridSize);

    cout<<"True Resolution (without StartBar): "<<workspace.x<<"x"<<workspace.y<<endl;
    cout<<"Determined closest perfect square to be "<<gridSize<<" ("<<sqrt(gridSize)<<"x"<<sqrt(gridSize)<<")\n";
    cout<<"Ideal size for window: "<<sizeOfWindow.x<<"x"<<sizeOfWindow.y<<endl;



    int cont = 0;
    for(int i=0; i<sqrt(gridSize); i++) {
        for(int j=0; j<sqrt(gridSize); j++) {
            POINT pos;
            pos.y = result.rcWork.top+i*sizeOfWindow.y;
            pos.x = result.rcWork.left+j*sizeOfWindow.x;
            if(cont>=processesFound.size())
                break;
            HWND window = processesFound.at(cont);
            SetWindowPos(window,0,pos.x,pos.y,sizeOfWindow.x,sizeOfWindow.y,SWP_NOOWNERZORDER);

            cont++;
        }
    }


    return 0;
}
