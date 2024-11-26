#ifndef __GFX_TRACER_TRACER
#define __GFX_TRACER_TRACER


namespace ach
{
	struct Tracer : Effect
	{
		ach::Phys *phys;
		sf::Color  color;

		bool       alive;


		         Tracer(ach::Phys *_phys);
		virtual ~Tracer();

		virtual bool update();

		virtual void init()    {};
		virtual void correct() {};
	};
}

#endif
