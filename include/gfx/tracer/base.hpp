#ifndef __GFX_TRACER_BASE
#define __GFX_TRACER_BASE


namespace ach
{
	enum TracerType
	{
		ttNone = 0
	};


	struct Tracer
	{
		ach::Phys *phys;

		sf::Color  color;


		         Tracer(ach::Phys *_phys);
		virtual ~Tracer();

		virtual void update() {};
		virtual void render() {};

		static ach::Tracer *create(ach::TracerType type, ach::Phys *_phys);
	};
}

#endif
