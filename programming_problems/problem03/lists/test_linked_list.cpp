#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "linked_list.hpp"

template class LinkedList<int>;

TEST_CASE( "TODO", "[LinkedList]" ) {

    LinkedList<int> list;
}

TEST_CASE( "Test insert", "[LinkedList]" ) {
    LinkedList<int> list;
    list.insert(0,00);
    list.insert(1,11);
    list.insert(2,33);
    list.insert(2,22);

    REQUIRE(list.getEntry(2)==22);
    REQUIRE(list.getLength()==4);
}

TEST_CASE( "Test insert with invalid position", "[LinkedList]" ) {
    LinkedList<int> list;

    REQUIRE(list.insert(0,10));
    REQUIRE_FALSE(list.insert(10,101010));
}

TEST_CASE( "Test remove", "[LinkedList]" ) {
    LinkedList<int> list;
    list.insert(0,00);
    list.insert(1,11);
    list.insert(2,22);
    list.insert(3,33);
    list.remove(2);

    REQUIRE(list.getEntry(2)==33);
    REQUIRE(list.getLength()==3);
}

TEST_CASE( "Test remove with invalid position", "[LinkedList]" ) {
    LinkedList<int> list;
    list.insert(0,00);
    list.insert(1,11);
    list.insert(2,22);
    list.insert(3,33);

    REQUIRE(list.remove(1));
    REQUIRE_FALSE(list.remove(10));
}


TEST_CASE( "Test operator", "[LinkedList]" ) {
    LinkedList<int> list;
    list.insert(0,00);
    list.insert(1,11);
    list.insert(2,22);
    list.insert(3,33);
    list.remove(2);
    LinkedList<int> list2 = list;

    REQUIRE(list2.getLength()==list.getLength());

    for(int i=0;i<list.getLength();i++)
    {
        REQUIRE(list2.getEntry(i)==list.getEntry(i));
    }
}

TEST_CASE( "Test clear", "[LinkedList]" ) {
    LinkedList<int> list;
    list.insert(0,00);
    list.insert(1,11);
    list.insert(2,22);
    list.insert(3,33);
    list.clear();

    REQUIRE(list.getLength()==0);
    
}