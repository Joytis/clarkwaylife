find_package(SDL2 REQUIRED)
find_package(Boost REQUIRED)

# Executable
#======================================================================
add_executable(clarkwaylife ${clarkwaylife_SOURCES})
# Assets
#======================================================================
add_custom_command(TARGET clarkwaylife POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${PROJECT_SOURCE_DIR}/assets $<TARGET_FILE_DIR:clarkwaylife>/assets)

# Linking
#==========================================================================
#------------------------------------------------------
#fix for a CMake whitespace error in find_package(SDL2)
set(SDL2_LIBRARIES "-L${SDL2_LIBDIR} -lSDL2")
target_link_libraries(${PROJECT_NAME}
        wizengine
        ${SDL2_LIBRARIES}
        -L${SDL2_IMAGE_LIBRARY_DIR} -lSDL2_image
        ${Boost_LIBRARIES}
        )