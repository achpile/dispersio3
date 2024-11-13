PROJECT  = dispersio3

INCLUDE  = include

CPP      = $(shell find src/        -type f -name '*.cpp')
HPP      = $(shell find $(INCLUDE)/ -type f -name '*.hpp')
INL      = $(shell find $(INCLUDE)/ -type f -name '*.inl')
OBJ      = $(patsubst %.cpp,%.o, $(CPP))

HEADER   = $(INCLUDE)/meta/headers.hpp
PCH      = $(HEADER).gch

TOTAL    = $(words $(OBJ))
CORES    = $(shell grep -c ^processor /proc/cpuinfo)

CMAKE    = CMakeFiles           \
           CMakeCache.txt       \
           cmake_install.cmake  \
           install_manifest.txt

DATA     = settings.json        \
           logs/

GARBAGE  = $(PCH) $(OBJ) $(PROJECT) $(CMAKE) $(DATA)

CC       = @g++
STRIP    = @strip
MAKE     = @make -j$(CORES) --no-print-directory
ECHO     = @echo
CLEAN    = @rm -rf

NORMAL   = "\033[0m"
PURPLE   = "\033[1;35m"
YELLOW   = "\033[0;33m"
GREEN    = "\033[0;32m"
BLUE     = "\033[1;34m"
CYAN     = "\033[1;36m"
RED      = "\033[1;31m"

LDFLAGS  = -static-libstdc++ \
           -static-libgcc    \
           -lstdc++fs        \
           -lsfml-graphics   \
           -lsfml-window     \
           -lsfml-system     \
           -lsfml-audio      \
           -lm               \
           -ljansson

CFLAGS   = -Wall            \
           -Wextra          \
           -Werror          \
           -std=c++17       \
           -I$(INCLUDE)


all: info
	$(MAKE) $(PROJECT)


info:
	$(ECHO)
	$(ECHO) $(PURPLE) "Threads " $(NORMAL) " :" $(YELLOW) $(CORES)   $(NORMAL)
	$(ECHO) $(PURPLE) "Files   " $(NORMAL) " :" $(YELLOW) $(TOTAL)   $(NORMAL)
	$(ECHO)
	$(ECHO) $(RED) "C flags " $(NORMAL) " :" $(YELLOW) $(CFLAGS)  $(NORMAL)
	$(ECHO) $(RED) "LD flags" $(NORMAL) " :" $(YELLOW) $(LDFLAGS) $(NORMAL)
	$(ECHO)


$(PROJECT): $(OBJ)
	$(ECHO)
	$(ECHO) $(CYAN) "Linking  " $(NORMAL) : $(PROJECT)
	$(CC) $(OBJ) -o $(PROJECT) $(LDFLAGS)

	$(ECHO) $(CYAN) "Stripping" $(NORMAL) : $(PROJECT)
	$(STRIP) $(PROJECT)
	$(ECHO)

$(OBJ) : $(PCH)
$(PCH) : $(HPP) $(INL)
	$(ECHO) $(BLUE) "Header   " $(NORMAL) ": $(HEADER)"
	$(ECHO)
	$(CC) $(CFLAGS) -o $@ -c $(HEADER)

.cpp.o:
	$(ECHO) $(GREEN) "Compiling" $(NORMAL) ": $(<)"
	$(CC) $(CFLAGS) -o $@ -c $<


clean:
	$(ECHO) $(YELLOW)$(GARBAGE) $(NORMAL)
	$(CLEAN) $(GARBAGE)
