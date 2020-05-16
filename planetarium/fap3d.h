#pragma once
#include "setup.h"
#include "shapes.h"
#include "globals.h"
#include "colors.h"
#ifndef __cplusplus
#error A C++ compiler is required!
#endif
#ifdef __cplusplus
#if __cplusplus < 201103L
#error The C++ version (C++99) you are currently using is incompatible with Fap3D. Please switch to C++11
#endif
#if __cplusplus>201103L
#warning The only C++ version supported by Fap3D is C++11. Any others are unsupported and were not tested.
#endif
#endif
