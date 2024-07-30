project(tests)

find_package (Boost 1.76.0 COMPONENTS unit_test_framework REQUIRED)

add_executable(my_tests tests.cpp)
target_link_libraries(my_tests ${Boost_LIBRARIES} ${CMAKE_PROJECT_NAME}_lib)

add_test(NAME my_test COMMAND my_tests)
