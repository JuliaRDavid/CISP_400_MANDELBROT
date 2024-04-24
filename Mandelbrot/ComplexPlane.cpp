#include "ComplexPlane.h"

ComplexPlane::ComplexPlane(int PixelWidth, int PixelHeight)
{
	m_pixel_size = { PixelWidth, PixelHeight };
	m_aspectRatio = float(PixelHeight) / float(PixelWidth);
	m_plane_center = { 0, 0 };
	m_plane_size = { BASE_WIDTH, BASE_HEIGHT * m_aspectRatio };
	m_zoomCount = 0;
	m_state = State::CALCULATING;
	m_vArray.setPrimitiveType(Points);
	m_vArray.resize(PixelWidth * PixelHeight);

}

void ComplexPlane::draw(RenderTarget& target, RenderStates states) const
{
	target.draw(m_vArray);
}
void ComplexPlane::zoomIn()
{

	m_state = State::CALCULATING;
}
void ComplexPlane::zoomOut()
{


	m_state = State::CALCULATING;
}
void ComplexPlane::setCenter(Vector2i mousePixel)
{
	m_plane_center = mapPixelToCoords(mousePixel);
	m_state = State::CALCULATING;
}
void ComplexPlane::setMouseLocation(Vector2i mousePixel)
{
	
}
void ComplexPlane::loadText(Text& text)
{
	sf::Font font;
	if (!font.loadFromFile("HARRISON.ttf"))
	{
		std::cout << "ERROR: Font failed to load!" << std::endl;
	}
	text.setFont(font);
	text.setCharacterSize(28);
	text.setFillColor(sf::Color::White);
	std::stringstream game_stream;
	game_stream <<
		"Mandelbrot Set" <<
		"\n Center: (0,0)" <<
		"\n Cursor: (filler, filler)" <<
		"\n Left-Click to Zoom in" <<
		"\n Right-Click to Zoom out";
	text.setString(game_stream.str());
}
void ComplexPlane::updateRender()
{
	if (m_state == State::CALCULATING)
	{
		for (size_t i = 0; i < m_pixel_size.y; i++)
		{
			for (size_t j = 0; j < m_pixel_size.x; j++)
			{
				m_vArray[j + i * m_pixel_size.x].position = { (float)j,(float)i };

			}
		}
		m_state = State::DISPLAYING;
	}
}

int ComplexPlane::countIterations(Vector2f coord)
{
	complex<double> c(coord.x, coord.y);
	complex<double> z(0, 0);
	int count = 0;

	while (abs(z) <= 2 && count < MAX_ITER)
	{
		z = z * z + c;
		count++;
	}
	return count;
}

void ComplexPlane::iterationsToRGB(size_t count, Uint8& r, Uint8& g, Uint8& b)
{
	if (count == MAX_ITER)
	{
		r = 0;
		g = 0;
		b = 0;
	}
	else if (count > 57)
	{
		r = 90;
		g = 0;
		b = 90;
	}
	else if (count > 50)
	{
		r = 80;
		g = 0;
		b = 110;
	}
	else if (count > 40)
	{
		r = 60;
		g = 0;
		b = 230;
	}
	else if (count > 30)
	{
		r = 0;
		g = 130;
		b = 230;
	}
	else if (count > 20)
	{
		r = 0;
		g = 255;
		b = 255;
	}
	else if (count > 10)
	{
		r = 0;
		g = 255;
		b = 210;
	}
	else 
	{
		r = 250;
		g = 200;
		b = 250;
	}
}

Vector2f ComplexPlane::mapPixelToCoords(Vector2i mousePixel)
{
	Vector2f coords = { ((float(mousePixel.x) / m_pixel_size.x) * m_plane_size.x - (m_plane_center.x - m_plane_size.x)),
							((float(mousePixel.y) / m_pixel_size.y) * m_plane_size.y - (m_plane_center.y - m_plane_size.y)) };
	return coords;
}