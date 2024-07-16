#ifndef __GFX_EFFECT_BASE
#define __GFX_EFFECT_BASE


namespace ach
{
	struct Effect
	{
		         Effect();
		virtual ~Effect();

		virtual bool update();
		virtual void render() {};

		static ach::Effect *create(ach::EffectType type, sf::Vector2f pos, sf::Vector2f dir, sf::Color color);
	};
}

#endif
