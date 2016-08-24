cmake_minimum_required(VERSION 3.3)
project(clarkwaylife)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#set(SDL2_IMAGE_LIBRARY_DIR /usr/local/Cellar/sdl2_image/2.0.1_1/lib)

# Platform Variables
#======================================================================
if(UNIX)
    set(SDL2_IMAGE_LIBRARY_DIR /usr/local/Cellar/sdl2_image/2.0.1_1/lib)

elseif(WIN32)
    
endif()

#
# Directories for libraries
#=======================================================================
file(GLOB_RECURSE clarkwaylife_SOURCES "src/*.cpp")

find_package(SDL2 REQUIRED)
find_package(Boost REQUIRED)

# Include Directories
#======================================================================
include_directories(
    ${SDL2_INCLUDE_DIR} 
    ${Boost_INCLUDE_DIRS}
    ${PROJECT_SOURCE_DIR}/include
    )

# Executable
#======================================================================
add_executable(clarkwaylife ${clarkwaylife_SOURCES})

# Linking
#==========================================================================

#------------------------------------------------------
#fix for a CMake whitespace error in find_package(SDL2)
set(SDL2_LIBRARIES "-L${SDL2_LIBDIR} -lSDL2")

target_link_libraries(${PROJECT_NAME}
        ${SDL2_LIBRARIES}
        -L${SDL2_IMAGE_LIBRARY_DIR} -lSDL2_image
        ${Boost_LIBRARIES}
        )