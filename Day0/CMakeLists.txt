add_executable(day0
    main.cc
    day0.cc)

add_executable(day0_tests
    day0.cc
    )
target_link_libraries(day0_tests PRIVATE Catch2::Catch2WithMain)
