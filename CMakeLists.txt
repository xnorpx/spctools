cmake_minimum_required(VERSION 3.16 FATAL_ERROR)
project(spctools CXX)

include(FetchContent)
#set(CMAKE_CXX_STANDARD 11)
set(CMAKE_SKIP_INSTALL_ALL_DEPENDENCY true)
set(FETCHCONTENT_QUIET FALSE)

FetchContent_Declare(matplotplusplus
                     GIT_REPOSITORY https://github.com/alandefreitas/matplotplusplus
                     GIT_PROGRESS TRUE
                     USES_TERMINAL_DOWNLOAD
                     TRUE)

 FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
)

FetchContent_GetProperties(matplotplusplus googletest)

if(NOT matplotplusplus_POPULATED)
  FetchContent_Populate(matplotplusplus)
  add_subdirectory(${matplotplusplus_SOURCE_DIR})
endif()

FetchContent_GetProperties(googletest)
if(NOT googletest_POPULATED)
  set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
  FetchContent_Populate(googletest)
  add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
endif() 

add_library(spctools SHARED src/spctools.cpp include/spctools.h)
target_link_libraries(spctools matplot)
target_compile_features(spctools PRIVATE cxx_std_17)
target_include_directories(
  spctools
  PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)

add_executable(test_spctools src/test_spctools)
target_link_libraries(test_spctools spctools gtest gtest_main)
