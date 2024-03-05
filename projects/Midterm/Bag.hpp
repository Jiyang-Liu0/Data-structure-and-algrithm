#ifndef _BAG_HPP
#define _BAG_HPP

template<typename Item> class Bag
{
private:
    static const int CAPACITY = 10;
    Item items[CAPACITY];
    int size;

public:
    Bag();
    bool add(Item item);
    bool remove(Item item);
    bool contains(Item item);
};
#endif