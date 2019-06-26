#include "pch.h"
#include "map.h"


map::map(int Dimensions)
{	
	m_size = Dimensions / tile;
	max_rooms = 10;
	for (int i = 0; i < m_size; i++)
	{
		vector<int> line;
		line.clear();
		for (int j = 0; j < m_size; j++)
		{
			line.push_back(0);
		}
		m_mapa.push_back(line);
	}
}


map::~map()
{
}

void map::CreateMap()
{
	diger Agent(cCreatePoint(2, 2));
	diger Agent2(cCreatePoint(10, 10));
	
	while (this->m_rooms.size() <= 20)
	{
		Agent.Dig(this->m_mapa, this->m_rooms);
		//Agent.Dig(this->m_mapa, this->m_rooms);
	}

}

void map::DrawMap()
{
	punto start, savestart;
	start.first = -(m_size*tile) / 2;
	start.second = -(m_size*tile) / 2;
	savestart = start;
	for (int i = 0; i < m_size; i++)
	{		
		for (int j = 0; j < m_size; j++)
		{
			if (m_mapa[i][j] == 0) {							
				gDrowTiledRectangle(start, green);				
			}
			if (m_mapa[i][j] == 1) {
				gDrowRectangle(start, white);
			}
			if (m_mapa[i][j] == 9) {
				gDrowRectangle(start, red);
			}
			start.first += tile;
		}
		start = savestart;
		start.second += tile;
		savestart = start;
	}
}




