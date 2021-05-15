cmake_minimum_required(VERSION 3.0)

#use toolchain
if (ARM_BUILD)
    set(CMAKE_CXX_COMPILER ${TOOLCHAIN}/aarch64-linux-gnu-g++)
    set(CMAKE_INSTALL_RPATH ${CMAKE_INSTALL_PREFIX}/lib)
}

project(SimpleLibrary)

include_directories(include)

#add dirs and flds
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${SimpleLibrary_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${SimpleLibrary_SOURCE_DIR}/lib)

#add subdirectories
add_subdirectory(src)

#build project
add_executable(Main main.cpp)
add_executable(MainLib main_lib.cpp)

target_link_libraries(MainLib buffer)

if (ARM_BUILD)
    install(TARGETS buffer DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)
    install(FILES include/buffer.h DESTINATION ${CMAKE_INSTALL_PREFIX}/include)
    install(TARGETS MainLib DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
    install(TARGETS Main DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
endif()
