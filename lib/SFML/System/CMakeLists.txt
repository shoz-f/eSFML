add_library(SystemNIF
    SHARED
    eSystemNIF.cpp
    eClock.cpp
#    EventFlag.cpp
    ${EXTRA_SRCS}
    )

install(TARGETS SystemNIF
    DESTINATION System
    )
