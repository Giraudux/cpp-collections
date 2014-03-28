// Alexis Giraudet
// Théo Cesbron

#ifndef LIST_HPP
#define LIST_HPP

#include <iterator>
#include <exception>

/**
 * Classe list: liste chaînée
 * Implémentation avec double chaînage.
**/
template <typename T>
class list
{
    struct _link
    {
        T t_type;
        _link *previous;
        _link *next;
    };
    
    private:
        _link *_head;
        _link *_tail;
        int _size;
    
    public:
        list();
        ~list();
        void add(T t_type);
        void add_first(T t_type);
        void add_last(T t_type);
        void clear();
        bool contains(T t_type);
        T get(int index);
        int index_of(T t_type);
        bool is_empty();
        T* to_array();
        bool remove(T t_type);
        int size();
};

/**
 * 
**/
template <typename T>
list<T>::list(): _head(0), _tail(0), _size(0)
{
    ;
}

/**
 * 
**/
template <typename T>
list<T>::~list()
{
    clear();
}

/**
 * 
**/
template <typename T>
void list<T>::add(T t_type)
{
    add_last(t_type);
}

/**
 * 
**/
template <typename T>
void list<T>::add_first(T t_type)
{
    _link *new_link = new _link;
    (*new_link).t_type = t_type;
    (*new_link).previous = 0;
    (*new_link).next = _head;
    _head = new_link;
    if(is_empty())
    {
        _tail = new_link;
    }
}

/**
 * 
**/
template <typename T>
void list<T>::add_last(T t_type)
{
    _link *new_link = new _link;
    (*new_link).t_type = t_type;
    (*new_link).previous = _tail;
    (*new_link).next = 0;
    if(is_empty())
    {
        _head = new_link;
    }
    _tail = new_link;
}

/**
 * 
**/
template <typename T>
void list<T>::clear()
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

/**
 * 
**/
template <typename T>
bool list<T>::contains(T t_type)
{
    _link *tmp_link = _head;
    while(tmp_link != 0)
    {
        if((*tmp_link).t_type == t_type)
        {
            return true;
        }
        tmp_link = (*tmp_link).next;
    }
    return false;
}

/**
 * 
**/
template <typename T>
T list<T>::get(int index)
{
    if((index >= 0) && (index < _size))
    {
        int i=0;
        //todo
        return i;
    }
    throw std::exception();
}

/**
 * 
**/
template <typename T>
int list<T>::index_of(T t_type)
{
    int i=0;
    _link *tmp_link = _head;
    while(tmp_link != 0)
    {
        if((*tmp_link).t_type == t_type)
        {
            return i;
        }
        tmp_link = (*tmp_link).next;
        i++;
    }
    return -1;
}

/**
 * 
**/
template <typename T>
bool list<T>::is_empty()
{
    return (_head == 0) && (_tail == 0);
}

/**
 * 
**/
template <typename T>
T* list<T>::to_array()
{
    T *res = new T[_size];
    int i=0;
    _link *tmp_link = _head;
    while(tmp_link != 0)
    {
        res[i] = (*tmp_link).t_type;
        i++;
        tmp_link = (*tmp_link).next;
    }
    return res;
}

/**
 * 
**/
template <typename T>
bool list<T>::remove(T t_type)
{
    _link *tmp_link = _head;
    while(tmp_link != 0)
    {
        if((*tmp_link).t_type == t_type)
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

/**
 * 
**/
template <typename T>
int list<T>::size()
{
    return _size;
}

template <typename T>
class list_iterator: std::iterator<std::input_iterator_tag, T>
{
    //todo
};

#endif

