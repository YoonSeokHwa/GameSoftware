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
	///////������Ʈ//////////////
	float m_mass = 0;
	float m_AccX = 0, m_AccY = 0;//X���ӵ�,Y���ӵ� 
	float m_Velx = 0, m_Vely = 0;//x�ӵ�, y�ӵ�
	float m_FrictionCoef = 0.2;//������ ���� ũ��

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

