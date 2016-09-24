#
# Library Sources
#======================================================================
find_package(SDL2 REQUIRED)
find_package(Boost REQUIRED)

#fix for a CMake whitespace error in find_package(SDL2)
set(SDL2_LIBRARIES "-L${SDL2_LIBDIR} -lSDL2")

# Executable
#======================================================================
add_library(wizengine ${wizengine_SOURCES} ${wizengine_HEADERS})

target_link_libraries(wizengine
        ${SDL2_LIBRARIES}
        -L${SDL2_IMAGE_LIBRARY_DIR} -lSDL2_image
        ${Boost_LIBRARIES}
        )
