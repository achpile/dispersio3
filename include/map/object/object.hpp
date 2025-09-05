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
		bool        hidden;

		bool        value;
		char        flag[STR_LEN_NAME];


		         MapObject(ach::ProcessWorld *_world, json_t *obj);
		virtual ~MapObject();

		bool update();
		void render();

		bool visible(bool area);
		bool intersects(sf::FloatRect rect);
		void process();
		void select();
		void box();
		void refresh();
		void load(json_t *obj);

		void setModel(ach::DataModel *_model);
		void setModel(const char     *_model);
		void setSheet(const char     *_sheet);

		virtual void reset()           {};
		virtual void handle()          {};
		virtual void post()            {};
		virtual void touch()           {};
		virtual void use()             {};
		virtual void init(ach::Map*)   {};
		virtual void stand(ach::Phys*) {};
		virtual void hit()             {};
	};
}

#endif
