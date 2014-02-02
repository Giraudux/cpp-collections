// Alexis Giraudet

#ifndef MAP_HPP
#define MAP_HPP

#include <exception>

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
        link *head;
        link *tail;
        int size;
    
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
map<K,V>::map(): head(0); tail(0), size(0)
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
    link *tmp_link = head;
    while(tmp_link != 0)
    {
        link *del_link = tmp_link;
        tmp_link = (*tmp_link).next;
        delete del_link;
    }
    head = 0;
    tail = 0;
    size = 0;
}

template <typename K, typename V>
bool map<K,V>::contains_key(K key)
{
    link *tmp_link = head;
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
    link *tmp_link = head;
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
    link *tmp_link = head;
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
    return (head == 0) && (tail == 0);
}

template <typename K, typename V>
bool map<K,V>::put(K key, V value)
{
    if(is_empty())
    {
        try
        {
            link *new_link = new link();
        }
        catch(std::bad_alloc &e)
        {
            return false;
        }
        new_link.key = key;
        new_link.value = value;
        new_link.previous = 0;
        new_link.next = 0;
        head = new_link;
        tail = new_link;
    }
    else
    {
        link *tmp_link = head;
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
            link *new_link = new link();
        }
        catch(std::bad_alloc &e)
        {
            return false;
        }
        new_link.key = key;
        new_link.value = value;
        new_link.previous = tail;
        new_link.next = 0;
        (*tail).next = new_link;
        tail = new_link;
    }
    size++;
    return true;
}

template <typename K, typename V>
bool map<K,V>::remove(K key)
{
    link *tmp_link = head;
    while(tmp_link != 0)
    {
        if((*tmp_link).key == key)
        {
            if(tmp_link == head)
            {
                head = (*tmp_link).next;
            }
            else
            {
                (*(*tmp_link).previous).next = (*tmp_link).next;
            }
            
            if(tmp_link == tail)
            {
                tail = (*tmp_link).previous;
            }
            else
            {
                (*(*tmp_link).next).previous = (*tmp_link).previous;
            }
            
            delete tmp_link;
            size--;
            return true;
        }
        tmp_link = (*tmp_link).next;
    }
    return false;
}

template <typename K, typename V>
int map<K,V>::size()
{
    return size;
}

#endif
