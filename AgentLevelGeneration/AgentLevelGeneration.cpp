// AgentLevelGeneration.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
#include "map.h"
#include "diger.h"

int main()
{
	
	ALLEGRO_DISPLAY *display;

	float FPS = 10.0;
	//init the random generator
	srand(time(NULL));
	//----------------------
	if (!al_init())
	{
		fprintf(stderr, "failed to initialize allegro!\n");
		return -1;
	}

	display = al_create_display(X_MAX + 10, Y_MAX + 10);
	al_set_window_title(display, "Castle Generation");

	if (!display)
	{
		fprintf(stderr, "failed to create display!\n");
		return -1;
	}
	al_set_window_position(display, 100, 10);

	al_init_font_addon();
	al_install_keyboard();
	al_init_primitives_addon();
	

	ALLEGRO_TIMER *timer = al_create_timer(FPS / 60);

	ALLEGRO_EVENT_QUEUE *cola_de_eventos = al_create_event_queue();
	ALLEGRO_KEYBOARD_STATE key_state;

	//teclado
	al_register_event_source(cola_de_eventos, al_get_keyboard_event_source());
	al_register_event_source(cola_de_eventos, al_get_timer_event_source(timer));
	al_register_event_source(cola_de_eventos, al_get_display_event_source(display));

	
	al_set_window_title(display, "Level Generation By Agent");
	ALLEGRO_FONT* font = al_create_builtin_font();
	
	bool done = false;
	bool drow = false;
	al_start_timer(timer);

	int GameLoopCounter = 0;
	//Objects
	map Map(900);
	//diger Agent(cCreatePoint(89, 89));
	//diger Agent2(cCreatePoint(10, 10));
	Map.CreateMap();
	while (!done)
	{
		ALLEGRO_EVENT events;

		al_wait_for_event(cola_de_eventos, &events);
		al_get_keyboard_state(&key_state);

		if (events.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			done = true;
		}

		if (events.type == ALLEGRO_EVENT_TIMER)
		{
			drow = true;
		}
		if (drow)
		{
			al_clear_to_color(al_map_rgb(0, 0, 0));//color de fondo

			//CREATION

			/*
			R.AddWall(R.m_mapa);
			if (GameLoopCounter > 2 && GameLoopCounter % 3 == 0)
			{
				//R.RemoveWall(R.m_mapa);
				R.AddDoor(0);
			}*/


			//GRAFICATION
			
			//Agent.Dig(Map);
			//Agent2.Dig(Map);

			Map.DrawMap();
			//string text = ("Iteracion: " + to_string(GameLoopCounter));	
			//string text2 = ("Turn: " + to_string(Agent.m_turnP));
			//string text3 = ("Room: " + to_string(Agent.m_roomP));

			/*
			al_draw_text(font, al_map_rgb(255, 255, 255), 100, 10, ALLEGRO_ALIGN_CENTER, text.c_str());
			al_draw_text(font, al_map_rgb(255, 255, 255), 200, 10, ALLEGRO_ALIGN_CENTER, text2.c_str());
			al_draw_text(font, al_map_rgb(255, 255, 255), 300, 10, ALLEGRO_ALIGN_CENTER, text3.c_str());
			if (Agent.m_direction == 1) { al_draw_text(font, al_map_rgb(255, 255, 255), 500, 10, ALLEGRO_ALIGN_CENTER, "Direccion: Derecha"); }
			else if(Agent.m_direction == 2){ al_draw_text(font, al_map_rgb(255, 255, 255), 500, 10, ALLEGRO_ALIGN_CENTER, "Direccion: Izquierda"); }
			else if (Agent.m_direction == 3) { al_draw_text(font, al_map_rgb(255, 255, 255), 500, 10, ALLEGRO_ALIGN_CENTER, "Direccion: Arriba"); }
			else { al_draw_text(font, al_map_rgb(255, 255, 255), 500, 10, ALLEGRO_ALIGN_CENTER, "Direccion: Abajo"); }
			*/
			al_flip_display();

			GameLoopCounter++;
			//al_rest(0.5); // wait 5 seconds
		}

	}

	al_destroy_display(display);
	al_destroy_timer(timer);
	al_destroy_event_queue(cola_de_eventos);
	
	/*al_clear_to_color(al_map_rgb(0, 0, 0));
	al_draw_text(font, al_map_rgb(255, 255, 255), 400, 300, ALLEGRO_ALIGN_CENTER, "Welcome to Allegro!");
	al_flip_display();
	al_rest(5.0);*/

	return 0;
}

