add_library(SystemNIF
    SHARED
    eSystemNIF.cpp
    eClock.cpp
    ${EXTRA_SRCS}
    )

install(TARGETS SystemNIF
    DESTINATION System
    )
