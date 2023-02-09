#include <SFML/Graphics.hpp>
#include "settings.h"
#include "Roadobj.h"
#include "Player.h"
using namespace sf;

int main()
{
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE, Style::Close | Style::Titlebar);
	window.setPosition(Vector2i{ (1920 - (int)WINDOW_WIDTH) / 2,0 });
	window.setFramerateLimit(FPS);

	Roadobj Doroga, Doroga2;
	roadObjInit(Doroga, DorogaStartPos, Doroga_File_Name,150.f);
	roadObjInit(Doroga2, DorogaStartPos2, Doroga_File_Name, 150.f);
	Roadobj Trava, Trava2;
	roadObjInit(Trava, TravaStartPos, Trava_File_Name,0.f);
	roadObjInit(Trava2, TravaStartPos2, Trava_File_Name, 0.f);
	Roadobj Pesok,Pesok2;
	roadObjInit(Pesok, PesokStartPos, Pesok_File_Name,135.f);
	roadObjInit(Pesok2, PesokStartPos2, Pesok_File_Name, 135.f);
	Player Machina;
	playerInit(Machina, MachinaStartPos, Machina_File_Name);
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		roadObjUpdate(Trava);
		roadObjUpdate(Trava2);
		roadObjUpdate(Pesok); 
		roadObjUpdate(Pesok2);
		roadObjUpdate(Doroga);
		roadObjUpdate(Doroga2);
		playerUpdate(Machina);

		RoadObjDraw(window, Trava);
		RoadObjDraw(window, Pesok);
		RoadObjDraw(window, Doroga);
		RoadObjDraw(window, Trava2);
		RoadObjDraw(window, Pesok2);
		RoadObjDraw(window, Doroga2);
		playerDraw(window, Machina);

		window.display();
	}

	return 0;
}