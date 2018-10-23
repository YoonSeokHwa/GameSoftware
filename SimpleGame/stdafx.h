#pragma once

#include "targetver.h"
#include "renderer.h"
#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <Windows.h>
#include <chrono>

using namespace std;


#define FRICTION_COEF 1.f //������ ũ��
#define GRAVITY 9.8f
#define KEY_FORCE 200.0f

using Time = std::chrono::high_resolution_clock;
using TimePoint = Time::time_point;
using TimeDuration = std::chrono::duration<float>;//����Ʈ�� ��.

const float UPDATE_FREQUENCY{ 1.f / 120.f };

float magnitude(float x, float y);