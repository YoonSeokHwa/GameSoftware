#include "stdafx.h"
#include "object.h"


Object::Object()
{
}


Object::~Object()
{
}

void Object::SetPosition(float x, float y, float z){ m_posX = x; m_posY = y;}

void Object::SetColor(float r, float g, float b, float a){ m_A = a; m_R = r; m_B = b; m_G = g;}

void Object::SetSize(float width, float height) { m_height = height; m_width = width; }

void Object::SetMass(float mass){ m_mass = mass;}

void Object::Update(float eTime)
{
	
	m_animationIndex += eTime;

	//속도의 크기 구하기
	float velocity = sqrt((m_velX * m_velX) + (m_velY * m_velY));

	if (velocity > FLT_EPSILON)//속도가 있으면.
	{


		float gz = GRAVITY * m_mass;//중력가속도. 중력 속도 * 질량.
		float friction = FRICTION_COEF * gz;//마찰력 값

		float frictionVelX, frictionVelY;
		frictionVelX = -friction * m_velX / velocity;
		frictionVelY = -friction * m_velY / velocity;


		float frictionAccX, frictionAccY;
		frictionAccX = frictionVelX / m_mass;
		frictionAccY = frictionVelY / m_mass;

		float afterVelX, afterVelY;
		afterVelX = m_velX + (frictionAccX*eTime);
		afterVelY = m_velY + (frictionAccY*eTime);

		if (afterVelX * m_velX < 0.0f)
			m_velX = 0.0f;
		else
			m_velX = m_velX + (frictionAccX * eTime);

		if (afterVelY * m_velY < 0.0f)
			m_velY = 0.0f;
		else
			m_velY = m_velY + (frictionAccY * eTime);

	/*	m_velX = m_velX + (frictionAccX * eTime);
		m_velY = m_velY + (frictionAccY * eTime);*/
	}

	float accX = (m_forceX / m_mass);
	float accY = (m_forceY / m_mass);

	m_velX = m_velX + accX * eTime;
	m_velY = m_velY + accY * eTime;


	m_posX = m_posX + (m_velX*eTime);
	m_posY = m_posY + (m_velY*eTime);
}

void Object::Draw(Renderer* renderer, GLuint tex)
{
	if (tex != NULL)
		renderer->DrawTextureRectSeqXY(m_posX, m_posY, 0, m_width, (m_height), m_R, m_G, m_B, m_A, tex, (int)m_animationIndex%m_totalAnimationIndex, 0, m_totalAnimationIndex,1);
	else
		renderer->DrawSolidRect(m_posX, m_posY, 0, m_width, (m_height), m_R, m_G, m_B, m_A);
}

void Object::ApplyForce(float x, float y)
{
	m_forceX += x;
	m_forceY += y;
}

Rect Object::GetRect()
{
	return { (m_posX - m_width / 2),(m_posY - m_height / 2),(m_posX + m_width / 2),(m_posY + m_height / 2) };
}
