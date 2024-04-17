#ifndef __STATE_BASE
#define __STATE_BASE


namespace ach
{
	enum GameState
	{
		gsStart = 0,
		gsMenu,
		gsCredits,
		gsGame
	};


	struct StateBase
	{
		         StateBase()          {};
		virtual ~StateBase()          {};

		virtual void update()         {};
		virtual void render()         {};
		virtual void translate()      {};
		virtual void event(sf::Event) {};
	};
}

#endif
