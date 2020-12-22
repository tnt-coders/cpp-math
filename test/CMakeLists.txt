include(Catch)

add_executable(${PROJECT_NAME}_test
    main.cpp
    comparison_test.cpp
    math_test.cpp
    vector_test.cpp
)

target_link_libraries(${PROJECT_NAME}_test
    tnt::${PROJECT_NAME}
    Catch2::Catch2WithMain
)

catch_discover_tests(${PROJECT_NAME}_test)