#include "meta/headers.hpp"


/***********************************************************************
     * TracerLine
     * constructor

***********************************************************************/
ach::TracerLine::TracerLine(ach::Phys *_phys) : Tracer(_phys)
{
	line.resize(10);
	line.setPrimitiveType(sf::PrimitiveType::LineStrip);
}



/***********************************************************************
     * TracerLine
     * destructor

***********************************************************************/
ach::TracerLine::~TracerLine()
{
}



/***********************************************************************
     * TracerLine
     * update

***********************************************************************/
void ach::TracerLine::update()
{
	for (unsigned int i = 0; i < line.getVertexCount() - 1; i++)
		line[i].position = line[i + 1].position;

	correct();
}



/***********************************************************************
     * TracerLine
     * render

***********************************************************************/
void ach::TracerLine::render()
{
	rm->draw(&line, ach::RenderLayer::rlGame);
}



/***********************************************************************
     * TracerLine
     * init

***********************************************************************/
void ach::TracerLine::init()
{
	for (unsigned int i = 0; i < line.getVertexCount(); i++)
	{
		line[i].color    = color;
		line[i].color.a  = (i + 1) * 255 / line.getVertexCount();
		line[i].position = phys->pos;
	}
}



/***********************************************************************
     * TracerLine
     * correct

***********************************************************************/
void ach::TracerLine::correct()
{
	line[line.getVertexCount() - 1].position = phys->pos;
}
