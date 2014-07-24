cmake_minimum_required(VERSION 2.8)
project(UVa-Online-Judge)

set(CMAKE_C_FLAGS "-std=c99 ${CMAKE_C_FLAGS}")
set(CMAKE_CXX_FLAGS "-std=c++98 ${CMAKE_CXX_FLAGS}")

configure_file(
    ${PROJECT_SOURCE_DIR}/test.in
    ${PROJECT_BINARY_DIR}/test
    @ONLY
)
execute_process(COMMAND chmod +x ${PROJECT_BINARY_DIR}/test)

set(TEST_DIR ${PROJECT_BINARY_DIR}/bin)
execute_process(COMMAND ${CMAKE_COMMAND} -E make_directory ${TEST_DIR})

enable_testing()

file(GLOB all_src ${PROJECT_SOURCE_DIR}/src/*)
foreach(src ${all_src})
    get_filename_component(exec_name ${src} NAME_WE)
    add_executable(${exec_name} ${src})
    set_target_properties(${exec_name} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${TEST_DIR}
    )

    add_test(test-${exec_name} ${PROJECT_BINARY_DIR}/test ${exec_name} ${PROJECT_SOURCE_DIR} ${PROJECT_BINARY_DIR})
endforeach()
