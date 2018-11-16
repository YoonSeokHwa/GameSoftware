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
	MakeAlly(0, 0, 0, 100, 100, 1, 0, 1, 1);

	for (int i = 0; i < 5; i++)
	{
		MakeEnemy(rand() % 500 - 250, rand() % 500 - 250, 0, 100, 100, 0, 1, 1,1);
	}
}


ScnMgr::~ScnMgr()
{
}

void ScnMgr::Draw()
{
	for (auto& object:m_vAlly)
	{
		object->Draw(m_render,m_ZzangTex);
	}
	for (auto& object : m_vEnemy)
	{
		object->Draw(m_render);
	}
}

void ScnMgr::MakeAlly(float x, float y, float z, float w, float h, float r, float g, float b, float a)
{
	
	Object* obj = new Object();

	obj->SetSize(w, h);
	obj->SetColor(r, g, b, a);
	obj->SetPosition(x, y,0);
	obj->SetMass(10.f);


	m_vAlly.push_back(obj);
}

void ScnMgr::MakeEnemy(float x, float y, float z, float w, float h, float r, float g, float b, float a)
{
	Object* obj = new Object();

	obj->SetSize(w, h);
	obj->SetColor(r, g, b, a);
	obj->SetPosition(x, y, 0);
	obj->SetMass(10.f);


	m_vEnemy.push_back(obj);
}

void ScnMgr::CollisionCheck()
{
	Rect playerRect = m_vAlly[PLAYER]->GetRect();
	for (auto& enemy : m_vEnemy)
	{
		if (isCollide(playerRect, enemy->GetRect()) == true)
		{
			enemy->SetColor(1, 0, 0, 1);
		}
	}
}

void ScnMgr::Update(float time)
{
	CollisionCheck();

	for (auto& object : m_vAlly)
	{
		object->Update(time);
	}
	for (auto& object : m_vEnemy)
	{
		object->Update(time);
	}
}
	
void ScnMgr::KeyInput(unsigned char key, int x, int y)
{
	if (key == 'w')
	{
		m_vAlly[PLAYER]->ApplyForce(0, KEY_FORCE);
	}
	if (key == 's')
	{
		m_vAlly[PLAYER]->ApplyForce(0, -KEY_FORCE);
	}
	if (key == 'd')
	{
		m_vAlly[PLAYER]->ApplyForce(KEY_FORCE, 0);
	}
	if (key == 'a')
	{
		m_vAlly[PLAYER]->ApplyForce(-KEY_FORCE, 0);
	}
}

void ScnMgr::KeyUpInput(unsigned char key, int x, int y)
{
	if (key == 'w')
	{
		m_vAlly[PLAYER]->ApplyForce(0, -KEY_FORCE);
	}
	if (key == 's')
	{
		m_vAlly[PLAYER]->ApplyForce(0, KEY_FORCE);
	}
	if (key == 'd')
	{
		m_vAlly[PLAYER]->ApplyForce(-KEY_FORCE, 0);
	}
	if (key == 'a')
	{
		m_vAlly[PLAYER]->ApplyForce(KEY_FORCE, 0);
	}
}
