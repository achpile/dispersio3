#ifndef __META_HEADERS
#define __META_HEADERS


#include "meta/system.hpp"
#include "meta/defines.hpp"
#include "meta/forward.hpp"

#include "framework/string/defines.hpp"
#include "framework/string/pair.hpp"
#include "framework/string/option.hpp"
#include "framework/string/check.hpp"
#include "framework/string/regex.hpp"
#include "framework/string/color.hpp"
#include "framework/string/utf8.hpp"

#include "framework/log/pair.hpp"
#include "framework/log/base.hpp"

#include "framework/misc/arch.hpp"
#include "framework/misc/direction.hpp"
#include "framework/misc/sfml.hpp"
#include "framework/misc/flag.hpp"
#include "framework/misc/handler.hpp"
#include "framework/misc/list.hpp"
#include "framework/misc/file.hpp"

#include "framework/random/base.hpp"
#include "framework/random/item.hpp"
#include "framework/random/item.inl"
#include "framework/random/list.hpp"
#include "framework/random/list.inl"

#include "framework/math/defines.hpp"
#include "framework/math/base.hpp"
#include "framework/math/interval.hpp"
#include "framework/math/interval.inl"
#include "framework/math/vector.hpp"
#include "framework/math/projection.hpp"
#include "framework/math/line.hpp"

#include "framework/time/defines.hpp"
#include "framework/time/timer.hpp"
#include "framework/time/framer.hpp"
#include "framework/time/animation.hpp"

#include "framework/html/base.hpp"
#include "framework/html/include.hpp"
#include "framework/html/list.hpp"
#include "framework/html/link.hpp"
#include "framework/html/section.hpp"
#include "framework/html/table.hpp"

#include "framework/json/array.hpp"
#include "framework/json/branch.hpp"
#include "framework/json/property.hpp"
#include "framework/json/merge.hpp"
#include "framework/json/macros.hpp"

#include "framework/datamodel/defines.hpp"
#include "framework/datamodel/pair.hpp"
#include "framework/datamodel/attr.hpp"
#include "framework/datamodel/trait.hpp"
#include "framework/datamodel/class.hpp"
#include "framework/datamodel/type.hpp"
#include "framework/datamodel/check.hpp"
#include "framework/datamodel/default.hpp"
#include "framework/datamodel/preprocessor.hpp"
#include "framework/datamodel/docs.hpp"
#include "framework/datamodel/base.hpp"

#include "framework/control/pair.hpp"
#include "framework/control/key.hpp"
#include "framework/control/pad.hpp"

#include "framework/gfx/sprite.hpp"
#include "framework/gfx/sheet.hpp"
#include "framework/gfx/layer.hpp"

#include "framework/manager/render.hpp"
#include "framework/manager/sound.hpp"
#include "framework/manager/time.hpp"

#include "framework/text/align.hpp"
#include "framework/text/draw.hpp"

#include "framework/menu/defines.hpp"
#include "framework/menu/forward.hpp"
#include "framework/menu/theme.hpp"
#include "framework/menu/item.hpp"
#include "framework/menu/action.hpp"
#include "framework/menu/back.hpp"
#include "framework/menu/checkbox.hpp"
#include "framework/menu/control.hpp"
#include "framework/menu/folder.hpp"
#include "framework/menu/list.hpp"
#include "framework/menu/slider.hpp"
#include "framework/menu/base.hpp"

#include "framework/particle/base.hpp"
#include "framework/particle/system.hpp"

#include "framework/collision/defines.hpp"
#include "framework/collision/pair.hpp"
#include "framework/collision/phys.hpp"
#include "framework/collision/line.hpp"
#include "framework/collision/quadrant.hpp"
#include "framework/collision/base.hpp"
#include "framework/collision/algo.hpp"

#include "particle/stars.hpp"
#include "particle/smoke.hpp"
#include "particle/splash.hpp"

#include "data/content.hpp"
#include "data/font.hpp"
#include "data/theme.hpp"
#include "data/sheet.hpp"
#include "data/model.hpp"
#include "data/projectile.hpp"
#include "data/weapon.hpp"
#include "data/body.hpp"
#include "data/character.hpp"
#include "data/base.hpp"

#include "model/base.hpp"

#include "gfx/base.hpp"
#include "gfx/explosion.hpp"

#include "gfx/impact/base.hpp"
#include "gfx/impact/spark.hpp"

#include "gfx/tracer/base.hpp"
#include "gfx/tracer/line.hpp"
#include "gfx/tracer/smoke.hpp"

#include "container/theme.hpp"
#include "container/settings.hpp"
#include "container/background.hpp"
#include "container/language.hpp"

#include "character/ai/pair.hpp"
#include "character/ai/base.hpp"
#include "character/ai/player.hpp"

#include "character/body/pair.hpp"
#include "character/body/part.hpp"
#include "character/body/base.hpp"
#include "character/body/simple.hpp"
#include "character/body/humanoid.hpp"

#include "character/projectile/pair.hpp"
#include "character/projectile/base.hpp"

#include "character/weapon.hpp"
#include "character/base.hpp"

#include "map/object/base.hpp"
#include "map/object/decor.hpp"

#include "map/tile/pair.hpp"
#include "map/tile/base.hpp"
#include "map/tile/tileset.hpp"
#include "map/tile/maptile.hpp"

#include "map/camera.hpp"
#include "map/base.hpp"

#include "process/base.hpp"
#include "process/world.hpp"

#include "state/pair.hpp"
#include "state/base.hpp"
#include "state/start.hpp"
#include "state/menu.hpp"
#include "state/game.hpp"
#include "state/credits.hpp"
#include "state/end.hpp"

#include "handler/menu.hpp"

#include "meta/app.hpp"
#include "meta/externs.hpp"

#endif
