add_library(GraphicsNIF
    SHARED
    eGraphicsNIF.cpp
    eCircleShape.cpp
    eRectangleShape.cpp
    eConvexShape.cpp
    eEvent.cpp
    eRenderWindow.cpp
    eSprite.cpp
    eTexture.cpp
    eText.cpp
    eFont.cpp
    ${EXTRA_SRCS}
    )

target_link_libraries(GraphicsNIF
    PRIVATE
    misc
    )

install(TARGETS GraphicsNIF
    DESTINATION Graphics
    )
