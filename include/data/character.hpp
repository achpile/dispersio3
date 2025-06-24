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
		aiCannon,
		aiSniper,
		aiJumper,
		aiFollow,
		aiLeveler,
		aiBouncer
	};


	struct DataCharacter : DataContent
	{
		ach::DataModel  *model;
		ach::DataWeapon *weapon;
		ach::AIType      ai;

		ach::DataSound  *sndDie;
		ach::DataSound  *sndJump;
		ach::DataSound  *sndLand;
		ach::DataSound  *sndSwim;

		sf::Vector2f     hitbox;
		sf::Vector2f     offset;
		sf::Color        color;

		float barrel;
		float speed;
		float jumping;
		float gravity;


		 DataCharacter(json_t *obj);
		~DataCharacter();
	};
}

#endif
