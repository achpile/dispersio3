#ifndef __DATA_CHARACTER
#define __DATA_CHARACTER


namespace ach
{
	enum AIType
	{
		aiIdle = 0,
		aiPlayer,
		aiFloat,
		aiCrawl,
		aiCannon
	};


	struct DataCharacter : DataContent
	{
		ach::DataModel  *model;
		ach::DataWeapon *weapon;
		ach::AIType      ai;

		ach::DataSound  *sndDie;
		ach::DataSound  *sndJump;
		ach::DataSound  *sndLand;

		sf::Vector2f     hitbox;
		sf::Color        color;

		float barrel;
		float speed;
		float jumping;


		 DataCharacter(json_t *obj);
		~DataCharacter();
	};
}

#endif
