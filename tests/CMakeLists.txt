enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

if (NOT INCLUDE_PILE_SOURCES_DIRECTLY)
    set (REF_CNT_LIBRARY refcnt)
endif()

add_executable(test_basic
    ${REFCNT_SOURCES}
    ${REFCNT_HEADERS}
    basic.cc)
target_link_libraries(test_basic
    ${GTEST_BOTH_LIBRARIES}
    ${REF_CNT_LIBRARY})

add_test(AllTestsInFoo test_basic)
