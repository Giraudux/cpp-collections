// Alexis Giraudet
// Théo Cesbron

#ifndef NODE_HPP
#define NODE_HPP

#include "dictionary.hpp"

using namespace std;

template <typename V>
class node
{
    private:
        node<V>* _father;
        dictionary<char,node<V>> _children;
        V* _value;

    public:
        node(node<V>* father=0);
        ~node();
        bool add(const V& value);
        bool contains(string::iterator it, const string::iterator end) const;
        V get(string::iterator it, const string::iterator end) const;
        V get_value() const;
        bool is_empty() const;
        bool is_leaf() const;
        bool set(const V& value, string::iterator it, const string::iterator end);
        bool set_value(const V& value);
};

template <typename V>
node<V>::node(node<V>* father): _father(father), _value(0)
{
    ;
}

template <typename V>
node<V>::~node()
{
    delete _value;
}

template <typename V>
bool node<V>::contains(string::iterator it, const string::iterator end) const
{
    try
    {
        if(it == end)
        {
            return _children.get_ref(*it).is_empty();
        }
        else
        {
            string::iterator next(it);
            next++;
            return _children.get_ref(*it).contains(next,end);
        }
    }
    catch(exception& e)
    {
        return false;
    }
}

template <typename V>
V node<V>::get(string::iterator it, const string::iterator end) const
{
    if(it == end)
    {
        return _children.get_ref(*it).get_value();
    }
    else
    {
        string::iterator next(it);
        next++;
        return _children.get_ref(*it).get(next,end);
    }
}

template <typename V>
V node<V>::get_value() const
{
    if(is_empty())
    {
        throw exception();
    }
    else
    {
        return *_value;
    }
}

template <typename V>
bool node<V>::is_empty() const
{
    return _value == 0;
}

template <typename V>
bool node<V>::is_leaf() const
{
    return _children.is_empty();
}

template <typename V>
bool node<V>::set(const V& value, string::iterator it, const string::iterator end)
{
    try
    {
        if(it == end)
        {
            return _children.get_ref(*it).set_value(value);
        }
        else
        {
            string::iterator next(it);
            next++;
            return _children.get_ref(*it).set(value,next,end);
        }
    }
    catch(exception& e)
    {
        _children.put(*it,node<V>());
        return set(value,it,end);
    }
}

template <typename V>
bool node<V>::set_value(const V& value)
{
    if(_value == 0)
    {
        _value = new V(value);
        return false;
    }
    else
    {
        *_value = value;
        return true;
    }
}

#endif
