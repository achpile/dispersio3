#ifndef __GFX_TRACER_BASE
#define __GFX_TRACER_BASE


namespace ach
{
	struct Tracer
	{
		ach::Phys *phys;

		sf::Color  color;


		         Tracer(ach::Phys *_phys);
		virtual ~Tracer();

		virtual void update() {};
		virtual void render() {};

		virtual void init()    {};
		virtual void correct() {};
	};
}

#endif
