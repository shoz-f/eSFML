if (WIN32)
    set(PLATFORM_SRCS
    Win32/EventFlagImpl.cpp
    )
elseif(UNIX)
    set(PLATFORM_SRCS
    )
endif()

add_library(misc
    STATIC
    EventFlag.cpp
    ${PLATFORM_SRCS}
    )
