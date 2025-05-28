# find_package(ServerCore REQUIRED)

add_executable(GameServer
    GameServer.cpp
)

target_link_libraries(GameServer PRIVATE ServerCore)