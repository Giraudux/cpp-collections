// Alexis Giraudet

#ifndef MAP_HPP
#define MAP_HPP

#include <exception>
#include <new>

template <typename K, typename V>
class map
{
    struct link
    {
        K key;
        V value;
        link *previous;
        link *next;
    };
    
    private:
        link *_head;
        link *_tail;
        int _size;
    
    public:
        map();
        ~map();
        void clear();
        bool contains_key(K key);
        bool contains_value(V value);
        V get(K key);
        bool is_empty();
        //K* keys_array();
        bool put(K key, V value);
        bool remove(K key);
        int size();
        //V* values_array();
};

template <typename K, typename V>
map<K,V>::map(): _head(0), _tail(0), _size(0)
{
    ;
}

template <typename K, typename V>
map<K,V>::~map()
{
    clear();
}

template <typename K, typename V>
void map<K,V>::clear()
{
    link *tmp_link = _head;
    while(tmp_link != 0)
    {
        link *del_link = tmp_link;
        tmp_link = (*tmp_link).next;
        delete del_link;
    }
    _head = 0;
    _tail = 0;
    _size = 0;
}

template <typename K, typename V>
bool map<K,V>::contains_key(K key)
{
    link *tmp_link = _head;
    while(tmp_link != 0)
    {
        if((*tmp_link).key == key)
        {
            return true;
        }
        tmp_link = (*tmp_link).next;
    }
    return false;
}

template <typename K, typename V>
bool map<K,V>::contains_value(V value)
{
    link *tmp_link = _head;
    while(tmp_link != 0)
    {
        if((*tmp_link).value == value)
        {
            return true;
        }
        tmp_link = (*tmp_link).next;
    }
    return false;
}

template <typename K, typename V>
V map<K,V>::get(K key)
{
    link *tmp_link = _head;
    while(tmp_link != 0)
    {
        if((*tmp_link).key == key)
        {
            return (*tmp_link).value;
        }
        tmp_link = (*tmp_link).next;
    }
    throw std::exception();
}

template <typename K, typename V>
bool map<K,V>::is_empty()
{
    return (_head == 0) && (_tail == 0);
}

template <typename K, typename V>
bool map<K,V>::put(K key, V value)
{
    if(is_empty())
    {
        try
        {
            link *new_link = new link;
            (*new_link).key = key;
            (*new_link).value = value;
            (*new_link).previous = 0;
            (*new_link).next = 0;
            _head = new_link;
            _tail = new_link;
        }
        catch(std::bad_alloc &e)
        {
            return false;
        }
    }
    else
    {
        link *tmp_link = _head;
        while(tmp_link != 0)
        {
            if((*tmp_link).key == key)
            {
                (*tmp_link).value = value;
                return true;
            }
            tmp_link = (*tmp_link).next;
        }
        try
        {
            link *new_link = new link;
            (*new_link).key = key;
            (*new_link).value = value;
            (*new_link).previous = _tail;
            (*new_link).next = 0;
            (*_tail).next = new_link;
            _tail = new_link;
        }
        catch(std::bad_alloc &e)
        {
            return false;
        }
    }
    _size++;
    return true;
}

template <typename K, typename V>
bool map<K,V>::remove(K key)
{
    link *tmp_link = _head;
    while(tmp_link != 0)
    {
        if((*tmp_link).key == key)
        {
            if(tmp_link == _head)
            {
                _head = (*tmp_link).next;
            }
            else
            {
                (*(*tmp_link).previous).next = (*tmp_link).next;
            }
            
            if(tmp_link == _tail)
            {
                _tail = (*tmp_link).previous;
            }
            else
            {
                (*(*tmp_link).next).previous = (*tmp_link).previous;
            }
            
            delete tmp_link;
            _size--;
            return true;
        }
        tmp_link = (*tmp_link).next;
    }
    return false;
}

template <typename K, typename V>
int map<K,V>::size()
{
    return _size;
}

#endif