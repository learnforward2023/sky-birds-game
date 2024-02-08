cmake_minimum_required(VERSION 3.22)
project(sky_birds_game)

set(CMAKE_CXX_STANDARD 14)

# Add the executable
add_executable(sky_birds_game main.cpp)

find_package(SDL2 REQUIRED)

# Include the directories containing the header files
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS} ${HEADERS} include)

# Link against libraries
target_link_libraries(sky_birds_game PRIVATE -L/opt/homebrew/lib -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer)
