project(multiplytest)
cmake_minimum_required(VERSION 2.6)

include_directories($ENV{GMOCK_HOME}/googlemock/include $ENV{GMOCK_HOME}/googletest/include)
link_directories($ENV{GMOCK_HOME}/googlemock/mybuild $ENV{GMOCK_HOME}/googletest/mybuild)
add_definitions(-std=c++0x)
set(CMAKE_CXX_FLAGS "${CMAXE_CXX_FLAGS} -Wall")

set(sources 
   main.cpp 
   multiply.cpp)
add_executable(test ${sources})
target_link_libraries(test -pthread)
target_link_libraries(test gmock)
target_link_libraries(test gtest)

