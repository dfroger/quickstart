cmake_minimum_required(VERSION 2.8)
 
project(iterators)
 
find_package(ITK REQUIRED)
include(${ITK_USE_FILE})
 
add_executable(iterators iterators.cxx)
 
target_link_libraries(iterators ${ITK_LIBRARIES})
