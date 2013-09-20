cmake_minimum_required(VERSION 2.8)

PROJECT(rullo)

cmake_minimum_required(VERSION 2.8)

IF(WIN32)
                add_definitions(-D_CRT_SECURE_NO_WARNINGS)
ENDIF(WIN32)

IF(CMAKE_COMPILER_IS_GNUCXX)
   add_definitions(-Wall -Wno-unknown-pragmas ) #removing pragma once...
ENDIF(CMAKE_COMPILER_IS_GNUCXX)

#################################################
# BOOST
################################################
SET(BOOST_ROOT "$ENV{BOOST}")
SET(Boost_USE_STATIC_LIBS ON)
SET(Boost_USE_MULTITHREADED ON)
UNSET(Boost_INCLUDE_DIR CACHE)
UNSET(Boost_LIBRARY_DIRS CACHE)
FIND_PACKAGE(Boost REQUIRED COMPONENTS thread )
INCLUDE_DIRECTORIES(AFTER SYSTEM  ${Boost_INCLUDE_DIR})

###########################################################
# RULLO
###########################################################

SET(RULLO_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
SET(RULLO_SRC_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/src)
FILE(GLOB RULLO_SRC ${RULLO_SRC_DIR}/*.cpp)
FILE(GLOB RULLO_HDR ${RULLO_INCLUDE_DIR}/*.h)

SET(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/)

ADD_LIBRARY(${PROJECT_NAME} STATIC ${RULLO_SRC})

################################
# TEST using GTEST
################################
add_definitions(-DGTEST_HAS_TR1_TUPLE=0)
SET(gtest_force_shared_crt ON)
ADD_SUBDIRECTORY (${CMAKE_CURRENT_SOURCE_DIR}/test/gtest-1.6.0)
#ENABLE_TESTING()
INCLUDE_DIRECTORIES(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} ${RULLO_INCLUDE_DIR})
FILE(GLOB TESTS_CPP ${CMAKE_CURRENT_SOURCE_DIR}/test/src/*.cpp)
FILE(GLOB TEST_H ${CMAKE_CURRENT_SOURCE_DIR}/test/src/*.h)
add_executable( test_runner ${TESTS_CPP} ${TEST_H})
TARGET_LINK_LIBRARIES(test_runner gtest gtest_main ${PROJECT_NAME})
ADD_TEST( test_runner test_runner )
