#include "pch.h"
#include "diger.h"


diger::diger(punto StartPosition)
{
	m_position = StartPosition;
	m_turnP = 0;
	m_roomP = 100;
	m_direction = RandRange(1, 4);
}


diger::~diger()
{
}

void diger::Dig(vector<vector<int>> &mapa, vector<rectangle> &rooms) {
	mapa[m_position.second][m_position.first] = 1;
	int limit = mapa[0].size();
	int tunr = RandRange(0, 500);
	int room = RandRange(0, 100);
	if (tunr <= m_turnP) {

		int new_direction = RandRange(1, 10);
		if (m_direction == 1 || m_direction == 2) {
			if (new_direction % 2 == 0) { m_direction = 3; }
			else { m_direction = 4; }
		}
		else if (m_direction == 3 || m_direction == 4) {
			if (new_direction % 2 == 0) { m_direction = 1; }
			else { m_direction = 2; }
		}
		m_turnP = 0;
	}
	if (room <= m_roomP) {
		bool create = MakeRoom(mapa, rooms);
		if (create == true) 
		{ 
			m_roomP = 0; 				
		}
	}
	m_turnP = m_turnP + 1;
	m_roomP = m_roomP + 1;
	int  next = 0;
	if (m_direction == 1) { next = m_position.first+1; }
	if (m_direction == 2) { next = m_position.first-1; }
	if (m_direction == 3) { next = m_position.second-1; }
	if (m_direction == 4) { next = m_position.second+1; }
	
	//Movimineto
	if (m_direction == 1 && next < limit) { m_position.first++; }
	else if (m_direction == 2 && next >= 0) { m_position.first--; }
	else if (m_direction == 3 && next >= 0) { m_position.second--; }	
	else if (m_direction == 4 && next < limit) { m_position.second++; }
	else { 
		if (m_direction == 1) { m_direction = 2; }
		else if (m_direction == 2) { m_direction = 1; }
		else if (m_direction == 3) { m_direction = 4; }
		else if (m_direction == 4) { m_direction = 3; }
		m_turnP = 0;
	}

	mapa[m_position.second][m_position.first] = 9; //primera iteracion
}

bool diger::MakeRoom(vector<vector<int>> &mapa, vector<rectangle> &rooms) {
	int height, width;
	int limit = mapa[0].size();
	height = RandRange(4, 10);
	width = RandRange(4, 10);

	punto A, B;
	if (width % 2 == 0) {
		A.first = m_position.first + (width / 2);
		B.first = m_position.first - (width / 2)-1;
	}
	else
	{
		A.first = m_position.first + (width / 2);
		B.first = m_position.first - (width / 2);
	}
	if (height % 2 == 0) {
		A.second = m_position.second + (height / 2);
		B.second = m_position.second - (height / 2) - 1;
	}
	else
	{
		A.second = m_position.second + (height / 2);
		B.second = m_position.second - (height / 2);
	}
	//Validacion
	if (A.first>=limit || A.second>=limit || B.first<0 || B.second<0) { return false; }
	rectangle room = cRectangle(B, A);
	for (int i = 0; i < rooms.size(); i++)
	{
		if (colide(room, rooms[i])) {
			return false;
		}
	}
	room.first.first--;
	room.first.second--;
	room.second.first++;
	room.second.second++;
	rooms.push_back( room );
	for (int i = B.first; i <= A.first; i++)
	{
		for (int j= B.second; j <= A.second; j++)
		{
			mapa[j][i] = 1;
		}
	}
	
	return true;
}