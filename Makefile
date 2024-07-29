PROJECT     = dispersio3
INCLUDE_DIR = $(PWD)/include
HEADER      = include/meta/headers.hpp
OBJ        = $(patsubst %.cpp,%.o,$(sort $(shell find src/ -type f -name '*.cpp')))
HPP         = $(shell find include/ -type f -name '*.hpp')
NPROCS      = $(shell grep -c ^processor /proc/cpuinfo)
TOTAL       = $(words $(OBJ))
LEN         = $(shell echo -n ${TOTAL} | wc -c)
PCH         = $(HEADER).gch

CMAKE       = CMakeFiles           \
              CMakeCache.txt       \
              cmake_install.cmake  \
              install_manifest.txt

DATA        = settings.json        \
              logs/

GARBAGE     = $(PCH) $(OBJ) $(PROJECT) $(CMAKE) $(DATA)

CC          = @g++
STRIP       = @strip
MAKE        = @make -j${NPROCS} --no-print-directory
ECHO        = @echo
CLEAN       = @rm -rf
PROGRESS    = \[`echo $(OBJ) | sed "s/\ /\n/g" | grep -n $@ | cut -f1 -d: | tr -d '\n' | xargs -0 printf "%0$(LEN)d"`\/$(TOTAL)\]

NORMAL      = "\033[0m"
PURPLE      = "\033[1;35m"
YELLOW      = "\033[0;33m"
GREEN       = "\033[0;32m"
CYAN        = "\033[1;36m"
RED         = "\033[1;31m"

LDFLAGS     = -static-libstdc++ \
              -static-libgcc    \
              -lstdc++fs        \
              -lsfml-graphics   \
              -lsfml-window     \
              -lsfml-system     \
              -lsfml-audio      \
              -lm               \
              -ljansson

CFLAGS      = -Wall            \
              -Wextra          \
              -Werror          \
              -std=c++17       \
              -I$(INCLUDE_DIR)


all: info
	$(MAKE) $(PROJECT)


info:
	$(ECHO) $(CYAN)
	$(ECHO) "                                                         "
	$(ECHO) "  ▗▄▄    █                             █             ▄▄▖ "
	$(ECHO) "  ▐▛▀█   ▀                             ▀            ▐▀▀█▖"
	$(ECHO) "  ▐▌ ▐▌ ██  ▗▟██▖▐▙█▙  ▟█▙  █▟█▌▗▟██▖ ██   ▟█▙         ▟▌"
	$(ECHO) "  ▐▌ ▐▌  █  ▐▙▄▖▘▐▛ ▜▌▐▙▄▟▌ █▘  ▐▙▄▖▘  █  ▐▛ ▜▌      ▐██ "
	$(ECHO) "  ▐▌ ▐▌  █   ▀▀█▖▐▌ ▐▌▐▛▀▀▘ █    ▀▀█▖  █  ▐▌ ▐▌        ▜▌"
	$(ECHO) "  ▐▙▄█ ▗▄█▄▖▐▄▄▟▌▐█▄█▘▝█▄▄▌ █   ▐▄▄▟▌▗▄█▄▖▝█▄█▘     ▐▄▄█▘"
	$(ECHO) "  ▝▀▀  ▝▀▀▀▘ ▀▀▀ ▐▌▀▘  ▝▀▀  ▀    ▀▀▀ ▝▀▀▀▘ ▝▀▘       ▀▀▘ "
	$(ECHO) "                 ▐▌                                      "
	$(ECHO) $(NORMAL)
	$(ECHO) $(RED) "C  flags:" $(YELLOW) $(CFLAGS)  $(NORMAL)
	$(ECHO) $(RED) "LD flags:" $(YELLOW) $(LDFLAGS) $(NORMAL)
	$(ECHO)
	$(ECHO) $(PURPLE) "Building $(TOTAL) files in $(NPROCS) threads" $(NORMAL)
	$(ECHO) $(PURPLE) "Building: $(PROJECT)" $(NORMAL)
	$(ECHO)


$(PROJECT): $(OBJ)
	$(ECHO)
	$(ECHO) $(CYAN) Linking $(PROJECT) $(NORMAL)
	$(CC) $(OBJ) -o $(PROJECT) $(LDFLAGS)

	$(ECHO) $(CYAN) Stripping $(PROJECT) $(NORMAL)
	$(STRIP) $(PROJECT)

$(OBJ) : $(PCH)
$(PCH) : $(HPP)
	$(ECHO) $(GREEN) "  Compiling main header:"$(NORMAL)" $(HEADER)"
	$(ECHO)
	$(CC) $(CFLAGS) -o $@ -c $(HEADER)

.cpp.o:
	$(ECHO) $(GREEN) "  Compiling" $(NORMAL)$(PROGRESS)$(GREEN) ": $(<)" $(NORMAL)
	$(CC) $(CFLAGS) -o $@ -c $<


clean:
	$(ECHO) $(YELLOW)$(GARBAGE) $(NORMAL)
	$(CLEAN) $(GARBAGE)
