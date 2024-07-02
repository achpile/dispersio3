#ifndef __GFX_EFFECT_BASE
#define __GFX_EFFECT_BASE


namespace ach
{
	enum EffectType
	{
		etNone = 0
	};


	struct Effect
	{
		         Effect(sf::Vector2f pos);
		virtual ~Effect();

		virtual bool update();
		virtual void render() {};

		static ach::Effect *create(ach::EffectType type, sf::Vector2f pos);
	};
}

#endif
