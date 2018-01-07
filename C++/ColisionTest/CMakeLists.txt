cmake_minimum_required(VERSION 3.2)
project(SFMLDemo)
set(DIRECTORIOS src include)


file(GLOB SOURCES
    *.hpp	
    *.h
    *.cpp
    include/*.h
    src/*.cpp
)
# GLOB_RECURSE

include_directories(${DIRECTORIOS})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#set(SOURCE_FILES main.cpp json.hpp g_estado.hpp g_controlador.hpp g_controlador.cpp e_anim_init.hpp e_anim_init.cpp  src/AssetManager.cpp src/caracter_loader.cpp src/e_intro_calle.cpp src/json_parse.cpp src/Mago.cpp src/Map_loader.cpp include/AssetManager.h include/caracter_loader.h include/e_intro_calle.h include/json_parse.h include/Mago.h include/Map_loader.h src/Animator.cpp include/Animator.h)
add_executable(SFMLDemo ${SOURCES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
#set(SFML_STATIC_LIBRARIES TRUE)

find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(SFMLDemo ${SFML_LIBRARIES})
endif()
