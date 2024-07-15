#ifndef __GFX_TRACER_LINE
#define __GFX_TRACER_LINE


namespace ach
{
	struct TracerLine : Tracer
	{
		sf::VertexArray line;


		 TracerLine(ach::Phys *_phys);
		~TracerLine();

		void update();
		void render();

		void init();
		void correct();
	};
}

#endif
