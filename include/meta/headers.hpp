#ifndef __META_HEADERS
#define __META_HEADERS

#include <jansson.h>
#include <string.h>
#include <regex.h>
#include <math.h>

#include <random>
#include <ctime>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>


#include "meta/defines.hpp"
#include "meta/forward.hpp"

#include "framework/misc/flag.hpp"
#include "framework/misc/handler.hpp"
#include "framework/misc/list.hpp"

#include "framework/math/random.hpp"
#include "framework/math/vector.hpp"

#include "framework/time/timer.hpp"
#include "framework/time/framer.hpp"

#include "framework/string/regex.hpp"
#include "framework/string/color.hpp"
#include "framework/string/utf8.hpp"

#include "framework/json/branch.hpp"
#include "framework/json/merge.hpp"
#include "framework/json/macros.hpp"

#include "framework/control/key.hpp"
#include "framework/control/pad.hpp"

#include "framework/gfx/sprite.hpp"
#include "framework/gfx/sheet.hpp"
#include "framework/gfx/layer.hpp"

#include "framework/menu/item.hpp"
#include "framework/menu/base.hpp"

#include "framework/manager/render.hpp"
#include "framework/manager/time.hpp"

#include "container/resources.hpp"

#include "state/base.hpp"
#include "state/menu.hpp"

#include "meta/app.hpp"
#include "meta/externs.hpp"

#endif
