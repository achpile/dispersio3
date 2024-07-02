#include "meta/headers.hpp"


/***********************************************************************
     * TracerLine
     * constructor

***********************************************************************/
ach::TracerLine::TracerLine(ach::Phys *_phys) : Tracer(_phys)
{
	line = new sf::VertexArray(sf::PrimitiveType::LineStrip, TRACER_LINE_COUNT);
}



/***********************************************************************
     * TracerLine
     * destructor

***********************************************************************/
ach::TracerLine::~TracerLine()
{
	delete line;
}



/***********************************************************************
     * TracerLine
     * update

***********************************************************************/
void ach::TracerLine::update()
{
}



/***********************************************************************
     * TracerLine
     * render

***********************************************************************/
void ach::TracerLine::render()
{
	rm->draw(line, ach::RenderLayer::rlGame);
}
