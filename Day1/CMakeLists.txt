add_executable(day1
    main.cc
    day1.cc)

add_executable(day1_tests
    day1.cc
    tests.cc)

target_link_libraries(day1_tests PRIVATE Catch2::Catch2WithMain)

target_compile_features(day1 PRIVATE cxx_std_17)
target_compile_features(day1_tests PRIVATE cxx_std_17)

catch_discover_tests(day1_tests)