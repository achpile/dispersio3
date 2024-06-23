#ifndef __DATA_CHARACTER
#define __DATA_CHARACTER


namespace ach
{
	struct DataCharacter : DataContent
	{
		ach::DataBody   *body;
		ach::DataWeapon *weapon;

		sf::Vector2f     hitbox;
		sf::Color        color;

		sf::SoundBuffer *sndHurt;
		sf::SoundBuffer *sndDie;
		sf::SoundBuffer *sndJump;
		sf::SoundBuffer *sndLand;

		float speed;
		float jumping;


		 DataCharacter(json_t *obj);
		~DataCharacter();
	};
}

#endif
