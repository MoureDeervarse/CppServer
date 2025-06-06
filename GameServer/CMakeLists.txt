# find_package(ServerCore REQUIRED)

add_executable(GameServer
    src/GameServer.cpp
)

target_link_libraries(GameServer PRIVATE ServerCore)