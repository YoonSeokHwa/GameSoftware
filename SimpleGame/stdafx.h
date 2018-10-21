#pragma once

#include "targetver.h"
#include "renderer.h"
#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <Windows.h>

using namespace std;


#define FRICTION_COEF 0.2f //¸¶Âû·Â Å©±â
#define GRAVITY 9.8f
#define KEY_FORCE 10.0f
#define OBJECT_SPEED 0.1f

float magnitude(float x, float y);