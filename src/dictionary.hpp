// Alexis Giraudet
// Théo Cesbron

#ifndef DICTIONARY_HPP
#define DICTIONARY_HPP

#include <ostream>
#include <iostream>
#include <exception>

template <typename K, typename V>
class dictionary
{
    struct _link
    {
        K key;
        V value;
        _link *previous;
        _link *next;
    };
    
    private:
        _link *_head;
        _link *_tail;
        int _size;
    
    public:
        dictionary();
        ~dictionary();
        void clear();
        bool contains_key(K key);
        bool contains_value(V value);
        bool count(V value);//todo
        V get(K key);
        bool is_empty();
        //K* keys_array();
        std::ostream& print();
        std::ostream& print(std::ostream &os);
        bool put(K key, V value);
        bool remove(K key);
        int size();
        //V* values_array();
        void trousseau(K *clfs, int &n);
};

template <typename K, typename V>
dictionary<K,V>::dictionary(): _head(0), _tail(0), _size(0)
{
    ;
}

template <typename K, typename V>
dictionary<K,V>::~dictionary()
{
    clear();
}

template <typename K, typename V>
void dictionary<K,V>::clear()
{
    _link *tmp_link = _head;
    while(tmp_link != 0)
    {
        _link *del_link = tmp_link;
        tmp_link = (*tmp_link).next;
        delete del_link;
    }
    _head = 0;
    _tail = 0;
    _size = 0;
}

template <typename K, typename V>
bool dictionary<K,V>::contains_key(K key)
{
    _link *tmp_link = _head;
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
bool dictionary<K,V>::contains_value(V value)
{
    _link *tmp_link = _head;
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
V dictionary<K,V>::get(K key)
{
    _link *tmp_link = _head;
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
bool dictionary<K,V>::is_empty()
{
    return (_head == 0) && (_tail == 0);
}

template <typename K, typename V>
std::ostream& dictionary<K,V>::print()
{
    return print(std::cout);
}

template <typename K, typename V>
std::ostream& dictionary<K,V>::print(std::ostream &os)
{
    _link *tmp_link = _head;
    os << "size = " << _size << std::endl;
    while(tmp_link != 0)
    {
        os << (*tmp_link).key << " : " << (*tmp_link).value << std::endl;
        tmp_link = (*tmp_link).next;
    }
    return os;
}

template <typename K, typename V>
bool dictionary<K,V>::put(K key, V value)
{
    if(is_empty())
    {
        _link *new_link = new _link;
        (*new_link).key = key;
        (*new_link).value = value;
        (*new_link).previous = 0;
        (*new_link).next = 0;
        _head = new_link;
        _tail = new_link;
        return true;
    }
    else
    {
        _link *tmp_link = _head;
        while(tmp_link != 0)
        {
            if((*tmp_link).key == key)
            {
                (*tmp_link).value = value;
                return false;
            }
            tmp_link = (*tmp_link).next;
        }
        _link *new_link = new _link;
        (*new_link).key = key;
        (*new_link).value = value;
        (*new_link).previous = _tail;
        (*new_link).next = 0;
        (*_tail).next = new_link;
        _tail = new_link;
    }
    _size++;
    return true;
}

template <typename K, typename V>
bool dictionary<K,V>::remove(K key)
{
    _link *tmp_link = _head;
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
int dictionary<K,V>::size()
{
    return _size;
}

template <typename K, typename V>
std::ostream& operator<< (std::ostream &os, dictionary<K,V> &m)//todo fix set const dictionary
{
    return m.print(os);
}

template <typename K, typename V>
void dictionary<K,V>::trousseau(K *clfs, int &n)
{
    n = _size;
    int i = 0;
    _link *tmp_link = _head;
    while(tmp_link != 0)
    {
        clfs[i] = (*tmp_link).key;
        i++;
    }
}

#endif
