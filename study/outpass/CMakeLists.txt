project(outpass)
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_FLAGS "-Wall -fno-rtti")
set(LLVM_DIR /Users/zhubing/Documents/workspace-git/llvm-project/build-debug/lib/cmake/llvm)

find_package(LLVM REQUIRED CONFIG)

add_definitions(${LLVM_DEFINITIONS})
include_directories(${LLVM_INCLUDE_DIRS})

add_subdirectory(OutEncryptFunctionName)
#-Wl,-flat_namespace -Wl,-undefined -Wl,suppress -Wl,-dead_strip
#添加这些参数到outpass/cmake-build-debug/OutEncryptFunctionName/CMakeFiles/LLVMOutEncryptFunctionName.dir/link.txt