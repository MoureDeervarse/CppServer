add_library(ServerCore STATIC
    Utils/CorePch.h
    Utils/CorePch.cpp
    Utils/Lock.h
    Utils/Lock.cpp
    Utils/Types.h
)

target_include_directories(ServerCore PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
