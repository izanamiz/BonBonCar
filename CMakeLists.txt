cmake_minimum_required(VERSION 3.20)
project(BonBonCar)

set(CMAKE_CXX_STANDARD 14)

add_executable(BonBonCar main.cpp Animation.cpp Animation.hpp Bullet.cpp Bullet.hpp Coin.cpp Coin.hpp Enemy.cpp Enemy.hpp Explosion.cpp Explosion.hpp Game.cpp Game.hpp Header.hpp Menu.hpp Obstacle.cpp Obstacle.hpp Player.cpp Player.hpp PowerUP.cpp PowerUP.hpp Load.hpp)
set(SFML_STATIC_LIBRARIES TRUE)

set(SFML_DIR C:/Program Files (x86)/SFML/lib/make/SFML)

find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(C:/Program Files (x86)/SFML/include)

target_link_libraries(BonBonCar sfml-system sfml-window sfml-graphics sfml-audio sfml-network)