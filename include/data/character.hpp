#ifndef __DATA_CHARACTER
#define __DATA_CHARACTER


namespace ach
{
	enum AIType
	{
		aiIdle = 0,
		aiPlayer
	};


	struct DataCharacter : DataContent
	{
		ach::DataBody   *body;
		ach::DataWeapon *weapon;
		ach::AIType      ai;

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
