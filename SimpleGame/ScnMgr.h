#pragma once

#include "object.h"

class ScnMgr
{
	Renderer *m_render;
	vector<Object*> m_vAlly;
	vector<Object*> m_vEnemy;
	GLuint m_ZzangTex;
	
public:
	ScnMgr();
	~ScnMgr();


	void MakeAlly(float x, float y, float z, float w, float h, float r, float g, float b, float a);
	void MakeEnemy(float x, float y, float z, float w, float h, float r, float g, float b, float a);
	void CollisionCheck();

	void Draw();
	void Update(float time);
	void KeyInput(unsigned char key, int x, int y);
	void KeyUpInput(unsigned char key, int x, int y);
};

