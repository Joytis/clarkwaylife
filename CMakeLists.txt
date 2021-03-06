cmake_minimum_required(VERSION 3.3)
project(clarkwaylife)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#set(SDL2_IMAGE_LIBRARY_DIR /usr/local/Cellar/sdl2_image/2.0.1_1/lib)

# Platform Variables
#======================================================================
if(UNIX)
    set(SDL2_IMAGE_LIBRARY_DIR /usr/local/Cellar/sdl2_image/2.0.1_1/lib)
elseif(MINGW)
    set(SDL2_IMAGE_LIBRARY_DIR C:/MinGW/lib)
endif()

#
# Source Includes
#=======================================================================

file(GLOB_RECURSE TEST_CASES ${PROJECT_SOURCE_DIR}/src/tests/*.cpp)
file(GLOB_RECURSE GAME_SOURCES ${PROJECT_SOURCE_DIR}/src/game/*.cpp)
file(GLOB_RECURSE ENGINE_SOURCES ${PROJECT_SOURCE_DIR}/src/engine/*.cpp)
file(GLOB_RECURSE ENGINE_HEADERS ${PROJECT_SOURCE_DIR}/src/engine/*.hpp)

set(clarkwaylife_SOURCES ${GAME_SOURCES})
set(wizengine_SOURCES ${ENGINE_SOURCES})
set(wizengine_HEADERS ${ENGINE_HEADERS})
set(test_SOURCES ${TEST_CASES})

#
# Directories for libraries
#=======================================================================
find_package(SDL2 REQUIRED)
find_package(Boost REQUIRED)

# Include Directories
#======================================================================
include_directories(
        ${SDL2_INCLUDE_DIR}
        ${Boost_INCLUDE_DIRS}
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/include/engine
        ${PROJECT_SOURCE_DIR}/include/engine/systems
        ${PROJECT_SOURCE_DIR}/include/engine/managers
        ${PROJECT_SOURCE_DIR}/include/game
)

#
# Add Subdirectories
#======================================================================
add_subdirectory(src/engine)
add_subdirectory(src/game)
add_subdirectory(src/tests)

