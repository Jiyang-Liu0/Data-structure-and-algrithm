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

TEST_CASE("test recursion", "[FindPalindrome]"){
	FindPalindrome b;

	REQUIRE(b.add("a"));
	REQUIRE(b.add("AA"));
	REQUIRE(b.add("AaA"));
	REQUIRE(b.number() == 6);
}

TEST_CASE("test recursion with no Palindrome", "[FindPalindrome]"){
	FindPalindrome b;

	REQUIRE(b.add("QWE"));
	REQUIRE(b.add("asd"));
	REQUIRE(b.add("zxc"));
	REQUIRE(b.number() == 0);
}

TEST_CASE("Test add a value", "[FindPalindrome]"){
	FindPalindrome b;

	REQUIRE(b.add("aaa"));
	REQUIRE_FALSE(b.add("a1"));
	REQUIRE_FALSE(b.add("AaA"));
}

TEST_CASE("Test add vector", "[FindPalindrome]"){
	FindPalindrome b;
	std::vector<std::string> vec = {"a","AA","AaA"};
	REQUIRE(b.add(vec));
	REQUIRE(b.number() == 6);
}

TEST_CASE("Test cut test 1 with oddtimes>1", "[FindPalindrome]"){
	FindPalindrome b;
	std::vector<std::string> vec = {"abc","abd","dd"};
	REQUIRE_FALSE(b.cutTest1(vec));
}

TEST_CASE("Test cut test 1 with oddtimes<=1", "[FindPalindrome]"){
	FindPalindrome b;
	std::vector<std::string> vec = {"abc","abd","d"};
	REQUIRE(b.cutTest1(vec));
}

TEST_CASE("Test cut test 2 with success", "[FindPalindrome]"){
	FindPalindrome b;
	std::vector<std::string> vec1 = {"abc","abd"};
	std::vector<std::string> vec2 = {"abc","abd","efg"};

	REQUIRE(b.cutTest2(vec1,vec2));
}

TEST_CASE("Test cut test 2 with false", "[FindPalindrome]"){
	FindPalindrome b;
	std::vector<std::string> vec1 = {"abc","zxc"};
	std::vector<std::string> vec2 = {"abc","abd","efg"};

	REQUIRE_FALSE(b.cutTest2(vec1,vec2));
}

