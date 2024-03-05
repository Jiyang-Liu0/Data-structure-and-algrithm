#define CATCH_CONFIG_MAIN
#include "catch.hpp"


/**
 * @brief Check if an item is contained in the examChest 
 * @param item The item to be checked
 * @return True if the item is contained, False if not
 * @details Check one item per call
*/


3. (6 points) For each operator below, describe how you would interpret and
implement this overloaded operator for the Bag ADT discussed in class. If you do
not think it would make sense to overload the specified operator for the Bag class,
explain why not.
a) The equality operator: Bag& Bag::operator==(const Bag& x)
Check if the sizes are equal.
Use contains() to check if every item in x is contained in this,and every item in this is contained in x.
If above 2 conditions satisfied, return true; else return false.

b) The addition assignment operator: Bag& Bag::operator+=(const Bag& x)
Iterate the items in x.
Use add() to add each item in x to this.
If add the exist item in this from x, then ignore the item.
Return this.


4. (8 points) The following questions are concerned with array- and link-based
implementations. For the following applications, indicate which of the following
three implementations you would choose, and justify your choice:

i. Fixed-size array ii. Dynamic array iii. Link-based

a) (4 points) A limited-size Bag implementation, where you know the maximum size of
the Bag in advance.
i. The reason is we dont need to change the size of the bag. For fixed size array,
the reading complexity is O(1), which is the lowest. The writing complexity is O(n),
where the O(n) is predictable.

b) (4 points) A List implementation, for an application where you need to frequently
insert and remove items in the middle of the list.
iii. For linked-based, the reading complexity is O(n), and the inserting/removing complexity
is O(1). But for Dynamic array, if the size is out of maximum, then there would be O(n) extra
allocate space operations. Even though no allocate space happened, the worst case is to have
O(n) shifting. For frequently inserting and removing, iii is the best choice.
