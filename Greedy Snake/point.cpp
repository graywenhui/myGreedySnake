#pragma once
#include "point.h"
#include "tools.h"
#include <iostream>
void Point::Print()//�������
{
	SetCursorPosition(m_X,m_Y);
	std::cout << "��";//�������λ�� ���ɵ�ͼ�ı߽�
}
void Point::PrintCircular()//���Բ�� �����ߵ�����
{
	SetCursorPosition(m_X, m_Y);
	std::cout << "��";
}
void Point::Clear()//������
{
	SetCursorPosition(m_X, m_Y);
	std::cout << "  ";//���ǵ�֮ǰ��ͼ��
}
void Point::ChangePosion(const int x, const int y)
{
	this->m_X = x;
	this->m_Y = y;
}