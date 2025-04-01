#include "meta/headers.hpp"


/***********************************************************************
     * DataCharacter
     * constructor

***********************************************************************/
ach::DataCharacter::DataCharacter(json_t *obj)
{
	model   = db->getModel (json_object_get_branch_string(obj, "Appearance.Model"));
	weapon  = db->getWeapon(json_object_get_branch_string(obj, "Game.Weapon"     ));

	sndDie  = db->getSound(json_object_get_branch_string(obj, "Sound.Die" ));
	sndJump = db->getSound(json_object_get_branch_string(obj, "Sound.Jump"));
	sndLand = db->getSound(json_object_get_branch_string(obj, "Sound.Land"));
	sndSwim = db->getSound(json_object_get_branch_string(obj, "Sound.Swim"));

	barrel  = json_object_get_branch_real(obj, "Appearance.Barrel");
	color   = str_to_color(json_object_get_branch_string(obj, "Appearance.Color"));

	ai      = pair_get_enum(json_object_get_branch_string(obj, "Game.AI"), pairAI);
	hitbox  = vector_json_coord(json_object_get_branch(obj, "Game.Hitbox"), "X", "Y");
	offset  = vector_json_coord(json_object_get_branch(obj, "Game.Offset"), "X", "Y");

	speed   = json_object_get_branch_real(obj, "Stats.Speed"  );
	jumping = json_object_get_branch_real(obj, "Stats.Jump"   );
	gravity = json_object_get_branch_real(obj, "Stats.Gravity");
}



/***********************************************************************
     * DataCharacter
     * destructor

***********************************************************************/
ach::DataCharacter::~DataCharacter()
{
}
