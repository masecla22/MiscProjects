#include <iostream>
#include "fap3d.h"
#include <windows.h>
#include <vector>
#include <ctime>
#include <random>

using namespace fap3d::setup;
using namespace fap3d::shapes::bidimensional;
using namespace fap3d::colors;
using namespace fap3d;

int main() {
    Window d = Window(0,0,900,600);
    d.open();

    _getch();
    return 0;
}
