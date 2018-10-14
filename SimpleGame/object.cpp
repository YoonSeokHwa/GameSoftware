#include "stdafx.h"
#include "object.h"


object::object()
{
}


object::~object()
{
}

void object::SetPosition(float x, float y, float z){ m_PosX = x; m_PosY = y;}

void object::SetColor(float r, float g, float b, float a){ m_A = a; m_R = r; m_B = b; m_G = g;}

void object::SetSize(float width, float height) { m_Height = height; m_Width = width; }

void object::SetMess(float mass){ m_mass = mass;}

void object::Update(float eTime)
{
	//m_PosX += m_mass*time;
	float velocity = sqrtf(m_Velx*m_Vely + m_Velx + m_Vely); //속도의 크기 size of velocity
	if (velocity < FLT_EPSILON) {

	}
	else {
		//gravity force
		float gz;
		gz = 9.8 * m_mass;	//수직항력
		float friction;
		friction = m_FrictionCoef * gz; //마찰력의 크기

		//마찰력의 방향 friction
		float fx, fy, size;
		fx = -friction * m_Velx / velocity;
		fy = -friction * m_Vely / velocity;

		//백터 노말라이징제이션

		//가속도 Calc acc
		float accX, accY;
		accX = fx / m_mass;
		accY = fy / m_mass;
		m_Velx = m_Velx + eTime * accX;
		m_Vely = m_Vely + eTime * accY;
	}
	m_Velx = m_Velx - eTime * 0.2;
	m_Velx = m_Velx + eTime * m_AccX;
	m_Vely = m_Vely + eTime * m_AccY;
//calc position
	m_PosX = m_PosX + eTime * m_Velx;
	m_PosY = m_PosX + eTime * m_Vely;


}

void object::Draw(Renderer* renderer, GLuint tex)
{
	if (tex != NULL)
		renderer->DrawTextureRect(m_PosX, m_PosY, 0, m_Width, m_Height, 1, 1, 1, 1, tex);
	else
		renderer->DrawSolidRect(m_PosX, m_PosY, 0, m_Width, m_Height, m_R, m_G, m_B, m_A);
}

void object::ApplyForce(float x, float y, float eTime)
{
	m_AccX = x / m_mass; //  x힘의 크기 / 무게
	m_AccY = y / m_mass; //  y힘의 크기 / 무게

	m_Velx = m_Velx + m_AccX * eTime;// 현재속도 + x가속도 * 프레임 사이 흐른 시간
	m_Vely = m_Vely + m_AccY * eTime;// 현재속도 + y가속도 * 프레임 사이 흐른 시간

	//m_AccX = o.f;
	//m_Accy = o.f;
}
