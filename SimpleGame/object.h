#pragma once
class object	 //그리는거 모아논거
{
public:
	float m_PosX;
	float m_PosY;
	float m_R;
	float m_G;
	float m_B;
	float m_A;
	float m_Width;
	float m_Height;
	///////업데이트//////////////
	float m_mass = 0;
	float m_AccX = 0, m_AccY = 0;//X가속도,Y가속도 
	float m_Velx = 0, m_Vely = 0;//x속도, y속도
	float m_FrictionCoef = 0.2;//마찰력 힘의 크기

public:
	object();
	~object();

	void SetPosition(float x, float y, float z);
	void SetColor(float r, float g, float b, float a);
	void SetSize(float width, float height);
	void SetMess(float mess);
	void Update(float eTime);
	void Draw(Renderer* renderer);
	void ApplyForce(float x, float y, float eTime);

};

