file(GLOB_RECURSE TEST_FILES "*.cpp")

foreach(TEST_FILE ${TESTFILES})
    get_filename_component(TEST_NAME ${TEST_FILE} NAME_WE)
    add_executable(${TEST_NAME} ${TEST_FILE})
    target_link_libraries(${TEST_NAME} Library)
    add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
endforeach(TEST_FILE ${TESTFILES})
