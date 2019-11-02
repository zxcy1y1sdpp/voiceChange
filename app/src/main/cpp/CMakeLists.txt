cmake_minimum_required(VERSION 3.4.1)

aux_source_directory(${CMAKE_SOURCE_DIR} srcs)
include_directories(${CMAKE_SOURCE_DIR}/inc)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -L${CMAKE_SOURCE_DIR}/../jniLibs/${CMAKE_ANDROID_ARCH_ABI}")


add_library(
        voice
        SHARED
        ${srcs})

target_link_libraries(
        voice
        fmod
        fmodL
        log)

