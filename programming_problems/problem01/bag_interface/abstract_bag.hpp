#ifndef _ABSTRACT_BAG_HPP_
#define _ABSTRACT_BAG_HPP_

#include <cstdlib>

template<class T> 
class AbstractBag{
    public:
        virtual void add(const T& entry) = 0;
        virtual bool remove(const T& entry) = 0;
        virtual std::size_t getFrequencyOf(const T& entry) const = 0;
        virtual bool contains(const T& entry) const = 0;
        virtual std::size_t size() const = 0;
        virtual void clear() = 0;
    private:
        std::size_t size;
};

#endif