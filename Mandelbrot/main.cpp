#include "ComplexPlane.h"

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
		

		/*
		****************************************
		Draw the scene
		****************************************
		*/

		window.clear();
		window.draw(chaos);
		window.display();
	}
}