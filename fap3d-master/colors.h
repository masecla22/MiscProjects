#pragma once
#include "globals.h"
namespace fap3d {
namespace colors {
namespace names{
enum Color {
    BLACK, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN, LIGHTGRAY, DARKGRAY,
    LIGHTBLUE, LIGHTGREEN, LIGHTCYAN, LIGHTRED, LIGHTMAGENTA, YELLOW, WHITE
};
}
void setColor(names::Color col) {
    globals::color = col;
}
}
}
