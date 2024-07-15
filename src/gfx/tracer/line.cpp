#include "meta/headers.hpp"


/***********************************************************************
     * TracerLine
     * constructor

***********************************************************************/
ach::TracerLine::TracerLine(ach::Phys *_phys) : Tracer(_phys)
{
	line.resize(TRACER_LINE_COUNT);
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
	for (int i = 0; i < TRACER_LINE_COUNT - 1; i++)
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
	for (int i = 0; i < TRACER_LINE_COUNT; i++)
	{
		line[i].color    = color;
		line[i].color.a  = (i + 1) * 255 / TRACER_LINE_COUNT;
		line[i].position = phys->pos;
	}
}



/***********************************************************************
     * TracerLine
     * correct

***********************************************************************/
void ach::TracerLine::correct()
{
	line[TRACER_LINE_COUNT - 1].position = phys->pos;
}
