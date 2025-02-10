#include "meta/headers.hpp"


/***********************************************************************
     * DataCharacter
     * constructor

***********************************************************************/
ach::DataCharacter::DataCharacter(json_t *obj)
{
	body    = db->getBody  (json_object_get_branch_string(obj, "Appearance.Body" ));
	weapon  = db->getWeapon(json_object_get_branch_string(obj, "Game.Weapon"     ));

	barrel  = json_object_get_branch_real(obj, "Appearance.Barrel");
	color   = str_to_color(json_object_get_branch_string(obj, "Appearance.Color"));

	ai      = (ach::AIType)pair_get_enum(json_object_get_branch_string(obj, "Game.AI"), pairAI);
	hitbox  = vector_json_coord(json_object_get_branch(obj, "Game.Hitbox"), "X", "Y");

	speed   = json_object_get_branch_real   (obj, "Stats.Speed" );
	jumping = json_object_get_branch_real   (obj, "Stats.Jump"  );

	sfml_load_sound(&sndDie , json_object_get_branch_string(obj, "Sound.Die" ));
	sfml_load_sound(&sndJump, json_object_get_branch_string(obj, "Sound.Jump"));
	sfml_load_sound(&sndLand, json_object_get_branch_string(obj, "Sound.Land"));
}



/***********************************************************************
     * DataCharacter
     * destructor

***********************************************************************/
ach::DataCharacter::~DataCharacter()
{
	delete sndDie;
	delete sndJump;
	delete sndLand;
}
