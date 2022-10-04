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
void Controller::Start()//��ʼ����
{
	SetWindowSize(44,44);//���ô��ڴ�С
	SetColor(2);//���ÿ�ʼ������ɫ
	StartInterface start;
	start.Action();//��ʼ����

	/*���ù��λ�ã��������ʾ���ȴ�������������*/
	SetCursorPosition(13, 27);
	system("pause");

}
void Controller::Select()
{
	/*��ʼ������ѡ��*/
	SetColor(3);
	SetCursorPosition(13, 26);
	std::cout << "                          ";
	SetCursorPosition(13, 27);
	std::cout << "                          ";
	SetCursorPosition(6, 21);
	std::cout << "��ѡ����Ϸ�Ѷȣ�";
	SetCursorPosition(6, 22);
	std::cout << "(���¼�ѡ��,�س�ȷ��)";
	SetCursorPosition(27, 22);
	SetBackColor();//��һ��ѡ�����ñ���ɫ�Ա�ʾ��ǰѡ��
	std::cout << "��ģʽ";
	SetCursorPosition(27, 24);
	SetColor(3);
	std::cout << "��ͨģʽ";
	SetCursorPosition(27, 26);
	std::cout << "����ģʽ";
	SetCursorPosition(27, 28);
	std::cout << "����ģʽ";
	SetCursorPosition(0, 31);
	m_Score = 0;

	/*���·����ѡ��ģ��*/
	int ch;//��¼����ֵ
	m_Key = 1;//��ʼѡ���һ��
	bool enterflag = false;//�Ƿ���enter��
	while (ch = _getch())
	{
		switch (ch)//��������
		{
		case 72://UP�Ϸ����
			if (m_Key > 1)//����ʱѡ����Ϊ��һ��ʱ��UP�Ϸ������Ч
			{
				switch (m_Key)
				{
				case 2:
					SetCursorPosition(27, 22);//����ѡ�������ñ���ɫ
					SetBackColor();
					std::cout << "��ģʽ";

					SetCursorPosition(27, 24);//����ѡ����ȡ���ұ���ɫ
					SetColor(3);
					std::cout << "��ͨģʽ";

					--m_Key;
					break;
				case 3:
					SetCursorPosition(27, 24);
					SetBackColor();
					std::cout << "��ͨģʽ";

					SetCursorPosition(27, 26);
					SetColor(3);
					std::cout << "����ģʽ";

					--m_Key;
					break;
				case 4:
					SetCursorPosition(27, 26);
					SetBackColor();
					std::cout << "����ģʽ";

					SetCursorPosition(27, 28);
					SetColor(3);
					std::cout << "����ģʽ";

					--m_Key;
					break;
				}
			}
			break;

		case 80://DOWN�·����
			if (m_Key < 4)//����ʱѡ����Ϊ������ʱ�����¼�ʧЧ
			{
				switch (m_Key)
				{
				case 1:
					SetCursorPosition(27, 24);
					SetBackColor();
					std::cout << "��ͨģʽ";
					SetCursorPosition(27, 22);
					SetColor(3);
					std::cout << "��ģʽ";

					++m_Key;
					break;
				case 2:
					SetCursorPosition(27, 26);
					SetBackColor();
					std::cout << "����ģʽ";
					SetCursorPosition(27, 24);
					SetColor(3);
					std::cout << "��ͨģʽ";

					++m_Key;
					break;
				case 3:
					SetCursorPosition(27, 28);
					SetBackColor();
					std::cout << "����ģʽ";
					SetCursorPosition(27, 26);
					SetColor(3);
					std::cout << "����ģʽ";

					++m_Key;
					break;
				}
			}
			break;

		case 13:// Enter�س���
			enterflag = true;
			break;
		default://��Ч����
			break;
		}
		if (enterflag) break;//����Enter�س���ȷ�ϣ��˳��������ѭ��

		SetCursorPosition(0, 31);//������������½ǣ�����ر���˸Ӱ����Ϸ����

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
void Controller::DrawGame()//������Ϸ����
{
	system("cls");//�����Ļ

	/*���Ƶ�ͼ*/
	SetColor(3);
	Map initmap;
	initmap.PrintInitmap();

	/*���Ʋ����*/
	SetColor(3);
	SetCursorPosition(33, 1);
	std::cout << "Greedy Snake";
	SetCursorPosition(34, 2);
	std::cout << "̰����";
	SetCursorPosition(31, 4);
	std::cout << "�Ѷȣ�";
	SetCursorPosition(36, 5);
	switch (m_Key)
	{
	case 1:
		std::cout << "��ģʽ";
		break;
	case 2:
		std::cout << "��ͨģʽ";
		break;
	case 3:
		std::cout << "����ģʽ";
		break;
	case 4:
		std::cout << "����ģʽ";
		break;
	default:
		break;
	}
	SetCursorPosition(31, 7);
	std::cout << "�÷֣�";
	SetCursorPosition(37, 8);
	std::cout << "     0";
	SetCursorPosition(33, 13);
	std::cout << " ������ƶ�";
	SetCursorPosition(33, 15);
	std::cout << " ESC����ͣ";
}
int Controller::PlayGame()//��Ϸ����ѭ��?
{
	/*��ʼ��*/
	Snake csnake;
	Food cfood;
	SetColor(6);
	csnake.InitSnake();
	srand((unsigned)time(NULL));
	cfood.DrawFood(csnake);

	/*��Ϸѭ��*/
	while (csnake.OverEdge()&&csnake.HitItself())//�ж��Ƿ�ײǽ���߳Ե��Լ�
	{
		/*����ѡ��˵�*/
		if (!csnake.ChangeDirection()) //��Esc��ʱ
		{
			int tmp = Menu();//���Ʋ˵������õ�����ֵ
			switch (tmp)
			{
			case 1://������Ϸ
				break;
			case 2://���¿�ʼ
				return 1;//��1��ΪPlayGame�����ķ���ֵ���ص�Game�����У���ʾ���¿�ʼ

			case 3://�˳���Ϸ
				return 2;//��2��ΪPlayGame�����ķ���ֵ���ص�Game�����У���ʾ�˳���Ϸ

			default:
				break;
			}
		}

		if (csnake.GetFood(cfood))
		{
			csnake.Move();//�������ƶ�
			UpdateScore(1);
			RewriteScore();
			cfood.DrawFood(csnake);
		}
		else
		{
			csnake.NormalMove();//�������ƶ�
		}
		
		if (csnake.GetBigfood(cfood))
		{
			csnake.BigMove();//����2����λ
			UpdateScore(cfood.GetProgressBar() / 5);//����������ʱʳ�����������
			RewriteScore();
		}
		if (csnake.GetPoison(cfood))
		{
			csnake.EatPoison();
			UpdateScore(-1);
			RewriteScore();
		}

		if (cfood.GetBigFlag())//�������ʱʳ���˸��
		{
			cfood.FlashBigFood();
		}

		Sleep(m_Speed);
	}

	int tmp = GameOver();
	switch (tmp)
	{
	case 1:
		return 1;//���¿�ʼ
	case 2:
		return 2;//�˳���Ϸ
	default:
		return 2;
	}
}
void Controller::UpdateScore(const int& tmp)
{
	m_Score += m_Key * 10 * tmp; //�����ɲ�ͬ����ȷ��
}
void Controller::RewriteScore()
{
	/*Ϊ���ַ���β�����룬������������Ϊ6λ�����㵱ǰ����λ������ʣ��λ���ÿո�ȫ�����������*/
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
int Controller::Menu()//ѡ��˵�
{
	/*���Ʋ˵�*/
	SetColor(11);
	SetCursorPosition(32, 19);
	std::cout << "�˵���";
	Sleep(100);
	SetCursorPosition(34, 21);
	SetBackColor();
	std::cout << "������Ϸ";
	Sleep(100);
	SetCursorPosition(34, 23);
	SetColor(11);
	std::cout << "���¿�ʼ";
	Sleep(100);
	SetCursorPosition(34, 25);
	std::cout << "�˳���Ϸ";
	SetCursorPosition(0, 31);

	/*ѡ�񲿷�*/
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
					std::cout << "������Ϸ";
					SetCursorPosition(34, 23);
					SetColor(11);
					std::cout << "���¿�ʼ";

					--tmp_key;
					break;
				case 3:
					SetCursorPosition(34, 23);
					SetBackColor();
					std::cout << "���¿�ʼ";
					SetCursorPosition(34, 25);
					SetColor(11);
					std::cout << "�˳���Ϸ";

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
					std::cout << "���¿�ʼ";
					SetCursorPosition(34, 21);
					SetColor(11);
					std::cout << "������Ϸ";

					++tmp_key;
					break;
				case 2:
					SetCursorPosition(34, 25);
					SetBackColor();
					std::cout << "�˳���Ϸ";
					SetCursorPosition(34, 23);
					SetColor(11);
					std::cout << "���¿�ʼ";

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

	if (tmp_key == 1) //ѡ�������Ϸ���򽫲˵�����
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
	Start();//��ʼ����
	while (true)
	{
		Select();
		DrawGame();
		int tmp = PlayGame();
		if (tmp == 1) //����ֵΪ1ʱ���¿�ʼ��Ϸ
		{
			system("cls");
			continue;
		}
		else if (tmp == 2) //����ֵΪ2ʱ�˳���Ϸ
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
	/*������Ϸ��������*/
	Sleep(500);
	SetColor(11);
	SetCursorPosition(10, 8);
	std::cout << "��������������������������������������������";
	Sleep(30);
	SetCursorPosition(9, 9);
	std::cout << " ��               Game Over !!!              ��";
	Sleep(30);
	SetCursorPosition(9, 10);
	std::cout << " ��                                          ��";
	Sleep(30);
	SetCursorPosition(9, 11);
	std::cout << " ��              ���ź��������              ��";
	Sleep(30);
	SetCursorPosition(9, 12);
	std::cout << " ��                                          ��";
	Sleep(30);
	SetCursorPosition(9, 13);
	std::cout << " ��             ��ķ���Ϊ��                 ��";
	SetCursorPosition(24, 13);
	std::cout << m_Score;
	Sleep(30);
	SetCursorPosition(9, 14);
	std::cout << " ��                                          ��";
	Sleep(30);
	SetCursorPosition(9, 15);
	std::cout << " ��   �Ƿ�����һ�֣�                         ��";
	Sleep(30);
	SetCursorPosition(9, 16);
	std::cout << " ��                                          ��";
	Sleep(30);
	SetCursorPosition(9, 17);
	std::cout << " ��                                          ��";
	Sleep(30);
	SetCursorPosition(9, 18);
	std::cout << " ��    �ţ��õ�        ���ˣ�����ѧϰ����˼  ��";
	Sleep(30);
	SetCursorPosition(9, 19);
	std::cout << " ��                                          ��";
	Sleep(30);
	SetCursorPosition(9, 20);
	std::cout << " ��                                          ��";
	Sleep(30);
	SetCursorPosition(10, 21);
	std::cout << "��������������������������������������������";

	Sleep(100);
	SetCursorPosition(12, 18);
	SetBackColor();
	std::cout << "�ţ��õ�";
	SetCursorPosition(0, 31);

	/*ѡ�񲿷�*/
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
				std::cout << "�ţ��õ�";
				SetCursorPosition(20, 18);
				SetColor(11);
				std::cout << "���ˣ�����ѧϰ����˼";
				--tmp_key;
			}
			break;

		case 77://RIGHT
			if (tmp_key < 2)
			{
				SetCursorPosition(20, 18);
				SetBackColor();
				std::cout << "���ˣ�����ѧϰ����˼";
				SetCursorPosition(12, 18);
				SetColor(11);
				std::cout << "�ţ��õ�";
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
		return 1;//���¿�ʼ
	case 2:
		return 2;//�˳���Ϸ
	default:
		return 1;
	}
}
