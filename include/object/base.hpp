#ifndef __OBJECT_BASE
#define __OBJECT_BASE


namespace ach
{
	struct MapObject
	{
		bool alive;


		 MapObject();
		~MapObject();

		bool update();
		void render();
	};
}

#endif
