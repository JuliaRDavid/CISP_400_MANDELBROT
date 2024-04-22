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


	m_state = State::CALCULATING;
}
void ComplexPlane::setMouseLocation(Vector2i mousePixel)
{

}
void ComplexPlane::loadText(Text& text)
{

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

int countIterations(Vector2f coord)
{

}
void iterationsToRGB(size_t count, Uint8& r, Uint8& g, Uint8& b)
{

}
Vector2f mapPixelToCoords(Vector2i mousePixel)
{

}
