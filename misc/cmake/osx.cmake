IF ( APPLE )
        SET ( PLATFORM_CFLAGS "-stdlib=libc++ -mmacosx-version-min=10.15" )
        SET ( PLATFORM_LFLAGS "" )
        SET ( PLATFORM_LIBS    c++ )
ENDIF ()
