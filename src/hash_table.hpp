// Alexis Giraudet
// Théo Cesbron

#ifndef HASH_TABLE_HPP
#define HASH_TABLE_HPP

#include <functional>
#include <exception>
#include "dictionary.hpp"

template <typename K, typename V, int S=100>
class hash_table
{
    private:
        dictionary *_dictionaries;
        
    
    public:
        hash_table();
        ~hash_table();
};

template <typename K, typename V, int S>
hash_table<K,V>::hash_table()
{
    _dictionaries = new dictionary[S];
}

template <typename K, typename V, int S>
hash_table<K,V>::~hash_table()
{
    
    ;
}

#endif
