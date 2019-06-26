#pragma once

#include <iostream>


#include "allegro5/color.h"
#include "allegro5/allegro_font.h"
//#include "allegro5/allegro_ttf.h"
#include "allegro5/allegro_primitives.h"
#include "allegro5/allegro.h"

#include <time.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

#define X_MAX 1000
#define Y_MAX 1000
#define tile 10

#define white al_map_rgb(255,255,255)
#define red al_map_rgb(255,46,50)
#define blood al_map_rgb(139,0,0)
#define green al_map_rgb(0,255,0)
#define blue al_map_rgb(0,0,255)
#define seagreen al_map_rgb(84,255,159)
#define greenyellow al_map_rgb(173,255,47)
#define orange al_map_rgb(255,127,0)
#define cian al_map_rgb(0,191,196)
#define smoke al_map_rgb(152,170,185)
#define yellow al_map_rgb(255,255,0)
#define gold al_map_rgb(255,185,15)
#define violet al_map_rgb(138,43,226)
#define wood al_map_rgb(166,128,100)
#define coral al_map_rgb(240,128,128)
#define orchid al_map_rgb(147,112,219)
#define steelblue al_map_rgb(35,107,142)

typedef int rasmus;
typedef pair<rasmus, rasmus> punto;
typedef pair<punto, punto> rectangle; // posicion y radio
//B---------
//|        |
//|        |
//---------A


int RandRange(int a, int b);

/*************************************RECTANGLE FUNCTIONS*********************************************************/
bool isInside(rectangle rec, punto k);
bool colide(rectangle a, rectangle b);

/*************************************CREATION FUNCTIONS*********************************************************/
punto cCreatePoint(rasmus A, rasmus B);
rectangle cRectangle(punto A, punto B);
/************************************GRAFICATION FUNCTIONS******************************************************/
void gDrowRectangle(punto A, ALLEGRO_COLOR Color = yellow);
void gDrowTiledRectangle(punto A, ALLEGRO_COLOR Color = yellow);


void gDrowLine(punto A, punto B, ALLEGRO_COLOR Color = seagreen);
