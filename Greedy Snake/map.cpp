#pragma once
#include <windows.h>
#include "map.h"

void Map::PrintInitmap()
{
	for (auto& point : initmap)
	{
		point.Print();
		Sleep(10);//?可以营造动画效果？ 注释掉了再试试
	}
}
