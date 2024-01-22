#ifndef _ABSTRACT_BAG_HPP_
#define _ABSTRACT_BAG_HPP_

#include <cstdlib>

template<typename T> class AbstractBag{
    public:
    /** The constructor */
    AbstractBag() {};

    /** The destructor */
    virtual ~AbstractBag() {};

    /** Gets the current number of entries in this bag
    @return The integer number of entries currently in the bag.*/
    virtual std::size_t getCurrentSize() const = 0;

    /** Sees whether this bag is empty.
    @return True if the bag is empty, or false if not.*/
    virtual bool isEmpty() const = 0;

    /** Adds an Item to the bag.
    @param entry The item to be added.
    @return  True on success, else false*/
    virtual bool add(const T& entry) = 0;

    /** Removes a single instance of Item from the bag
    @param entry The item to be removed.
    @return  True on success, else false*/
    virtual bool remove(const T& entry) = 0;

    /** Removes all items in the bag*/
    virtual void clear() = 0;

    /** Gets the number of times item appears
    @param entry The item in the bag.
    @return  Returns the number of times Item appears in the bag*/
    virtual std::size_t getFrequencyOf(const T& entry) const = 0;

    /** Sees whether the bag contains item
    @param entry The item in the bag.
    @return  True if at least one item is in the bag, else false*/
    virtual bool contains(const T& entry) const = 0;

};


#endif