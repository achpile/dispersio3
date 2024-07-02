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


		         Tracer(ach::Phys *_phys);
		virtual ~Tracer();

		virtual void update() {};
		virtual void render() {};
	};
}

#endif
