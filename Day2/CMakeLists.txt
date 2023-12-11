add_executable(day2
    main.cc
    day2.cc)

add_executable(day2_tests
    day2.cc
    tests.cc
    )
target_link_libraries(day2_tests PRIVATE Catch2::Catch2WithMain)

target_compile_features(day2 PRIVATE cxx_std_17)
target_compile_features(day2_tests PRIVATE cxx_std_17)

catch_discover_tests(day2_tests)