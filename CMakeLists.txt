# ============================================================================
#
# Introduction
# ------------
# 
# This file is the main file for the refcnt-helpers. The project follows 
# the pattern laid out at http://pile-contributors.github.io/
# for a `pile-helpers` repository.
#
# Usage
# -----
# 
# ============================================================================

set (PROJECT_NAME "refcnt-helpers")
set (INCLUDE_PILE_SOURCES_DIRECTLY ON)

project(${PROJECT_NAME})
cmake_minimum_required(VERSION 2.8.11)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set( CMAKE_RUNTIME_OUTPUT_DIRECTORY
    "${PROJECT_BINARY_DIR}/build/bin" )
set( EXECUTABLE_OUTPUT_PATH
    "${PROJECT_BINARY_DIR}/build/bin" )
set( LIBRARY_OUTPUT_PATH
    "${PROJECT_BINARY_DIR}/build/lib" )
set( INCLUDE_OUTPUT_PATH
    "${PROJECT_BINARY_DIR}/build/include/${PROJECT_NAME}" )
include_directories("${PROJECT_BINARY_DIR}/build/include")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}")

if(INCLUDE_PILE_SOURCES_DIRECTLY)
    include(pile_support)
    pileInclude (RefCnt)
    refcntInit(PILE)
else()
    set (REFCNT_BUILD_MODE SHARED)
    add_subdirectory(refcnt)
endif()

add_subdirectory(tests)

# ============================================================================
