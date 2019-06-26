#include "pch.h"
#include "functions.h"

//Allegro initiations


int RandRange(int a, int b)
{
	if (a == 0 && b == 1) { return rand() % 2; }
	if (b == 0) { return 0; }
	return rand() % ((b - a) + 1) + a;
}


//---------------------------------CREATION FUNCTIONS--------------------------------------------------------------------------------
punto cCreatePoint(rasmus A, rasmus B)
{
	return make_pair(A, B);
}


rectangle cRectangle(punto A, punto B)
{
	rectangle rect;
	//if (a == b) { m_A = m_B = a; }
	/*if (A.first <= B.first and A.second > B.second) {
		rect.first = A;
		rect.second = B;
	}
	if (A.first <= B.first and A.second < B.second) {
		rect.first = make_pair(B.first, B.second);
		rect.second = make_pair(A.first, A.second);
	}
	if (A.first >= B.first and A.second < B.second) {
		rect.first = A;
		rect.second = B;
	}
	if (A.first >= B.first and A.second > B.second) {
		rect.first = make_pair(B.first, A.second);
		rect.second = make_pair(A.first, B.second);
	}*/
	rect.first = A;
	rect.second = B;
	return rect;
}

bool isInside(rectangle rec, punto k)
{
	if (k.first >= rec.first.first and k.first <= rec.second.first and
		k.second >= rec.first.second and k.second <= rec.second.second) {
		return true;
	}
	return false;
}

bool colide(rectangle a, rectangle b)
{
	punto A, AA;
	A = a.first;
	AA = a.second;
	for (int i = A.first; i <= AA.first; i++)
	{
		for (int j = A.second; j <= AA.second; j++)
		{
			punto p = cCreatePoint(i, j);
			if (isInside(b, p)) {
				return true;
			}
		}
	}
	return false;
}




//---------------------------------GRAFICATION FUNCTIONS-------------------------------------------------------------------------------

void gDrowRectangle(punto A, ALLEGRO_COLOR Color)
{
	al_draw_filled_rectangle(A.first + X_MAX / 2, A.second + Y_MAX / 2, (A.first + tile) + X_MAX / 2, (A.second + tile) + Y_MAX / 2, Color);
}
void gDrowTiledRectangle(punto A, ALLEGRO_COLOR Color)
{
	al_draw_rectangle(A.first + X_MAX / 2, A.second + Y_MAX / 2, (A.first + tile) + X_MAX / 2, (A.second + tile) + Y_MAX / 2, Color, 1);
}

void gDrowLine(punto A, punto B, ALLEGRO_COLOR Color)
{
	al_draw_line(A.first + X_MAX / 2, A.second + Y_MAX / 2, B.first + X_MAX / 2, B.second + Y_MAX / 2, Color, 2);
}	