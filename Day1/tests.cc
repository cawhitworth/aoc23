#include <catch2/catch_test_macros.hpp>
#include "day1.h"

TEST_CASE( "Lines are evaluated correctly", "[lines]")
{
    REQUIRE( process_line("1abc2") == 12);
    REQUIRE( process_line("pqr3stu8vwx") == 38);
    REQUIRE( process_line("a1b2c3d4e5f") == 15);
    REQUIRE( process_line("treb7uchet") == 77);
}