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
        dictionary<K,V> *_dictionaries;
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
    _dictionaries = new dictionary<K,V>[S];
}

template <typename K, typename V, int S>
hash_table<K,V,S>::~hash_table()
{
    delete[] _dictionaries;
}

template <typename K, typename V, int S>
void hash_table<K,V,S>::clear()
{
    for(int i=0; i<S; i++)
    {
        _dictionaries[i].clear();
    }
}

template <typename K, typename V, int S>
bool hash_table<K,V,S>::contains_key(K key)
{
    size_t i = _hash_fn(key)%S;
    return _dictionaries[i].contains_key(key);
}

template <typename K, typename V, int S>
bool hash_table<K,V,S>::contains_value(V value)
{
    for(int i=0; i<S; i++)
    {
        if(_dictionaries[i].contains_value(value))
        {
            return true;
        }
    }
    return false;
}

template <typename K, typename V, int S>
V hash_table<K,V,S>::get(K key)
{
    size_t i = _hash_fn(key)%S;
    return _dictionaries[i].get(key);
}

template <typename K, typename V, int S>
bool hash_table<K,V,S>::is_empty()
{
    for(int i=0; i<S; i++)
    {
        if(!_dictionaries[i].is_empty())
        {
            return false;
        }
    }
    return true;
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
    int size=0;
    for(int i=0; i<S; i++)
    {
        size += _dictionaries[i].size();
    }
    return size;
}

#endif
