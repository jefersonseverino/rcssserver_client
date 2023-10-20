cmake_minimum_required(VERSION 3.16)
project(simple_client)

set(CMAKE_CXX_STANDARD 20)
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(CMAKE_CXX_FLAGS " ${CMAKE_CXX_FLAGS} -pthread")
include_directories(${SOURCE_DIR} ${SOURCE_DIR}/network ${SOURCE_DIR}/parser ${SOURCE_DIR}/worldmodel)

set(PLAYER network/client.cpp parser/server_message_parser.cpp parser/formation_parser.cpp worldmodel/worldmodel.cpp)

foreach(src ${PLAYER})
    list(APPEND SOURCES ${SOURCE_DIR}/${src})
endforeach(src ${PLAYER})

add_library(player_sources STATIC ${SOURCES})

add_executable(player ${SOURCE_DIR}/main.cpp ${SOURCE_DIR}/player.cpp)
target_link_libraries(player player_sources)

set_target_properties(player PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${SOURCE_DIR})
