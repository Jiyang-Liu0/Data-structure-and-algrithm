#include "Bag.hpp"

template<typename Item>
Bag<Item>::Bag() : size(0) {}

template<typename Item>
bool Bag<Item>::add(Item item)
{
    if (size < CAPACITY)
    {
        items[size] = item;
        size++;
        return true;
    }
    return false;
};

template<typename Item>
bool Bag<Item>::remove(Item item)
{
    int position = -1;
    for (int i = 0; i < size; i++)
    {
        if (items[i] == item)
        {
            position = i;
            break;
        }
    }
    if (position == -1)
        return false;
    for (int i = position; i < size; i++)
    {
        items[i] = items[i + 1];
    }
    size--;
    return true;
};

template<typename Item>
bool Bag<Item>::contains(Item item)
{
    if (remove(item))
    {
        add(item);
        return true;
    }
    return false;
}