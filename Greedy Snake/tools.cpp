#pragma once
#include "tools.h"
#include <Windows.h>
#include <cstdio>
void SetWindowSize(int cols, int lines)
{
	system("title 贪吃蛇");
	char cmd[30];
	sprintf_s(cmd,"mode con cols=%d lines=%d", cols * 2,lines);//一个图形占两个字符，故宽度乘以2
	system(cmd);
}
void SetCursorPosition(const int x, const int y)
{
	COORD position;
	position.X = x * 2;
	position.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
}
void SetColor(int colorID)//文本颜色
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),colorID);
}
void SetBackColor()//文本背景色
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_RED);
}
