#pragma once
#include "snakefood.h"
#include "tools.h"
#include <cstdlib>
#include <iostream>
#include <ctime>
void Food::DrawFood(Snake& csnake)
{
	srand((unsigned int)time(NULL));//������������ӣ�����ÿ�����´����ɵ�������оͲ�һ����
	while (true)
	{
		int tmp_X = rand() % 28+2;
		int tmp_Y = rand() % 28+2;
		bool flag = false;//ʳ���Ƿ�����ظ��ı�־
		for (auto& point:csnake.m_Snake)
		{
			if ((point.GetX() == tmp_X && point.GetY() == tmp_Y)||(tmp_X == big_X)&&(tmp_Y == big_Y))
			{
				flag = true;
				break;
			}
		}
		if (flag)
		{
			continue;
		}
		m_X = tmp_X;
		m_Y = tmp_Y;
		SetCursorPosition(m_X, m_Y);
		SetColor(13);
		std::cout << "��";
		++cnt;
		cnt %= 5;
		if (cnt % 2 == 0)
		{
			DrawPoison(csnake);
		}
		if (cnt == 0)
		{
			DrawBigFood(csnake);
		}
		break;
	}
}
void Food::DrawBigFood(Snake& csnake)
{
	SetCursorPosition(5, 0);
	SetColor(11);
	std::cout << "------------------------------------------";//������
	progress_Bar = 42;
	while (true)
	{
		int tmp_X = rand() % 28 + 2;
		int tmp_Y = rand() % 28 + 2;
		bool flag = false;
		for (auto& point : csnake.m_Snake)
		{
			if ((point.GetX() == tmp_X && point.GetY() == tmp_Y) || (tmp_X == big_X) && (tmp_Y == big_Y))
			{
				flag = true;
				break;
			}
		}
		if (flag)
		{
			continue;
		}
		big_X = tmp_X;
		big_Y = tmp_Y;
		SetCursorPosition(big_X, big_Y);
		SetColor(18);
		std::cout << "��";
		big_Flag = true;
		flash_Flag = true;
		break;
	}
}
void Food::DrawPoison(Snake& csnake)
{
	while (true)
	{
		int tmp_X = rand() % 28 + 2;
		int tmp_Y = rand() % 28 + 2;
		bool flag = false;//ʳ���Ƿ�����ظ��ı�־
		for (auto& point : csnake.m_Snake)
		{
			if ((point.GetX() == tmp_X && point.GetY() == tmp_Y) || (tmp_X == big_X) && (tmp_Y == big_Y)||(tmp_X == m_X)&&(tmp_Y == m_Y))
			{
				flag = true;
				break;
			}
		}
		if (flag)
		{
			continue;
		}
		SetCursorPosition(poison_X, poison_Y);
		std::cout << "  ";
		poison_X = tmp_X;
		poison_Y = tmp_Y;
		SetCursorPosition(poison_X, poison_Y);
		SetColor(13);
		std::cout << "��";
		break;
	}
}
void Food::FlashBigFood()
{
	SetCursorPosition(big_X, big_Y);
	SetColor(18);
	if (flash_Flag)
	{
		std::cout << "  ";
		flash_Flag = false;
	}
	else
	{
		std::cout << "��";
		flash_Flag = true;
	}
	SetCursorPosition(26, 0);
	SetColor(11);
	for (int i = 42;i>=progress_Bar;--i)
	{
		std::cout << "\b\b";
	}
	--progress_Bar;
	if (progress_Bar == 0)
	{
		SetCursorPosition(big_X,big_Y);
		std::cout << "  ";
		big_Flag = false;
		big_X = 0;
		big_Y = 0;
	}
}