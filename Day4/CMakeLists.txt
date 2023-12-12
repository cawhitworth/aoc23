add_executable(day4
    main.cc
    day4.cc)

add_executable(day4_tests
    day4.cc
    tests.cc
    )

target_link_libraries(day4_tests PRIVATE Catch2::Catch2WithMain)

target_compile_features(day4 PRIVATE cxx_std_20)
target_compile_features(day4_tests PRIVATE cxx_std_20)

catch_discover_tests(day4_tests)