add_library(GraphicsNIF
    SHARED
    eGraphicsNIF.cpp
    eCircleShape.cpp
    eConvexShape.cpp
    eEvent.cpp
    eRenderWindow.cpp
    eSprite.cpp
    eTexture.cpp
    eTransformable.cpp
    ${EXTRA_SRCS}
    )

target_link_libraries(GraphicsNIF
    PRIVATE
    misc
    )

install(TARGETS GraphicsNIF
    DESTINATION Graphics
    )
