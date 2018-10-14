#pragma once
class object	 //�׸��°� ��Ƴ��
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
	/////// �ӵ����////////
	float m_forceX = 0, m_forceY = 0;
	float m_mass = 0;
	float m_accX = 0, m_accY = 0;//X���ӵ�,Y���ӵ� 
	float m_velX = 0, m_velY = 0;//x�ӵ�, y�ӵ�

public:
	object();
	~object();

	void SetPosition(float x, float y, float z);
	void SetColor(float r, float g, float b, float a);
	void SetSize(float width, float height);
	void SetMess(float mess);
	void Update(float eTime);
	void Draw(Renderer* renderer, GLuint tex = NULL);
	void ApplyForce(float x, float y, float eTime);

};

