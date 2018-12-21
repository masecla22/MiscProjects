#include <iostream>
#include <fstream>
#include <windows.h>
#include <cstring>
#include <iomanip>
#include <cstdlib>
#include <conio.h>
#include <windows.h>

void clear() {
    COORD topLeft  = { 0, 0 };
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(console, topLeft);
}
bool fexists(const char *filename) {
  std::ifstream ifile(filename);
  return (bool)ifile;
}
