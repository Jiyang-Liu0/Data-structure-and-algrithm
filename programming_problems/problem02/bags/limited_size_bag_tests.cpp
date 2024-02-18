#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "limited_size_bag.hpp"

// force template expansion for ints
template class LimitedSizeBag<int>;

TEST_CASE("Calling all public members", "[LimitedSizeBag]"){
  LimitedSizeBag<int> b;

  b.add(0);
  b.remove(0);
  b.isEmpty();
  b.getCurrentSize();
  b.clear();
  b.getFrequencyOf(0);
  b.contains(0);
}

TEST_CASE("Calling constructor", "[LimitedSizeBag]"){
  LimitedSizeBag<int> bag1;
  REQUIRE(bag1.isEmpty());
}

TEST_CASE("Calling add", "[LimitedSizeBag]"){
  LimitedSizeBag<int> bag1;
  bag1.add(1);
  bag1.add(2);
  bag1.add(1);
  REQUIRE(bag1.getCurrentSize()==3);
  REQUIRE_FALSE(bag1.isEmpty());
  REQUIRE(bag1.getFrequencyOf(1)==2);
  REQUIRE(bag1.getFrequencyOf(2)==1);
}

TEST_CASE("Calling remove", "[LimitedSizeBag]"){
  LimitedSizeBag<int> bag1;
  bag1.add(1);
  bag1.add(2);
  bag1.add(1);
  bag1.add(3);
  bag1.remove(2);
  REQUIRE(bag1.getCurrentSize()==3);
  REQUIRE(bag1.getFrequencyOf(2)==0);
  REQUIRE_FALSE(bag1.contains(2));
}

TEST_CASE("Calling isEmpty", "[DynamicBag]"){
  LimitedSizeBag<int> bag1;
  bag1.add(2);
  bag1.remove(2);
  REQUIRE(bag1.isEmpty());
}

TEST_CASE("Calling getCurrentSize", "[DynamicBag]"){
  LimitedSizeBag<int> bag1;
  bag1.add(1);
  bag1.add(2);
  bag1.add(1);
  bag1.add(3);
  bag1.remove(2);
  REQUIRE(bag1.getCurrentSize()==3);
  REQUIRE_FALSE(bag1.isEmpty());
}

TEST_CASE("Calling clear", "[DynamicBag]"){
  LimitedSizeBag<int> bag1;
  bag1.add(1);
  bag1.add(2);
  bag1.add(1);
  bag1.clear();
  REQUIRE(bag1.getCurrentSize()==0);
  REQUIRE(bag1.isEmpty());
}

TEST_CASE("Calling getFrequencyOf", "[DynamicBag]"){
  LimitedSizeBag<int> bag1;
  bag1.add(1);
  bag1.add(2);
  bag1.add(1);
  bag1.remove(2);
  REQUIRE(bag1.getCurrentSize()==2);
  REQUIRE(bag1.getFrequencyOf(1)==2);
}

TEST_CASE("Calling contains", "[DynamicBag]"){
  LimitedSizeBag<int> bag1;
  bag1.add(1);
  bag1.add(2);
  bag1.add(1);
  bag1.remove(2);
  REQUIRE(bag1.contains(1));
  REQUIRE_FALSE(bag1.contains(2));
}