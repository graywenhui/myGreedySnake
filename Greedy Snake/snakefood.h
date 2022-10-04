#pragma once
#include <deque>
#include "point.h"
//enum class Direction { UP, DOWN, LEFT, RIGHT };
class Food;
class Snake;
class Food
{
	friend class Snake;//������Ԫ�����Է���˽������
public:
	Food() :cnt(0), flash_Flag(false), big_Flag(false), m_X(0), m_Y(0), big_X(0), big_Y(0), progress_Bar(0)/*,poison_X(0),poison_Y(0)*/ {}
	void DrawFood(Snake&);
	void DrawBigFood(Snake&);
	void DrawPoison(Snake&);
	void FlashBigFood();
	int GetCnt() {
		return cnt;
	}
	bool GetBigFlag()
	{
		return big_Flag;
	}
	int GetProgressBar()
	{
		return progress_Bar;
	}
private:
	int cnt;
	bool flash_Flag;//��˸���
	bool big_Flag; //��ʱ���
	int m_X;//��ͨʳ���x����
	int m_Y;//��ͨʳ���y����
	int big_X;//����ʳ���x����
	int big_Y;//����ʳ���y����
	int poison_X;//��ҩ��x����
	int poison_Y;//��ҩ��y����
	int progress_Bar;//��ʱʳ�������
};
class Snake
{
	friend class Food;//������Ϊ��Ԫ
public:
	enum Direction { UP, DOWN, LEFT, RIGHT };
	Snake()
	{
		m_Snake.emplace_front(14, 8);
		m_Snake.emplace_front(15, 8);
		m_Snake.emplace_front(16, 8);
		m_Direction = Direction::DOWN;
	}
	void InitSnake();
	void Move();
	void BigMove();
	void NormalMove();
	void EatPoison();
	bool OverEdge();
	bool HitItself();
	bool ChangeDirection();
	bool GetFood(const Food&);
	bool GetBigfood(Food&);
	bool GetPoison(Food&);
private:
	std::deque<Point> m_Snake;
	Direction m_Direction;
};