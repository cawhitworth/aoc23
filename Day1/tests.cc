#include <catch2/catch_test_macros.hpp>
#include "day1.h"

TEST_CASE( "Lines are evaluated correctly - part 1", "[lines1]")
{
    REQUIRE( process_line_part1("") == 0);
    REQUIRE( process_line_part1("1abc2") == 12);
    REQUIRE( process_line_part1("pqr3stu8vwx") == 38);
    REQUIRE( process_line_part1("a1b2c3d4e5f") == 15);
    REQUIRE( process_line_part1("treb7uchet") == 77);
}

TEST_CASE( "Lines are evaluated correctly - part 2", "[lines2]")
{
    REQUIRE( process_line_part2("") == 0);
    REQUIRE( process_line_part2("1abc2") == 12);
    REQUIRE( process_line_part2("pqr3stu8vwx") == 38);
    REQUIRE( process_line_part2("a1b2c3d4e5f") == 15);
    REQUIRE( process_line_part2("treb7uchet") == 77);

    REQUIRE( process_line_part2("two1nine") == 29);
    REQUIRE( process_line_part2("eightwothree") == 83);
    REQUIRE( process_line_part2("abcone2threexyz") == 13);
    REQUIRE( process_line_part2("xtwone3four") == 24);
    REQUIRE( process_line_part2("4nineeightseven2") == 42);
    REQUIRE( process_line_part2("zoneight234") == 14);
    REQUIRE( process_line_part2("7pqrstsixteen") == 76);
}
