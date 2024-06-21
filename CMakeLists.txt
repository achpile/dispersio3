CMAKE_MINIMUM_REQUIRED ( VERSION 2.8 )
SET ( PROJECT_NAME dispersio3 )
PROJECT ( ${PROJECT_NAME} )

INCLUDE_DIRECTORIES ( "include" )
FILE ( GLOB_RECURSE SRC "src/*.cpp" )


IF ( WIN32 )

        SET ( CMAKE_RESOURCE   "misc/icon/icon.o" )
        SET ( CMAKE_CXX_FLAGS  "-DSFML_STATIC -s -std=c++17" )
        SET ( CMAKE_EXE_LINKER_FLAGS  "-mwindows -static-libgcc -static-libstdc++ -static -Wl,-Bstatic -Wl,-rpath,./lib/" )
        SET ( CMAKE_LINK_LIBS steam_api sfml-audio-s sfml-graphics-s sfml-window-s sfml-system-s winmm opengl32 gdi32 freetype jpeg opengl32 openal32 pthread FLAC vorbisfile vorbisenc vorbis ogg m jansson stdc++fs )
        ADD_CUSTOM_COMMAND ( OUTPUT misc/icon/icon.o COMMAND ${CMAKE_RC_COMPILER} -Imisc/icon -imisc/icon/icon.rc -o misc/icon/icon.o )

ELSEIF ( APPLE )

        SET ( CMAKE_RESOURCE  "" )
        SET ( CMAKE_CXX_FLAGS  "-std=c++17 -stdlib=libc++ -mmacosx-version-min=10.7" )
        SET ( CMAKE_EXE_LINKER_FLAGS  "-lc++ -L./lib -Wl,-rpath,./lib/" )
        SET ( CMAKE_LINK_LIBS steam_api sfml-audio sfml-graphics sfml-window sfml-system m jansson stdc++fs )

ELSEIF ( UNIX )

        SET ( CMAKE_RESOURCE  "" )
        SET ( CMAKE_CXX_FLAGS  "-s -std=c++17" )
        SET ( CMAKE_EXE_LINKER_FLAGS  "-s -static-libgcc -static-libstdc++ -L./lib -Wl,-rpath,./lib/" )
        SET ( CMAKE_LINK_LIBS steam_api sfml-audio sfml-graphics sfml-window sfml-system m jansson stdc++fs )

ENDIF ( )


ADD_EXECUTABLE ( ${PROJECT_NAME} ${SRC} ${CMAKE_RESOURCE} )
TARGET_LINK_LIBRARIES ( ${PROJECT_NAME}  ${CMAKE_LINK_LIBS} )
INSTALL ( TARGETS ${PROJECT_NAME} RUNTIME DESTINATION . )
