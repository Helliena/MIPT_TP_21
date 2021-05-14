cmake_minimum_required(VERSION 3.10.2)

project(task2 LANGUAGES CXX)

#make dirs and flds
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


#find headers
include_directories(A)
include_directories(B)
include_directories(C)

#add subdirectories
add_subdirectory(B)

#easy way to build project
execute_process(COMMAND python3 preparing.py WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/A)
add_executable(C C/main.cpp C/main.h)
target_link_libraries(C lib_b)
target_include_directories(C PUBLIC ${CMAKE_CURRENT_LIST_DIR})

#hard way to build project
find_package(GTest REQUIRED)
include_directories(include)
include_directories(PUBLIC ${GTEST_INCLUDE_DIRS})

add_executable(CTest C/main_test.cpp)
target_include_directories(CTest PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(CTest lib_b)
target_link_libraries(CTest ${GTEST_BOTH_LIBRARIES})
target_link_libraries(CTest Threads::Threads ${GTEST_BOTH_LIBRARIES})

















