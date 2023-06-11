/**
 * @file FindPalindrome_test.cpp
 * @author Amit Nafshi (amn102@pitt.edu)
 * @brief Project 2: Palindromes
 * @version 0.1
 * @date 2023-06-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"
#include "FindPalindrome.hpp"

// There should be at least one test per FindPalindrome method

TEST_CASE( "Test adding a non-allowable word", "[FindPalindrome]" )
{
	FindPalindrome b;
	REQUIRE(!b.add("kayak1"));
}

TEST_CASE("Test Recursion", "[FindPalindrome]"){
	FindPalindrome b;

	REQUIRE(b.add("a"));
	REQUIRE(b.add("AA"));
	REQUIRE(b.add("AaA"));
	REQUIRE(b.number() == 6);
}

TEST_CASE("Test Clearing", "[FindPalindrome]")
{
    FindPalindrome b;

    REQUIRE(b.add("a"));
    REQUIRE(b.add("AA"));
    REQUIRE(b.add("AaA"));
    REQUIRE(b.number() == 6);

    b.clear();
    REQUIRE(b.number() == 0);
    REQUIRE(b.toVector().empty());
}

TEST_CASE("Test Add (single word)", "[FindPalindrome]") {
    FindPalindrome b;
    REQUIRE(b.add("a"));
    REQUIRE(b.number() == 1);
}

TEST_CASE("Test Add (vector)", "[FindPalindrome]") {
    FindPalindrome b;
    std::vector<std::string> words = {"AA", "AaA"};
    REQUIRE(b.add(words));
    REQUIRE(b.number() == 2);
}
