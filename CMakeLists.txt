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
project(${PROJECT_NAME})
cmake_minimum_required(VERSION 2.8.11)


set (CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/build/bin")

#set (INCLUDE_PILE_SOURCES_DIRECTLY ON)
#if (INCLUDE_PILE_SOURCES_DIRECTLY)
#    include(pile_support)
#    pileInclude (RefCnt)

#    refcntInit(PILE)
#    add_executable(
#        ${PROJECT_NAME}
#        main.cc
#        ${REFCNT_SOURCES}
#        ${REFCNT_HEADERS})
#else()
#    set (REFCNT_BUILD_MODE SHARED)

#    add_subdirectory(refcnt)
#    add_executable(
#        ${PROJECT_NAME}
#        main.cc)
#    target_link_libraries(
#        ${PROJECT_NAME}
#        refcnt)
#endif()



# ============================================================================
