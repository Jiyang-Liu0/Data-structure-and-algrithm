#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "dynamic_bag.hpp"

// force template expansion for ints

template class DynamicBag<int>;
TEST_CASE("Calling all public members", "[DynamicBag]"){
  DynamicBag<int> b;
  b.add(0);
  b.remove(0);
  b.isEmpty();
  b.getCurrentSize();
  b.clear();
  b.getFrequencyOf(0);
  b.contains(0);
}

TEST_CASE("Calling copy constructor", "[DynamicBag]"){
  DynamicBag<int> bag1;
  bag1.add(1);
  bag1.add(2);
  bag1.add(1);
  DynamicBag<int> bag2 = bag1; 
  REQUIRE(bag2.getCurrentSize()==bag1.getCurrentSize());
  REQUIRE_FALSE(bag2.isEmpty());
}

TEST_CASE("Calling copy assignment", "[DynamicBag]"){
  DynamicBag<int> bag1;
  DynamicBag<int> bag2;
  bag1.add(1);
  bag1.add(2);
  bag1.add(1);
  bag2 = bag1;
  REQUIRE(bag2.getCurrentSize()==bag1.getCurrentSize());
  REQUIRE_FALSE(bag2.isEmpty());
}

TEST_CASE("Calling add", "[DynamicBag]"){
  DynamicBag<int> bag1;
  bag1.add(1);
  bag1.add(2);
  bag1.add(1);
  REQUIRE(bag1.getCurrentSize()==3);
  REQUIRE_FALSE(bag1.isEmpty());
  REQUIRE(bag1.getFrequencyOf(1)==2);
  REQUIRE(bag1.getFrequencyOf(2)==1);
}

TEST_CASE("Calling add when exceed the arraySize", "[DynamicBag]"){
  DynamicBag<int> bag1;
  bag1.add(1);
  bag1.add(1);
  bag1.add(1);
  bag1.add(1);
  bag1.add(1);
  bag1.add(1);
  bag1.add(1);
  REQUIRE(bag1.getCurrentSize()==7);
  REQUIRE_FALSE(bag1.isEmpty());
}

TEST_CASE("Calling remove", "[DynamicBag]"){
  DynamicBag<int> bag1;
  bag1.add(1);
  bag1.add(2);
  bag1.add(1);
  bag1.add(3);
  bag1.remove(2);
  // REQUIRE(bag1.getCurrentSize()==2);
  REQUIRE_FALSE(bag1.isEmpty());
  REQUIRE(bag1.getFrequencyOf(2)==0);
  REQUIRE_FALSE(bag1.contains(2));
}

TEST_CASE("Calling isEmpty", "[DynamicBag]"){
  DynamicBag<int> bag1;
  bag1.add(2);
  bag1.remove(2);
  REQUIRE(bag1.isEmpty());
}

TEST_CASE("Calling getCurrentSize", "[DynamicBag]"){
  DynamicBag<int> bag1;
  bag1.add(1);
  bag1.add(2);
  bag1.add(1);
  bag1.remove(2);
  REQUIRE(bag1.getCurrentSize()==2);
  REQUIRE_FALSE(bag1.isEmpty());
}

TEST_CASE("Calling clear", "[DynamicBag]"){
  DynamicBag<int> bag1;
  bag1.add(1);
  bag1.add(2);
  bag1.add(1);
  bag1.clear();
  REQUIRE(bag1.getCurrentSize()==0);
  REQUIRE(bag1.isEmpty());
}

TEST_CASE("Calling getFrequencyOf", "[DynamicBag]"){
  DynamicBag<int> bag1;
  bag1.add(1);
  bag1.add(2);
  bag1.add(1);
  bag1.remove(2);
  REQUIRE(bag1.getCurrentSize()==2);
  REQUIRE(bag1.getFrequencyOf(1)==2);
}

TEST_CASE("Calling contains", "[DynamicBag]"){
  DynamicBag<int> bag1;
  bag1.add(1);
  bag1.add(2);
  bag1.add(1);
  bag1.remove(2);
  REQUIRE(bag1.contains(1));
  REQUIRE_FALSE(bag1.contains(2));
}
