#ifndef BITSET_HPP
#define BITSET_HPP
#include <stdint.h>
#include <stdlib.h>
#include <string>

class Bitset{
public:

  // Default construction of a valid bitset of size 8, with all bits set to 0
  Bitset();

  // Construction of a valid bitset of size N,with all bits set to 0; the bitset is invalid if N <= 0.
  Bitset(intmax_t size);

  // Construction of a valid bitset initialized with a string of the form 00010000. If the string contains any character other than 0 or 1, the bitset is invalid.
  Bitset(const std::string & value);

  // To free the memory of bitArray
  ~Bitset();

  Bitset(const Bitset & ) = delete;
  Bitset & operator=(const Bitset &) = delete;

  // Return the size of the bitset
  intmax_t size() const;

  // Determine if the bitset is valid
  bool good() const;

  // Set the nth bit to 1, and if n is not in [0, N-1] then the bitset becomes invalid.
  void set(intmax_t index);

  // Reset the nth bit to 0
  void reset(intmax_t index);

  // Toggle the nth bit (1 to 0 or 0 to 1)
  void toggle(intmax_t index);

  // Check if the nth bit is set (1)
  bool test(intmax_t index);

  // Return the bitset as a std::string of characters 0 and 1 
  std::string asString() const;

private:
  std::uint8_t* bitArray;
  bool isValid;
  intmax_t sizeofArray;
};

#endif
