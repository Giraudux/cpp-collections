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
        std::hash<K> _hash_fn;
        
    
    public:
        hash_table();
        ~hash_table();
        void clear();
        bool contains_key(K key);
        bool contains_value(V value);
        int count(V value);//todo
        V get(K key);
        bool is_empty();
        //K* keys_array();
        std::ostream& print();
        std::ostream& print(std::ostream &os);
        bool put(K key, V value);
        bool remove(K key);
        int size();
        //V* values_array();
};

template <typename K, typename V, int S>
hash_table<K,V,S>::hash_table(): _dictionaries(0)
{
    _dictionaries = new dictionary[S];
}

template <typename K, typename V, int S>
hash_table<K,V,S>::~hash_table()
{
    
    delete[] _dictionaries;
}

template <typename K, typename V, int S>
V hash_table<K,V,S>::get(K key)
{
    size_t i = _hash_fn(key)%S;
    return _dictionaries[i].get(key);
}

template <typename K, typename V, int S>
bool hash_table<K,V,S>::put(K key, V value)
{
    size_t i = _hash_fn(key)%S;
    return _dictionaries[i].put(key,value);
}

template <typename K, typename V, int S>
bool hash_table<K,V,S>::remove(K key)
{
    size_t i = _hash_fn(key)%S;
    return _dictionaries[i].remove(key);
}

template <typename K, typename V, int S>
int hash_table<K,V,S>::size()
{
    return S;
}

#endif
