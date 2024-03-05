#ifndef _POKEMON_HPP_
#define _POKEMON_HPP_

template<typename T> class Pokemon
{
private:
    /* data */
public:
    //evolve: Evolves the Pokemon (if possible). Takes an evolution item as input, returns true if the evolution was successful and false if not.
    virtual bool evolve(const T& item)=0;

    //attack: Performs a basic attack. Takes no arguments, and returns the numerical damage inflicted by the attack.
    virtual int attack()=0;

    //special: Performs a special attack. Takes no arguments, and returns the numerical damage inflicted by the attack.
    virtual int special()=0;

    //defend: Reduces damage for the next turn. Does not require any inputs, does not return any values.
    virtual void defend()=0;

    //use: Applies an item. Takes the item as input and returns true if the effect was successful, and false if not.
    virtual bool use(const T& item)=0;
};


#endif