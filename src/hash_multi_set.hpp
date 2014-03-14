// Alexis Giraudet
// Théo Cesbron

#ifndef HASH_MULTI_SET_HPP
#define HASH_MULTI_SET_HPP

#include "hash_table.hpp"

template <typename T, int S>
class hash_multi_set
{
    private:
        hash_table<T,int,S> _hash_table;

    public:
        hash_multi_set();
        ~hash_multi_set();
        void add(T type);
        void clear();
        int count(T type);
        bool equal(hash_multi_set &hms);   
        void fusion(hash_multi_set &hms);
        void intersection(hash_multi_set &hms);
        bool is_empty();
        void remove(T type);
        void remove_all(T type);
        int size();
        void sub(hash_multi_set &hms);
};

template <typename T, int S>
hash_multi_set<T,S>::hash_multi_set()
{
    ;
}

template <typename T, int S>
hash_multi_set<T,S>::~hash_multi_set()
{
    ;
}

template <typename T, int S>
void hash_multi_set<T,S>::add(T type)
{
    _hash_table.put(type, count(type)+1);
}

template <typename T, int S>
void hash_multi_set<T,S>::clear()
{
    _hash_table.clear();
}

template <typename T, int S>
int hash_multi_set<T,S>::count(T type)
{
    try
    {
        int i = _hash_table.get(type);
        return i;
    }
    catch(std::exception &e)
    {
        return 0;
    }
}

template <typename T, int S>
bool hash_multi_set<T,S>::equal(hash_multi_set &hms)
{
    if(size() != hms.size())
    {
        return false;
    }
    else
    {
        bool res = true;
        T *tmp = _hash_table.keys_array();
        for(int i=0; i<_hash_table.size(); i++)
        {
            if(count(tmp[i]) != hms.count(tmp[i]))
            {
                res = false;
                break;
            }
        }
        delete[] tmp;
        return res;
    }
}

template <typename T, int S>
void hash_multi_set<T,S>::fusion(hash_multi_set &hms)
{
    T *tmp = hms._hash_table.keys_array();
    for(int i=0; i<hms._hash_table.size(); i++)
    {
        _hash_table.put(tmp[i], count(tmp[i])+hms.count(tmp[i]));
    }
    delete[] tmp;
}

template <typename T, int S>
void hash_multi_set<T,S>::intersection(hash_multi_set &hms)
{
    T *tmp = _hash_table.keys_array();
    for(int i=0; i<_hash_table.size(); i++)
    {
        int j = hms.count(tmp[i]);
        if(j>0)
        {
            if(j<count(tmp[i]))
            {
                _hash_table.put(tmp[i], j);
            }
        }
        else
        {
            _hash_table.remove_all(tmp[i]);
        }
    }
    delete[] tmp;
}

template <typename T, int S>
bool hash_multi_set<T,S>::is_empty()
{
    return _hash_table.is_empty();
}

template <typename T, int S>
void hash_multi_set<T,S>::remove(T type)
{
    int i = count(type);
    if(i>1)
    {
        _hash_table.put(type, i-1);
    }
    else
    {
        _hash_table.remove(type);
    }
}

template <typename T, int S>
void hash_multi_set<T,S>::remove_all(T type)
{
    _hash_table.remove(type);
}

template <typename T, int S>
int hash_multi_set<T,S>::size()
{
    int res=0;
    int *tmp = _hash_table.values_array();
    for(int i=0; i<_hash_table.size(); i++)
    {
        res += tmp[i];
    }
    delete[] tmp;
    return res;
}

template <typename T, int S>
void hash_multi_set<T,S>::sub(hash_multi_set &hms)
{
    T *tmp = _hash_table.keys_array();
    for(int i=0; i<_hash_table.size(); i++)
    {
        int j = hms.count(tmp[i]);
        if(j>0)
        {
            int k = count(tmp[i]);
            if(k-j < 1)
            {
                remove_all(tmp[i]);
            }
            else
            {
                _hash_table.put(tmp[i], k-j);
            }
        }
    }
    delete[] tmp;
}

#endif
