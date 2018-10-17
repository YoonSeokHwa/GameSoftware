#include "stdafx.h"
#include "object.h"


object::object()
{
}


object::~object()
{
}

void object::SetPosition(float x, float y, float z){ m_posX = x; m_posY = y;}

void object::SetColor(float r, float g, float b, float a){ m_A = a; m_R = r; m_B = b; m_G = g;}

void object::SetSize(float width, float height) { m_height = height; m_width = width; }

void object::SetMess(float mass){ m_mass = mass;}

void object::Update(float eTime)
{
	float fSpeed = magnitude(m_velX, m_velY);
	if (fSpeed)
	{
		float fPreviousVelocityX = m_velX;
		float fPreviousVelocityY = m_velY;

		float fFriction = FRICTION_COEF * m_mass * GRAVITY;
		float fForceX = -fFriction * m_velX / fSpeed;
		float fForceY = -fFriction * m_velY / fSpeed;

		m_velX += eTime * (fForceX / m_mass);
		m_velY += eTime * (fForceY / m_mass);

		//Fixes issue of friction subtracting more than needed (best way?)
		if (m_velX * fPreviousVelocityX < 0.f)
			m_velX = 0.f;
		if (m_velY * fPreviousVelocityY < 0.f)
			m_velY = 0.f;
	}

	m_velX += eTime * (m_forceX / m_mass);
	m_velY += eTime * (m_forceY / m_mass);

	m_prevX = m_posX;
	m_prevY = m_posY;

	m_posX += eTime * m_velX;
	m_posY += eTime * m_velY;

}

void object::Draw(Renderer* renderer, GLuint tex)
{
	if (tex != NULL)
		renderer->DrawTextureRect(m_posX, m_posY, 0, m_width, m_height, 1, 1, 1, 1, tex);
	else
		renderer->DrawSolidRect(m_posX, m_posY, 0, m_width, m_height, m_R, m_G, m_B, m_A);
}

void object::ApplyForce(float x, float y)
{
	m_forceX = x;
	m_forceY = y;
}
