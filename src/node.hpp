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
        dictionary<char,node<V>> _children;
        V* _value;

    public:
        node();
        ~node();
        void clear();
        bool contains(string::const_iterator it, string::const_iterator end) const;
        V get(string::const_iterator it, string::const_iterator end) const;
        bool is_empty() const;
        bool is_leaf() const;
        bool remove(string::const_iterator it, string::const_iterator end);
        bool set(const V& value, string::const_iterator it, string::const_iterator end);
        int size() const;
        pair<string*,V*> to_array() const;
    private:
        V get_value() const;
        bool remove_value();
        bool set_value(const V& value);
        int to_array(string* strings_array ,V* values_array, int index, string acc) const;
};

template <typename V>
node<V>::node(): _value(0)
{
    ;
}

template <typename V>
node<V>::~node()
{
    clear();
}

template <typename V>
void node<V>::clear()
{
    delete _value;
    _value = 0;
    _children.clear();
}

template <typename V>
bool node<V>::contains(string::const_iterator it, string::const_iterator end) const
{
    try
    {
        if(it == end)
        {
            return _children.get_ref(*it).is_empty();
        }
        else
        {
            string::const_iterator next(it);
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
V node<V>::get(string::const_iterator it, string::const_iterator end) const
{
    if(it == end)
    {
        return _children.get_ref(*it).get_value();
    }
    else
    {
        string::const_iterator next(it);
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
bool node<V>::remove(string::const_iterator it, string::const_iterator end)
{
    try
    {
        if(it == end)
        {
            if(_children.get_ref(*it).is_leaf())
            {
                return _children.remove(*it);
            }
            else
            {
                return _children.get_ref(*it).remove_value();
            }
        }
        else
        {
            string::const_iterator next(it);
            next++;
            if(_children.get_ref(*it).remove(next,end))
            {
                if(_children.get_ref(*it).is_leaf())
                {
                    _children.remove(*it);
                }
                return true;
            }
            else
            {
                return false;
            }
        }
    }
    catch(exception& e)
    {
        return false;
    }
}

template <typename V>
bool node<V>::remove_value()
{
    if(is_empty())
    {
        return false;
    }
    else
    {
        delete _value;
        _value = 0;
        return true;
    }
}

template <typename V>
bool node<V>::set(const V& value, string::const_iterator it, string::const_iterator end)
{
    try
    {
        if(it == end)
        {
            return _children.get_ref(*it).set_value(value);
        }
        else
        {
            string::const_iterator next(it);
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

template <typename V>
int node<V>::size() const
{
    int acc = 0;
    if(!is_empty())
    {
        acc++;
    }
    char* keys = _children.keys_array();
    for(int i=0; i<_children.size(); i++)
    {
        acc += _children.get_ref(keys[i]).size();
    }
    delete[] keys;
    return acc;
}

template <typename V>
pair<string*,V*> node<V>::to_array() const
{
    int _size = size();
    string* strings_array = new string[_size];
    V* values_array = new V[_size];
    pair<string*,V*> res(strings_array,values_array);
    to_array(strings_array,values_array,0,string());
    return res;
}

template <typename V>
int node<V>::to_array(string* strings_array ,V* values_array, int index, string acc) const
{
    char* keys = _children.keys_array();
    for(int i=0; i<_children.size(); i++)
    {
        string key(acc);
        key.push_back(keys[i]);
        if(!_children.get_ref(keys[i]).is_empty())
        {
            strings_array[index] = key;
            values_array[index] = _children.get_ref(keys[i]).get_value();
            index++;
        }
        index = _children.get_ref(keys[i]).to_array(strings_array,values_array,index,key);
    }
    delete[] keys;
    return index;
}

#endif
