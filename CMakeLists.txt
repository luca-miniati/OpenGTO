cmake_minimum_required(VERSION 3.10)

project(OpenGTO)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

include_directories(include)

set(SOURCES
    src/main.cpp
)

add_executable(main ${SOURCES})
add_executable(testHand ${SOURCES})

find_package(GTest REQUIRED)
target_link_libraries(testHand GTest::GTest GTest::Main pthread)

enable_testing()
add_test(NAME testHand COMMAND testHand)
