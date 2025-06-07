add_library(ServerCore STATIC
    include/Core.h
    include/utils/Types.h
    include/utils/SpinLock.h
    include/data_structure/LockStack.h
    src/Core.cpp
    src/utils/SpinLock.cpp
)

target_include_directories(ServerCore PUBLIC
 ${CMAKE_CURRENT_SOURCE_DIR}/include
)
