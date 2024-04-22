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

}
void ComplexPlane::zoomOut()
{

}
void ComplexPlane::setCenter(Vector2i mousePixel)
{

}
void ComplexPlane::setMouseLocation(Vector2i mousePixel)
{

}
void ComplexPlane::loadText(Text& text)
{

}
void ComplexPlane::updateRender()
{

}
