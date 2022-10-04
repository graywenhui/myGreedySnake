#pragma once
#include <Windows.h>
#include <vector>
#include "point.h"

class Map
{
public:
	Map()
	{
		for (int i = 1;i<31;++i)
		{
			initmap.emplace_back(Point(i, 1));
		}
		for (int i = 2; i < 31; ++i)
		{
			initmap.emplace_back(Point(1, i));
		}
		for (int i = 2; i < 31; ++i)
		{
			initmap.emplace_back(Point(30, i));
		}
		for (int i = 2; i < 31; ++i)
		{
			initmap.emplace_back(Point(i, 30));
		}
	}
	void PrintInitmap();//»æÖÆ
private:
	std::vector<Point> initmap;
};
