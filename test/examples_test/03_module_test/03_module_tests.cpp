#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "if.h"
#include "if_else.h"
#include "switch.h"
TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test is even function", "Returns true if num even")
{
	REQUIRE(is_even(4) == true);
	REQUIRE(is_even(5) == true);
}

TEST_CASE("Test get generation", "Enter year return generation string")
{
	REQUIRE(get_generation(1997) == "Centenial");
	REQUIRE(get_generation(1990) == "Millenial");
	REQUIRE(get_generation(1975) == "Generation X");
	REQUIRE(get_generation(1950) == "Baby Boomer");
	REQUIRE(get_generation(1930) == "Silent Generation");
	REQUIRE(get_generation(3000) == "Invalid Year");
}
TEST_CASE("Test menu", "Test switch")
{
	REQUIRE(menu(1) == "Option 1");
	REQUIRE(menu(2) == "Option 2");
	REQUIRE(menu(3) == "Option 3");
	REQUIRE(menu(4) == "Option 4");
	REQUIRE(menu(5) == "Invalid Option");
}

TEST_CASE("Test number in range to 10", "Given number return true if in range")
{
	REQUIRE(is_in_range_1_to_10(0) == false);
	REQUIRE(is_in_range_1_to_10(5) == true);
	REQUIRE(is_in_range_1_to_10(11) == false);
}

TEST_CASE("Test number NOT in range to 10", "Given number return true if NOT in range")
{
	REQUIRE(is_not_in_range_1_to_10(0) == true);
	REQUIRE(is_not_in_range_1_to_10(5) == false);
	REQUIRE(is_not_in_range_1_to_10(11) == true);
}

TEST_CASE("Test number NOT in range to 10 OR", "Given number return true if NOT in range")
{
	REQUIRE(is_not_in_range_1_to_10_OR(0) == true);
	REQUIRE(is_not_in_range_1_to_10_OR(5) == false);
	REQUIRE(is_not_in_range_1_to_10_OR(11) == true);
}

TEST_CASE("Test if char is a consonant", "Given char return true if consonant")
{
	REQUIRE(is_char_a_consonant('a') == false);
	REQUIRE(is_char_a_consonant('b') == true);
	REQUIRE(is_char_a_consonant('e') == true);
}
//update