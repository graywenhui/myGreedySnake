#pragma once
#include <windows.h>
#include "map.h"

void Map::PrintInitmap()
{
	for (auto& point : initmap)
	{
		point.Print();
		Sleep(10);//?����Ӫ�춯��Ч���� ע�͵���������
	}
}
