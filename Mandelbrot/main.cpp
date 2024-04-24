#include "ComplexPlane.h"
#include <sstream>

int main()
{
	// Create a video mode object
	int pixelWidth = VideoMode::getDesktopMode().width;
	int pixelHeight = VideoMode::getDesktopMode().height;
	VideoMode vm(pixelWidth, pixelHeight);
	// Create and open a window for the game
	RenderWindow window(vm, "Mandelbrot Set", Style::Default);

	//resize window for different resolutions
	View view;
	view.setSize(pixelWidth, pixelHeight);
	view.setCenter(VideoMode::getDesktopMode().width / 2, VideoMode::getDesktopMode().height / 2);
	window.setView(view);
	
	sf::Font font;
	if (!font.loadFromFile("HARRISON.ttf"))
	{
		std::cout << "ERROR: Font failed to load!" << std::endl;
	}
	sf::Text game_string;
	game_string.setFont(font);
	game_string.setCharacterSize(28);
	game_string.setFillColor(sf::Color::Blue);


	ComplexPlane chaos(pixelWidth, pixelHeight);

	while (window.isOpen())
	{

		/*
		****************************************
		Handle the players input
		****************************************
		*/

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close();
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					chaos.zoomIn();
					chaos.setCenter({ event.mouseButton.x, event.mouseButton.y });
				}
				else if (event.mouseButton.button == sf::Mouse::Right)
				{
					chaos.zoomOut();
					chaos.setCenter({ event.mouseButton.x, event.mouseButton.y });
				}
			}
			if (event.type == sf::Event::MouseMoved)
			{
				chaos.setMouseLocation({ event.mouseButton.x, event.mouseButton.y });
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}

		/*
		****************************************
		Update the scene
		****************************************
		*/
		chaos.updateRender();
		chaos.loadText(game_string);

		/*
		****************************************
		Draw the scene
		****************************************
		*/

		window.clear();
		window.draw(chaos);
		window.draw(game_string);
		window.display();
	}
}