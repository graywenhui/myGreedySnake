#pragma once
#include <deque>
#include "point.h"
//enum class Direction { UP, DOWN, LEFT, RIGHT };
class Food;
class Snake;
class Food
{
	friend class Snake;//类做友元，可以访问私有属性
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
	bool flash_Flag;//闪烁标记
	bool big_Flag; //限时标记
	int m_X;//普通食物的x坐标
	int m_Y;//普通食物的y坐标
	int big_X;//特殊食物的x坐标
	int big_Y;//特殊食物的y坐标
	int poison_X;//毒药的x坐标
	int poison_Y;//毒药的y坐标
	int progress_Bar;//限时食物进度条
};
class Snake
{
	friend class Food;//将类作为友元
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