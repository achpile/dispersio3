#include "meta/headers.hpp"


/***********************************************************************
     * DataCharacter
     * constructor

***********************************************************************/
ach::DataCharacter::DataCharacter(json_t *obj)
{
	body    = db->getBody  (json_object_get_branch_string(obj, "Appearance.Body" ));
	chunks  = db->getSheet (json_object_get_branch_string(obj, "Appearance.Chunk"));
	weapon  = db->getWeapon(json_object_get_branch_string(obj, "Game.Weapon"     ));

	barrel  = json_object_get_branch_real(obj, "Appearance.Barrel");

	ai      = (ach::AIType)pair_get_enum(json_object_get_branch_string(obj, "Game.AI"), pairAI);
	hitbox  = vector_json_coord(json_object_get_branch(obj, "Game.Hitbox"), "X", "Y");

	color   = str_to_color(json_object_get_branch_string(obj, "Color.Model"));
	blood   = str_to_color(json_object_get_branch_string(obj, "Color.Blood"));
	chunk   = str_to_color(json_object_get_branch_string(obj, "Color.Chunk"));

	speed   = json_object_get_branch_real   (obj, "Stats.Speed" );
	jumping = json_object_get_branch_real   (obj, "Stats.Jump"  );
	health  = json_object_get_branch_integer(obj, "Stats.Health");

	sfml_load_sound(&sndHurt, json_object_get_branch_string(obj, "Sound.Hurt"));
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
	delete sndHurt;
	delete sndDie;
	delete sndJump;
	delete sndLand;
}
