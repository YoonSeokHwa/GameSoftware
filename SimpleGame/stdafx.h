#pragma once

#include "targetver.h"
#include "renderer.h"
#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <Windows.h>
#include <chrono>
#include <vector>

using namespace std;



#define PLAYER 0
#define FRICTION_COEF 5.f //마찰력 크기
#define GRAVITY 9.8f
#define KEY_FORCE 1000.0f

using Time = std::chrono::high_resolution_clock;
using TimePoint = Time::time_point;
using TimeDuration = std::chrono::duration<float>;//디폴트는 초.

struct Rect
{
	float minx;
	float miny;
	float maxx;
	float maxy;
};

const float UPDATE_FREQUENCY{ 1.f / 120.f };

float magnitude(float x, float y);


bool isCollide(Rect &standard, Rect &compare);