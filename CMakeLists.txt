cmake_minimum_required(VERSION 3.20)
project(tower-defense-12)
set(CMAKE_CXX_STANDARD 17)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")

set(SFML_STATIC_LIBRARIES TRUE)

add_executable(tower-defense-12 src/main.cpp src/gui.cpp src/gui.h src/game_states/window_state.cpp src/game_states/window_state.h src/game_states/menu_state.cpp src/game_states/menu_state.h src/game_states/game_state.cpp src/game_states/game_state.h src/game_states/level_select_state.cpp src/game_states/level_select_state.h src/game_states/finish_state.cpp src/game_states/finish_state.h src/gui_elements/Button.h src/gui_elements/GlobalObjects.cpp src/gui_elements/GlobalObjects.h src/gui_elements/Button.cpp src/Game.hpp src/Game.cpp src/player.cpp src/player.hpp src/levelmap.hpp src/levelmap.cpp src/enemy.cpp src/enemy.hpp src/projectile.cpp src/towers/supporttower.cpp src/projectile.hpp src/towers/tower.cpp src/towers/tower.hpp src/Wave.cpp src/Wave.hpp src/towers/attacktower.cpp src/towers/attacktower.hpp src/gui_elements/TowerButton.cpp src/gui_elements/TowerButton.h libs/json/json.h libs/jsoncpp.cpp src/utils/json_driver.cpp src/utils/json_driver.h src/mapsquare.cpp src/utils/sound_driver.cpp src/utils/sound_driver.h)

# include_directories(headers /usr/include c:/SFML/include)

find_package(SFML COMPONENTS system window graphics network audio REQUIRED)


#include_directories(${SFML_INCLUDE_DIR})
target_link_libraries(tower-defense-12 sfml-graphics sfml-audio)


#file(COPY libs DESTINATION ${CMAKE_BINARY_DIR})
