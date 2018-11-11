cmake_minimum_required(VERSION 3.0.2)

project(eSFML)

find_package(SFML 2.5 COMPONENTS system window graphics audio)

if (WIN32)
    set(EXTRA_SRCS
	stdafx.cpp
	dllmain.cpp
	)
elseif(UNIX)
    set(CMAKE_CXX_FLAGS "-pthread -fPIC")
endif()

set(CMAKE_CONFIGURATION_TYPES "Debug;Release")
set(CMAKE_SUPPRESS_REGENERATION true)
set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR})

include_directories(
    misc
    $ENV{ERL_INCLUDE_PATH}
    )

link_libraries(
    sfml-window
    sfml-graphics
    sfml-audio
    sfml-system
    )

add_subdirectory(misc)
add_subdirectory(System)
add_subdirectory(Window)
add_subdirectory(Graphics)
add_subdirectory(Audio)
