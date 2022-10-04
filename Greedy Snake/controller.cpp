#pragma once
#include <iostream>
#include <time.h>
#include <conio.h>//
#include <windows.h>//
#include "controller.h"
#include "tools.h"
#include "startinterface.h"
#include "map.h"
#include "snakefood.h"
void Controller::Start()//开始界面
{
	SetWindowSize(44,44);//设置窗口大小
	SetColor(2);//设置开始动画颜色
	StartInterface start;
	start.Action();//开始动画

	/*设置光标位置，并输出提示，等待任意键输入结束*/
	SetCursorPosition(13, 27);
	system("pause");

}
void Controller::Select()
{
	/*初始化界面选项*/
	SetColor(3);
	SetCursorPosition(13, 26);
	std::cout << "                          ";
	SetCursorPosition(13, 27);
	std::cout << "                          ";
	SetCursorPosition(6, 21);
	std::cout << "请选择游戏难度：";
	SetCursorPosition(6, 22);
	std::cout << "(上下键选择,回车确认)";
	SetCursorPosition(27, 22);
	SetBackColor();//第一个选项设置背景色以表示当前选中
	std::cout << "简单模式";
	SetCursorPosition(27, 24);
	SetColor(3);
	std::cout << "普通模式";
	SetCursorPosition(27, 26);
	std::cout << "困难模式";
	SetCursorPosition(27, 28);
	std::cout << "炼狱模式";
	SetCursorPosition(0, 31);
	m_Score = 0;

	/*上下方向键选择模块*/
	int ch;//记录键入值
	m_Key = 1;//初始选择第一个
	bool enterflag = false;//是否按下enter键
	while (ch = _getch())
	{
		switch (ch)//检测输入键
		{
		case 72://UP上方向键
			if (m_Key > 1)//当此时选中项为第一项时，UP上方向键无效
			{
				switch (m_Key)
				{
				case 2:
					SetCursorPosition(27, 22);//给待选中项设置背景色
					SetBackColor();
					std::cout << "简单模式";

					SetCursorPosition(27, 24);//将已选中项取消我背景色
					SetColor(3);
					std::cout << "普通模式";

					--m_Key;
					break;
				case 3:
					SetCursorPosition(27, 24);
					SetBackColor();
					std::cout << "普通模式";

					SetCursorPosition(27, 26);
					SetColor(3);
					std::cout << "困难模式";

					--m_Key;
					break;
				case 4:
					SetCursorPosition(27, 26);
					SetBackColor();
					std::cout << "困难模式";

					SetCursorPosition(27, 28);
					SetColor(3);
					std::cout << "炼狱模式";

					--m_Key;
					break;
				}
			}
			break;

		case 80://DOWN下方向键
			if (m_Key < 4)//当此时选中项为第四项时，向下键失效
			{
				switch (m_Key)
				{
				case 1:
					SetCursorPosition(27, 24);
					SetBackColor();
					std::cout << "普通模式";
					SetCursorPosition(27, 22);
					SetColor(3);
					std::cout << "简单模式";

					++m_Key;
					break;
				case 2:
					SetCursorPosition(27, 26);
					SetBackColor();
					std::cout << "困难模式";
					SetCursorPosition(27, 24);
					SetColor(3);
					std::cout << "普通模式";

					++m_Key;
					break;
				case 3:
					SetCursorPosition(27, 28);
					SetBackColor();
					std::cout << "炼狱模式";
					SetCursorPosition(27, 26);
					SetColor(3);
					std::cout << "困难模式";

					++m_Key;
					break;
				}
			}
			break;

		case 13:// Enter回车键
			enterflag = true;
			break;
		default://无效按键
			break;
		}
		if (enterflag) break;//输入Enter回车键确认，退出检查输入循环

		SetCursorPosition(0, 31);//将光标置于左下角，避免关标闪烁影响游戏体验

		switch (m_Key)
		{
		case 1:
			m_Speed = 135;
			break;
		case 2:
			m_Speed = 100;
			break;
		case 3:
			m_Speed = 65;
			break;
		case 4:
			m_Speed = 30;
			break;
		default:
			break;
		}
	}
}
void Controller::DrawGame()//绘制游戏界面
{
	system("cls");//清除屏幕

	/*绘制地图*/
	SetColor(3);
	Map initmap;
	initmap.PrintInitmap();

	/*绘制侧边栏*/
	SetColor(3);
	SetCursorPosition(33, 1);
	std::cout << "Greedy Snake";
	SetCursorPosition(34, 2);
	std::cout << "贪吃蛇";
	SetCursorPosition(31, 4);
	std::cout << "难度：";
	SetCursorPosition(36, 5);
	switch (m_Key)
	{
	case 1:
		std::cout << "简单模式";
		break;
	case 2:
		std::cout << "普通模式";
		break;
	case 3:
		std::cout << "困难模式";
		break;
	case 4:
		std::cout << "炼狱模式";
		break;
	default:
		break;
	}
	SetCursorPosition(31, 7);
	std::cout << "得分：";
	SetCursorPosition(37, 8);
	std::cout << "     0";
	SetCursorPosition(33, 13);
	std::cout << " 方向键移动";
	SetCursorPosition(33, 15);
	std::cout << " ESC键暂停";
}
int Controller::PlayGame()//游戏二级循环?
{
	/*初始化*/
	Snake csnake;
	Food cfood;
	SetColor(6);
	csnake.InitSnake();
	srand((unsigned)time(NULL));
	cfood.DrawFood(csnake);

	/*游戏循环*/
	while (csnake.OverEdge()&&csnake.HitItself())//判断是否撞墙或者吃到自己
	{
		/*调出选择菜单*/
		if (!csnake.ChangeDirection()) //按Esc键时
		{
			int tmp = Menu();//绘制菜单，并得到返回值
			switch (tmp)
			{
			case 1://继续游戏
				break;
			case 2://重新开始
				return 1;//将1作为PlayGame函数的返回值返回到Game函数中，表示重新开始

			case 3://退出游戏
				return 2;//将2作为PlayGame函数的返回值返回到Game函数中，表示退出游戏

			default:
				break;
			}
		}

		if (csnake.GetFood(cfood))
		{
			csnake.Move();//蛇增长移动
			UpdateScore(1);
			RewriteScore();
			cfood.DrawFood(csnake);
		}
		else
		{
			csnake.NormalMove();//蛇正常移动
		}
		
		if (csnake.GetBigfood(cfood))
		{
			csnake.BigMove();//增长2个单位
			UpdateScore(cfood.GetProgressBar() / 5);//分数根据限时食物进度条决定
			RewriteScore();
		}
		if (csnake.GetPoison(cfood))
		{
			csnake.EatPoison();
			UpdateScore(-1);
			RewriteScore();
		}

		if (cfood.GetBigFlag())//如果有限时食物，闪烁它
		{
			cfood.FlashBigFood();
		}

		Sleep(m_Speed);
	}

	int tmp = GameOver();
	switch (tmp)
	{
	case 1:
		return 1;//重新开始
	case 2:
		return 2;//退出游戏
	default:
		return 2;
	}
}
void Controller::UpdateScore(const int& tmp)
{
	m_Score += m_Key * 10 * tmp; //分数由不同因数确定
}
void Controller::RewriteScore()
{
	/*为保持分数尾部对齐，将最大分数设置为6位，计算当前分数位数，将剩余位数用空格补全，再输出分数*/
	SetCursorPosition(37, 8);
	SetColor(11);
	int bit = 0;
	int tmp = m_Score;
	while (tmp != 0)
	{
		++bit;
		tmp /= 10;
	}
	for (int i = 0; i < (6 - bit); ++i)
	{
		std::cout << " ";
	}
	std::cout << m_Score;
}
int Controller::Menu()//选择菜单
{
	/*绘制菜单*/
	SetColor(11);
	SetCursorPosition(32, 19);
	std::cout << "菜单：";
	Sleep(100);
	SetCursorPosition(34, 21);
	SetBackColor();
	std::cout << "继续游戏";
	Sleep(100);
	SetCursorPosition(34, 23);
	SetColor(11);
	std::cout << "重新开始";
	Sleep(100);
	SetCursorPosition(34, 25);
	std::cout << "退出游戏";
	SetCursorPosition(0, 31);

	/*选择部分*/
	int ch;
	int tmp_key = 1;
	bool flag = false;
	while (ch = _getch())
	{
		switch (ch)
		{
		case 72://UP
			if (tmp_key > 1)
			{
				switch (tmp_key)
				{
				case 2:
					SetCursorPosition(34, 21);
					SetBackColor();
					std::cout << "继续游戏";
					SetCursorPosition(34, 23);
					SetColor(11);
					std::cout << "重新开始";

					--tmp_key;
					break;
				case 3:
					SetCursorPosition(34, 23);
					SetBackColor();
					std::cout << "重新开始";
					SetCursorPosition(34, 25);
					SetColor(11);
					std::cout << "退出游戏";

					--tmp_key;
					break;
				}
			}
			break;

		case 80://DOWN
			if (tmp_key < 3)
			{
				switch (tmp_key)
				{
				case 1:
					SetCursorPosition(34, 23);
					SetBackColor();
					std::cout << "重新开始";
					SetCursorPosition(34, 21);
					SetColor(11);
					std::cout << "继续游戏";

					++tmp_key;
					break;
				case 2:
					SetCursorPosition(34, 25);
					SetBackColor();
					std::cout << "退出游戏";
					SetCursorPosition(34, 23);
					SetColor(11);
					std::cout << "重新开始";

					++tmp_key;
					break;
				}
			}
			break;

		case 13://Enter
			flag = true;
			break;

		default:
			break;
		}

		if (flag)
		{
			break;
		}
		SetCursorPosition(0, 31);
	}

	if (tmp_key == 1) //选择继续游戏，则将菜单擦除
	{
		SetCursorPosition(32, 19);
		std::cout << "      ";
		SetCursorPosition(34, 21);
		std::cout << "        ";
		SetCursorPosition(34, 23);
		std::cout << "        ";
		SetCursorPosition(34, 25);
		std::cout << "        ";
	}
	return tmp_key;
}
void Controller::Game()
{
	Start();//开始界面
	while (true)
	{
		Select();
		DrawGame();
		int tmp = PlayGame();
		if (tmp == 1) //返回值为1时重新开始游戏
		{
			system("cls");
			continue;
		}
		else if (tmp == 2) //返回值为2时退出游戏
		{
			break;
		}
		else
		{
			break;
		}
	}
}
int Controller::GameOver()
{
	/*绘制游戏结束界面*/
	Sleep(500);
	SetColor(11);
	SetCursorPosition(10, 8);
	std::cout << "━━━━━━━━━━━━━━━━━━━━━━";
	Sleep(30);
	SetCursorPosition(9, 9);
	std::cout << " ┃               Game Over !!!              ┃";
	Sleep(30);
	SetCursorPosition(9, 10);
	std::cout << " ┃                                          ┃";
	Sleep(30);
	SetCursorPosition(9, 11);
	std::cout << " ┃              很遗憾！你挂了              ┃";
	Sleep(30);
	SetCursorPosition(9, 12);
	std::cout << " ┃                                          ┃";
	Sleep(30);
	SetCursorPosition(9, 13);
	std::cout << " ┃             你的分数为：                 ┃";
	SetCursorPosition(24, 13);
	std::cout << m_Score;
	Sleep(30);
	SetCursorPosition(9, 14);
	std::cout << " ┃                                          ┃";
	Sleep(30);
	SetCursorPosition(9, 15);
	std::cout << " ┃   是否再来一局？                         ┃";
	Sleep(30);
	SetCursorPosition(9, 16);
	std::cout << " ┃                                          ┃";
	Sleep(30);
	SetCursorPosition(9, 17);
	std::cout << " ┃                                          ┃";
	Sleep(30);
	SetCursorPosition(9, 18);
	std::cout << " ┃    嗯，好的        不了，还是学习有意思  ┃";
	Sleep(30);
	SetCursorPosition(9, 19);
	std::cout << " ┃                                          ┃";
	Sleep(30);
	SetCursorPosition(9, 20);
	std::cout << " ┃                                          ┃";
	Sleep(30);
	SetCursorPosition(10, 21);
	std::cout << "━━━━━━━━━━━━━━━━━━━━━━";

	Sleep(100);
	SetCursorPosition(12, 18);
	SetBackColor();
	std::cout << "嗯，好的";
	SetCursorPosition(0, 31);

	/*选择部分*/
	int ch;
	int tmp_key = 1;
	bool flag = false;
	while (ch = _getch())
	{
		switch (ch)
		{
		case 75://LEFT
			if (tmp_key > 1)
			{
				SetCursorPosition(12, 18);
				SetBackColor();
				std::cout << "嗯，好的";
				SetCursorPosition(20, 18);
				SetColor(11);
				std::cout << "不了，还是学习有意思";
				--tmp_key;
			}
			break;

		case 77://RIGHT
			if (tmp_key < 2)
			{
				SetCursorPosition(20, 18);
				SetBackColor();
				std::cout << "不了，还是学习有意思";
				SetCursorPosition(12, 18);
				SetColor(11);
				std::cout << "嗯，好的";
				++tmp_key;
			}
			break;

		case 13://Enter
			flag = true;
			break;

		default:
			break;
		}

		SetCursorPosition(0, 31);
		if (flag) {
			break;
		}
	}

	SetColor(11);
	switch (tmp_key)
	{
	case 1:
		return 1;//重新开始
	case 2:
		return 2;//退出游戏
	default:
		return 1;
	}
}
