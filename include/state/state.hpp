#ifndef __STATE_STATE
#define __STATE_STATE


namespace ach
{
	enum GameState
	{
		gsNone = -1,
		gsStart = 0,
		gsMenu,
		gsCredits,
		gsGame,
		gsEnd
	};


	struct StateBase
	{
		         StateBase()          {};
		virtual ~StateBase()          {};

		virtual void update()         {};
		virtual void event(sf::Event) {};

		virtual void translate()      {};
		virtual void style()          {};
	};
}

#endif
