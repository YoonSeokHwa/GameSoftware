#pragma once

#include "object.h"

class ScnMgr
{
	Renderer *m_render;
	object *m_object[5];
	int index = 0;
	float m_time;
	
public:
	ScnMgr();
	~ScnMgr();

	void Draw();
	void MakeObject(float x, float y, float z, float w, float h, float r, float g, float b, float a);
	void Update(float time);
	void KeyInput(unsigned char key, int x, int y);
};

