#ifndef BITSET_HPP
#define BITSET_HPP
#include <stdint.h>
#include <stdlib.h>
#include <string>

class Bitset{
public:
  // Default constructor
  Bitset();

  // Constructor with bitset size = N
  Bitset(intmax_t size);

  // Constructor with bitset size = length of string "value"
  Bitset(const std::string & value);

  // Destructor
  ~Bitset();

  Bitset(const Bitset & ) = delete;
  Bitset & operator=(const Bitset &) = delete;

  // Return bitset size
  intmax_t size() const;

  // Determine if bitset is valid
  bool good() const;

  // Set nth bit
  void set(intmax_t index);

  // Reset nth bit
  void reset(intmax_t index);

  // Toggle nth bit
  void toggle(intmax_t index);

  // Test nth bit
  bool test(intmax_t index);

  // Return bitset as string
  std::string asString() const;

private:
  // Bit size variable
  intmax_t bitSize;

  // Bit data array 
  uint8_t* bitData;

  // Validity bool
  bool valid;
};

#endif
