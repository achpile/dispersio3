#ifndef __MAP_OBJECT_OBJECT
#define __MAP_OBJECT_OBJECT


namespace ach
{
	struct MapObject
	{
		std::vector<ach::PhysLine*> lines;

		ach::ProcessWorld          *world;

		ach::Model *model;
		ach::Phys   phys;

		int         id;
		bool        alive;
		bool        solid;


		         MapObject(ach::ProcessWorld *_world, json_t *obj);
		virtual ~MapObject();

		bool update();
		void render();

		bool visible();
		void process();
		void box();

		void setModel(const char *_model);
		void setSheet(const char *_sheet);

		virtual void reset()           {};
		virtual void handle()          {};
		virtual void post()            {};
		virtual void touch()           {};
		virtual void use()             {};
		virtual void init(ach::Map*)   {};
		virtual void stand(ach::Phys*) {};
	};
}

#endif
