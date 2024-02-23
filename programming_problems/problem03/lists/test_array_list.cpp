#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "array_list.hpp"

//force class expansion
template class ArrayList<int>;

TEST_CASE( "Test", "[ArrayList]" ) {

  ArrayList<int> list;
}

TEST_CASE( "Test constructor", "[ArrayList]" ) {

  ArrayList<int> list;
  REQUIRE(list.getLength()==0);
}

TEST_CASE( "Test operator", "[ArrayList]" ) {

  ArrayList<int> list;
  ArrayList<int> list2 = list;
  REQUIRE(list2.getLength()==0);
}

TEST_CASE( "Test copy constructor", "[ArrayList]" ) {

  ArrayList<int> list;
  ArrayList<int> list2(list);
  REQUIRE(list2.getLength()==0);
}

TEST_CASE( "Test insert", "[ArrayList]" ) {

  ArrayList<int> list;
  list.insert(0,0);
  list.insert(1,1);
  list.insert(2,3);
  list.insert(2,2);

  REQUIRE(list.getLength()==4);
  REQUIRE(list.getEntry(2)==2);
  REQUIRE(list.getEntry(3)==3); 
}

TEST_CASE( "Test remove", "[ArrayList]" ) {

  ArrayList<int> list;
  list.insert(0,0);
  list.insert(1,1);
  list.insert(2,1);
  list.insert(3,2);
  list.remove(1);

  REQUIRE(list.getLength()==3);
  REQUIRE(list.getEntry(1)==1);
  REQUIRE(list.getEntry(2)==2);
}

TEST_CASE( "Test setEntry", "[ArrayList]" ) {

  ArrayList<int> list;
  list.insert(0,0);
  list.insert(1,1);
  list.insert(2,5);
  list.setEntry(2,2);

  REQUIRE(list.getEntry(2)==2);
  REQUIRE(list.getLength()==3);
}