#pragma once
class Point
{
public:
	Point() = default;
	Point(const int x,const int y):m_X(x),m_Y(y){}
	void Print();
	void PrintCircular();
	void Clear();
	void ChangePosion(const int x,const int y);
	bool operator== (const Point& point)//ÖØÔØ==ÔËËã·û
	{
		return (point.m_X==this->m_X) && (point.m_Y == this->m_Y);
	}
	int GetX()
	{
		return this->m_X;
	}
	int GetY()
	{
		return this->m_Y;
	}
private:
	int m_X;
	int m_Y;
};