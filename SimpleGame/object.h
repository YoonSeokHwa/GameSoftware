#pragma once
class object	 //그리는거 모아논거
{
public:
	float m_posX;
	float m_posY;
	float m_R;
	float m_G;
	float m_B;
	float m_A;
	float m_width;
	float m_height;
	/////// 속도계산////////
	float m_forceX = 0, m_forceY = 0;
	float m_mass = 0;
	float m_accX = 0, m_accY = 0;//X가속도,Y가속도 
	float m_velX = 0, m_velY = 0;//x속도, y속도
	//이전 위치
	float m_prevX = 0, m_prevY = 0;

public:
	object();
	~object();

	void SetPosition(float x, float y, float z);
	void SetColor(float r, float g, float b, float a);
	void SetSize(float width, float height);
	void SetMess(float mess);
	void Update(float eTime);
	void Draw(Renderer* renderer, GLuint tex = NULL);
	void ApplyForce(float x, float y);

};

