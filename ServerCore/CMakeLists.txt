add_library(ServerCore STATIC
    Utils/CorePch.h
    Utils/CorePch.cpp
)

target_include_directories(ServerCore PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
