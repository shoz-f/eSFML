if (WIN32)
    set(PLATFORM_SRCS
        Win32/EventFlagImpl.cpp
        )
endif()

add_library(misc
    STATIC
    EventFlag.cpp
    ${PLATFORM_SRCS}
    )
