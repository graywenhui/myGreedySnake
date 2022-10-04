#pragma once
#include "snakefood.h"
#include "tools.h"
#include <iostream>
#include <conio.h>
void Snake::InitSnake()
{
	for (auto& point : m_Snake)
	{
		point.PrintCircular();
	}
}
void Snake::Move()
{
	NormalMove();
	int x = m_Snake.back().GetX() * 2 - m_Snake[m_Snake.size() - 2].GetX();
	int y = m_Snake.back().GetY() * 2 - m_Snake[m_Snake.size() - 2].GetY();
	m_Snake.emplace_back(Point(x,y));
	SetColor(14);
	m_Snake.back().PrintCircular();	
	SetCursorPosition(0,16);
}

void Snake::BigMove()//吃到限时食物，增长两倍
{
	int x = m_Snake.back().GetX() * 2 - m_Snake[m_Snake.size() - 2].GetX();
	int y = m_Snake.back().GetY() * 2 - m_Snake[m_Snake.size() - 2].GetY();
	m_Snake.emplace_back(Point(x, y));
	SetColor(14);
	m_Snake.back().PrintCircular();
	x = m_Snake.back().GetX() * 2 - m_Snake[m_Snake.size() - 2].GetX();
	y = m_Snake.back().GetY() * 2 - m_Snake[m_Snake.size() - 2].GetY();
	m_Snake.emplace_back(Point(x, y));
	SetColor(14);
	m_Snake.back().PrintCircular();
	SetCursorPosition(0, 16);
}

void Snake::NormalMove()//正常移动 头增长，尾缩短
{
	switch (m_Direction)
	{
	case Direction::UP:
		m_Snake.emplace_front(Point(m_Snake.front().GetX(), m_Snake.front().GetY() - 1));
		break;
	case Direction::DOWN:
		m_Snake.emplace_front(Point(m_Snake.front().GetX(), m_Snake.front().GetY() + 1));
		break;
	case Direction::LEFT:
		m_Snake.emplace_front(Point(m_Snake.front().GetX() - 1, m_Snake.front().GetY()));
		break;
	case Direction::RIGHT:
		m_Snake.emplace_front(Point(m_Snake.front().GetX() + 1, m_Snake.front().GetY()));
		break;
	default:
		break;
	}
	SetColor(14);
	m_Snake.front().PrintCircular();
	m_Snake.back().Clear();
	m_Snake.pop_back();
	SetCursorPosition(0,16);
}
void Snake::EatPoison()
{
	m_Snake.back().Clear();
	m_Snake.pop_back();
	SetCursorPosition(0, 16);
}
bool Snake::OverEdge()
{
	return m_Snake.front().GetX() > 1 && m_Snake.front().GetX() < 30 && m_Snake.front().GetY() > 1 && m_Snake.front().GetY() < 30;
}
bool Snake::HitItself()
{
	std::deque<Point>::size_type cnt = 1;
	Point test(m_Snake.front().GetX(),m_Snake.front().GetY());
	for (auto& point : m_Snake)
	{
		if (!(point == test))	++cnt;
		else if (point == test && cnt != 1)	break;
	}
	if (cnt == m_Snake.size()) return true;
	else	return false;
}
bool Snake::ChangeDirection()
{
	char ch;
	if (_kbhit()) //检测键盘是否有输入，如果有则返回非0 否则返回0
	{
		ch = _getch();
		switch (ch)
		{
		case -32:
			ch = _getch();
			switch (ch)
			{
			case 72:
				if (m_Direction != Direction::DOWN)	m_Direction = Direction::UP;
				break;
			case 80:
				if (m_Direction != Direction::UP)	m_Direction = Direction::DOWN;
				break;
			case 75:
				if (m_Direction != Direction::RIGHT)	m_Direction = Direction::LEFT;
				break;
			case 77:
				if (m_Direction != Direction::LEFT)	m_Direction = Direction::RIGHT;
				break;
			default:
				break;
			}
			return true;
		case 27://ESC
			return false;
		default:
			return true;
		}
	}
	return true;
}
bool Snake::GetFood(const Food& cfood)
{
	if (m_Snake.front().GetX() == cfood.m_X && m_Snake.front().GetY() == cfood.m_Y) return true;
	else return false;
}
bool Snake::GetBigfood(Food& cfood)
{
	if (m_Snake.front().GetX() == cfood.big_X && m_Snake.front().GetY() == cfood.big_Y)
	{
		cfood.big_Flag = false;
		cfood.big_X = 0;
		cfood.big_Y = 0;
		SetCursorPosition(1, 0);
		std::cout << "                                                            ";
		return true;
	}
	else return false;
}

bool Snake::GetPoison(Food& cfood)
{
	if (m_Snake.front().GetX() == cfood.poison_X && m_Snake.front().GetY() == cfood.poison_Y)
	{
		cfood.poison_X = 0;
		cfood.poison_Y = 0;                                                           ";
		return true;
	}
	else return false;
}
