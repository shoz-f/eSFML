add_library(WindowNIF
    SHARED
    eWindowNIF.cpp
    ${EXTRA_SRCS}
    )

install(TARGETS WindowNIF
    DESTINATION Window
    )
