enable_testing()

file(GLOB_RECURSE TEST_FILES "*.cpp")

include(GoogleTest)

foreach(TEST_FILE ${TEST_FILES})
    get_filename_component(TEST_NAME ${TEST_FILE} NAME_WE)
    add_executable(${TEST_NAME} ${TEST_FILE})
    target_link_libraries(${TEST_NAME} Library GTest::gtest_main)
    gtest_discover_tests(${TEST_NAME})
endforeach(TEST_FILE ${TEST_FILES})

