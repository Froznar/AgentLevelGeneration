#pragma once

#include "functions.h"
#include "map.h"

class diger
{
public:
	diger(punto StartPosition);
	~diger();

	int m_roomP;
	int m_turnP;
	int m_direction;
	punto m_position;
	

	void Dig(vector<vector<int>> &mapa, vector<rectangle> &rooms);
	bool MakeRoom(vector<vector<int>> &mapa, vector<rectangle> &rooms);
	
};

