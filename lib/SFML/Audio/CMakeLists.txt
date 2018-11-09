add_library(AudioNIF
    SHARED
    eAudioNIF.cpp
    eMusic.cpp
    eSound.cpp
    eSoundBuffer.cpp
    ${EXTRA_SRCS}
    )

install(TARGETS AudioNIF
    DESTINATION Audio
    )
