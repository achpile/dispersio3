#ifndef __STATE_CREDITS
#define __STATE_CREDITS


namespace ach
{
	enum CreditsWeight
	{
		cwTitle,
		cwHeader,
		cwEntry
	};


	struct StateCredits : StateBase
	{
		std::vector<sf::Text*> lines;

		float pos;


		 StateCredits();
		~StateCredits();

		void update();
		void render();
		void event(sf::Event);

		void fill();
		void add(sf::String string, ach::CreditsWeight weight);
		void space();

		int            getSize  (ach::CreditsWeight weight);
		float          getOffset(ach::CreditsWeight weight);
		ach::TextAlign getAlign (ach::CreditsWeight weight);
		sf::Uint32     getStyle (ach::CreditsWeight weight);
	};
}

#endif
