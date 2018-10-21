#include "stdafx.h"
#include "ScnMgr.h"
#include <random>

ScnMgr::ScnMgr()
{
	m_render = new Renderer(500,500);
	//m_object = new object();

	if (!m_render->IsInitialized())
	{
		std::cout << "Renderer could not be initialized.. \n";
	}
	m_ZzangTex = m_render->CreatePngTexture("Zzang.png");
	MakeObject(0, 0, 0, 10, 10, 1, 0, 1, 1);
	/*m_object->SetColor(1, 0, 1, 0);
	m_object->SetPosition(10, 10, 0);
	m_object->SetSize(10, 10);*/
}


ScnMgr::~ScnMgr()
{
}

void ScnMgr::Draw()
{
	for (int i = 0; i < index; i++)
	{
		m_object[i]->Draw(m_render,m_ZzangTex);
	}
}

void ScnMgr::MakeObject(float x, float y, float z, float w, float h, float r, float g, float b, float a)
{
	
	m_object[index] = new object();

	m_object[index]->SetSize(w, h);
	m_object[index]->SetColor(r, g, b, a);
	m_object[index]->SetPosition(x, y,0);
	m_object[index]->SetMess(rand()%10+1);
	m_object[index]->SetVel(OBJECT_SPEED, OBJECT_SPEED);
	if (index < 4)
	{
		index += 1;
	}
}

void ScnMgr::Update(float time)
{
	m_time = time;
	for (int i = 0; i < index; i++)
	{
		m_object[i]->Update(time);
	}
}

void ScnMgr::KeyInput(unsigned char key, int x, int y)
{
	if (key == 'w')
	{
		m_object[0]->ApplyForce(0, KEY_FORCE);
	}
	if (key == 's')
	{
		m_object[0]->ApplyForce(0, -KEY_FORCE);
	}
	if (key == 'd')
	{
		m_object[0]->ApplyForce(KEY_FORCE, 0);
	}
	if (key == 'a')
	{
		m_object[0]->ApplyForce(-KEY_FORCE, 0);
	}
}

void ScnMgr::KeyUpInput(unsigned char key, int x, int y)
{
	m_object[0]->ApplyForce(0, 0);
}
