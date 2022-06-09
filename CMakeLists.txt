cmake_minimum_required(VERSION 3.11) # FetchContent is available in 3.11+
project(10x12chess)

# Our Project

# debug use mkdir Debug cd Debug , cmake -DCMAKE_BUILD_TYPE=Debug .. , make
set(CMAKE_CXX_FLAGS_DEBUG_INIT "-Wall -g")

file(GLOB SOURCES "src/*.c")

# Add an executable with the above sources
add_executable(${PROJECT_NAME} ${SOURCES})

# Set the directories that should be included in the build command for this target
# when running gcc these will be included as -I/directory/path/
target_include_directories(${PROJECT_NAME}
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/include
)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(10x12chess PRIVATE Threads::Threads)