// Given below is the class Bag. Suppose you are to implement a class
// ExamBag that derives from Bag, with an additional method “void clear()” and an
// overridden “add” method. Write your class declaration ExamBag.hpp on the
// following page. Minor syntax errors will be forgiven, but syntax should be as close as
// possible to the actual code.

#ifndef _EXAMBAG_HPP_
#define _EXAMBAG_HPP_

#include "Bag.hpp"

template<typename Item>
class ExamBag: public Bag<Item>
{
private:
    /* data */
public:
    void clear();
    bool add(Item item);
};


#endif
