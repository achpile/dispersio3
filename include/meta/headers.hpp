#ifndef __META_HEADERS
#define __META_HEADERS


#include "framework/meta/headers.hpp"

#include "meta/defines.hpp"
#include "meta/forward.hpp"

#include "collision/phys.hpp"
#include "collision/line.hpp"
#include "collision/algo.hpp"
#include "collision/quadrant.hpp"
#include "collision/collision.hpp"
#include "collision/pair.hpp"
#include "collision/filter.hpp"

#include "particle/stars.hpp"
#include "particle/wind.hpp"
#include "particle/smoke.hpp"
#include "particle/splash.hpp"

#include "data/content.hpp"
#include "data/font.hpp"
#include "data/sound.hpp"
#include "data/theme.hpp"
#include "data/sheet.hpp"
#include "data/model.hpp"
#include "data/projectile.hpp"
#include "data/weapon.hpp"
#include "data/character.hpp"
#include "data/map.hpp"
#include "data/data.hpp"

#include "model/model.hpp"
#include "model/pair.hpp"

#include "gfx/gfx.hpp"
#include "gfx/break.hpp"
#include "gfx/sheet.hpp"
#include "gfx/splash.hpp"
#include "gfx/bubble.hpp"

#include "gfx/impact/impact.hpp"
#include "gfx/impact/spark.hpp"

#include "gfx/tracer/tracer.hpp"
#include "gfx/tracer/line.hpp"
#include "gfx/tracer/smoke.hpp"

#include "container/theme.hpp"
#include "container/settings.hpp"
#include "container/cache.hpp"
#include "container/pair.hpp"

#include "character/ai/ai.hpp"
#include "character/ai/player.hpp"
#include "character/ai/float.hpp"
#include "character/ai/crawl.hpp"
#include "character/ai/cannon.hpp"
#include "character/ai/sniper.hpp"
#include "character/ai/jumper.hpp"
#include "character/ai/follow.hpp"
#include "character/ai/leveler.hpp"
#include "character/ai/bouncer.hpp"
#include "character/ai/thrower.hpp"
#include "character/ai/pair.hpp"

#include "character/body/body.hpp"
#include "character/body/simple.hpp"
#include "character/body/player.hpp"
#include "character/body/jumper.hpp"
#include "character/body/sniper.hpp"
#include "character/body/moving.hpp"

#include "character/projectile/projectile.hpp"
#include "character/projectile/pair.hpp"

#include "character/weapon.hpp"
#include "character/character.hpp"

#include "map/object/object.hpp"
#include "map/object/decor.hpp"
#include "map/object/door.hpp"
#include "map/object/goal.hpp"
#include "map/object/water.hpp"
#include "map/object/wind.hpp"
#include "map/object/checkpoint.hpp"
#include "map/object/collectable.hpp"
#include "map/object/moving.hpp"
#include "map/object/fragile.hpp"
#include "map/object/break.hpp"
#include "map/object/yoku.hpp"
#include "map/object/antigrav.hpp"

#include "map/tile/tile.hpp"
#include "map/tile/tileset.hpp"
#include "map/tile/maptile.hpp"
#include "map/tile/pair.hpp"

#include "map/area.hpp"
#include "map/camera.hpp"
#include "map/caption.hpp"
#include "map/selector.hpp"
#include "map/map.hpp"

#include "process/process.hpp"
#include "process/world.hpp"

#include "state/state.hpp"
#include "state/start.hpp"
#include "state/menu.hpp"
#include "state/game.hpp"
#include "state/credits.hpp"
#include "state/end.hpp"
#include "state/pair.hpp"

#include "handler/common.hpp"
#include "handler/menu.hpp"
#include "handler/options.hpp"

#include "meta/app.hpp"
#include "meta/externs.hpp"

#endif
