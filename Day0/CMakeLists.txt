add_executable(day0
    main.cc
    day0.cc)

add_executable(day0_tests
    day0.cc
    tests.cc
    )

target_link_libraries(day0_tests PRIVATE Catch2::Catch2WithMain)

target_compile_features(day0 PRIVATE cxx_std_17)
target_compile_features(day0_tests PRIVATE cxx_std_17)

catch_discover_tests(day0_tests)