#ifndef __GFX_BUBBLE
#define __GFX_BUBBLE


namespace ach
{
	struct EffectBubble : Effect
	{
		sf::CircleShape *spr;
		sf::Vector2f     pos;

		float life;
		float limit;


		 EffectBubble(sf::Vector2f _pos, float _limit);
		~EffectBubble();

		bool update();
		void render();
	};
}

#endif
