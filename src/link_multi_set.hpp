// Alexis Giraudet
// Théo Cesbron

#ifndef LINK_MULTI_SET_HPP
#define LINK_MULTI_SET_HPP

template <typename T>
class link_multi_set
{
    struct _link
    {
        T type;
        _link *next;
    };

    private:
        _link *_head;
        int _size;

    public:
        link_multi_set();
        ~link_multi_set();
        void add(T type);
        void clear();
        int count(T type);
        bool equal(const link_multi_set &lms);   
        void fusion(const link_multi_set &lms);
        void intersection(const link_multi_set &lms);
        bool is_empty();
        void remove(T type);
        void remove_all(T type);
        int size();
        void sub(const link_multi_set &lms);
};

template <typename T>
link_multi_set<T>::link_multi_set(): _head(0), _size(0)
{
    ;
}

template <typename T>
link_multi_set<T>::~link_multi_set()
{
    clear();
}

template <typename T>
void link_multi_set<T>::add(T type)
{
    _link *new_link = new _link;
    (*new_link).type = type;
    (*new_link).next = _head;
    _head = new_link;
}

template <typename T>
void link_multi_set<T>::clear()
{
    _link *tmp_link = _head;
    while(tmp_link != 0)
    {
        _link *del_link = tmp_link;
        tmp_link = (*tmp_link).next;
        delete del_link;
    }
    _head = 0;
    _size = 0;
}

template <typename T>
int link_multi_set<T>::count(T type)
{
    int res=0;
    _link *tmp_link = _head;
    while(tmp_link != 0)
    {
        if((*tmp_link).type == type)
        {
            res++;
        }
        tmp_link = (*tmp_link).next;
    }
    return res;
}

template <typename T>
bool link_multi_set<T>::equal(const link_multi_set &lms)//todo: optimiser
{
    if(size() != lms.size())
    {
        return false;
    }
    _link *tmp_link = _head;
    while(tmp_link != 0)
    {
        if(count((*tmp_link).type) != lms.count(*tmp_link).type)
        {
            return false;
        }
        tmp_link = (*tmp_link).next;
    }
    return true;
}

template <typename T>
void link_multi_set<T>::fusion(const link_multi_set &lms)
{
    _link *tmp_link = lms._head;
    while(tmp_link != 0)
    {
        add((*tmp_link).type);
        tmp_link = (*tmp_link).next;
    }
}

template <typename T>
void link_multi_set<T>::intersection(const link_multi_set &lms)
{
    _link *tmp_link = _head;
    while(tmp_link != 0)
    {
        int tmp_count = lms.count((*tmp_link).type);
        if(tmp_count == 0)
        {
            remove_all((*tmp_link).type);
        }
        else
        {
            ;//ajout tmp_count type ?
        }
        tmp_link = (*tmp_link).next;
    }
}

template <typename T>
bool link_multi_set<T>::is_empty()
{
    return _head == 0;
}

template <typename T>
void link_multi_set<T>::remove(T type)
{
    ;
}

template <typename T>
void link_multi_set<T>::remove_all(T type)
{
    ;
}

template <typename T>
int link_multi_set<T>::size()
{
    return _size;
}

template <typename T>
void link_multi_set<T>::sub(const link_multi_set &lms)
{
    ;
}

#endif
