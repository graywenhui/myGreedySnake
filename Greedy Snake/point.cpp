#pragma once
#include "point.h"
#include "tools.h"
#include <iostream>
void Point::Print()//输出方块
{
	SetCursorPosition(m_X,m_Y);
	std::cout << "■";//两个标的位置 构成地图的边界
}
void Point::PrintCircular()//输出圆形 构成蛇的身体
{
	SetCursorPosition(m_X, m_Y);
	std::cout << "●";
}
void Point::Clear()//清除输出
{
	SetCursorPosition(m_X, m_Y);
	std::cout << "  ";//覆盖掉之前的图形
}
void Point::ChangePosion(const int x, const int y)
{
	this->m_X = x;
	this->m_Y = y;
}