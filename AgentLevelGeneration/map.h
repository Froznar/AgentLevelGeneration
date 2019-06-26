#pragma once


#include "functions.h"
#include "diger.h"
class map
{
public:
	map(int Dimensions);
	~map();


	int m_tileSize;
	int m_size;
	int max_rooms;
	vector<vector<int>> m_mapa;

	vector<rectangle> m_rooms;
	void CreateMap();
	void DrawMap();
};

