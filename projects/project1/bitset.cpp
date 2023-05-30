#include "bitset.hpp"

// Default constructor
Bitset::Bitset()
{
    bitSize = 8;
    bitData = new uint8_t[bitSize]{}; // {} at the end initializes all elements to 0
    valid = true;
}

// Constructor (size parameter)
Bitset::Bitset(intmax_t size) 
{
    // Check and initialize bit size 
    if (size <= 0)
    {
        valid = false;
    }
    else
    {
        bitSize = size;
        valid = true;
    }
    bitData = new uint8_t[bitSize]{}; // {} at the end initializes all elements to 0
}

// Constructor (string parameter)
Bitset::Bitset(const std::string & value) 
{
    bitSize = value.length();
    valid = true;
    bitData = new uint8_t[bitSize];  // no {}, just set the array size

    // Check if string is valid and fill data array bit by bit until error or end
    for (intmax_t i = 0; i < bitSize; i++)
    {
        if (value[i] == '0')
        {
            bitData[i] = 0;
        }
        else if (value[i] == '1')
        {
            bitData[i] = 1;
        }
        else
        {
            valid = false;
        }
    }
}

// Destructor
Bitset::~Bitset() 
{
    delete [] bitData;
}

// Return bitset size
intmax_t Bitset::size() const
{
    return bitSize;
}

// Determine if bitset is valid
bool Bitset::good() const
{
    return valid;
}

// Set nth bit to 1
void Bitset::set(intmax_t index)
{
    if (index >= 0 && index < bitSize)
    {
        bitData[index] = 1;
    }
    else
    {
        valid = false;
    }
}

// Set nth bit to 0
void Bitset::reset(intmax_t index)
{
    if (index >= 0 && index < bitSize)
    {
        bitData[index] = 0;
    }
    else
    {
        valid = false;
    }
}

// Set Toggle nth bit
void Bitset::toggle(intmax_t index)
{
    if (index < 0 || index >= bitSize)
    {
        valid = false;
    }
    else
    {
        if (bitData[index] == 0)
        {
            bitData[index] = 1;
        }
        else if (bitData[index] == 1)
        {
            bitData[index] = 0;
        }
    }
}

// Test nth bit
bool Bitset::test(intmax_t index)
{
    if (index >= 0 && index < bitSize)
        {
            return bitData[index] == 1;
        }
        else
        {
            valid = false;
            return false;
        }
}

// Return bitset as string
std::string Bitset::asString() const
{
    std::string result;
    for (intmax_t i = 0; i < bitSize; i++)
    {
        result += bitData[i] == 0 ? '0' : '1'; // conditonal operator to check index and convert to string accordingly
    }
    return result;
}