#include "meta/headers.hpp"


/***********************************************************************
     * DataCharacter
     * constructor

***********************************************************************/
ach::DataCharacter::DataCharacter(json_t *obj)
{
	body   = db->getBody  (json_object_get_string(obj, "Body"  ));
	weapon = db->getWeapon(json_object_get_string(obj, "Weapon"));

	hitbox = vector_json_coord(json_object_get(obj, "Hitbox"), "X", "Y");
	color  = str_to_color(json_object_get_string(obj, "Color"));

	speed  = json_object_get_branch_real(obj, "Stats.Speed");
	jump   = json_object_get_branch_real(obj, "Stats.Jump" );

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
