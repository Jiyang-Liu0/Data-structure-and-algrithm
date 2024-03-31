#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"

#include "list.hpp"
#include "sorted_list.hpp"
#include "priority_queue.hpp"

TEST_CASE("Testing Priority Queue isEmpty", "[priority queue]") {
  typedef SortedList<int, List<int>> SortedListType;
  typedef PriorityQueue<int, SortedListType>  PriorityQueueType;

  PriorityQueueType pq;

  REQUIRE(pq.isEmpty());
  pq.add(1);
  REQUIRE_FALSE(pq.isEmpty());
}

TEST_CASE("Testing Priority Queue add", "[priority queue]") {
  typedef SortedList<int, List<int>> SortedListType;
  typedef PriorityQueue<int, SortedListType>  PriorityQueueType;

  PriorityQueueType pq;

  REQUIRE(pq.isEmpty());
  pq.add(3);
  pq.add(5);
  pq.add(1);
  REQUIRE(pq.peek()==5);
}

TEST_CASE("Testing Priority Queue remove", "[priority queue]") {
  typedef SortedList<int, List<int>> SortedListType;
  typedef PriorityQueue<int, SortedListType>  PriorityQueueType;

  PriorityQueueType pq;

  REQUIRE_THROWS(pq.remove());
  pq.add(3);
  pq.add(5);
  pq.add(1);
  pq.remove();
  REQUIRE(pq.peek()==3);
}

TEST_CASE("Testing Priority Queue peek", "[priority queue]") {
  typedef SortedList<int, List<int>> SortedListType;
  typedef PriorityQueue<int, SortedListType>  PriorityQueueType;

  PriorityQueueType pq;

  REQUIRE_THROWS(pq.peek());
  pq.add(5);
  pq.add(4);
  pq.add(6);
  REQUIRE(pq.peek()==6);
  pq.remove();
  REQUIRE(pq.peek()==5);
}
