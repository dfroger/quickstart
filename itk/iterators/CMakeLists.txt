cmake_minimum_required(VERSION 2.8)
 
project(iterators)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -Wall")
 
find_package(ITK REQUIRED)
include(${ITK_USE_FILE})
 
add_executable(iterators iterators.cxx create_image.cxx)
 
target_link_libraries(iterators ${ITK_LIBRARIES})
