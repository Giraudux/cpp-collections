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
    link_multi_set tmp_lms;
    _link *tmp_link = _head;
    while(tmp_link != 0)
    {
        if(tmp_lms.count((*tmp_link).type) < 1)
        {
            tmp_lms.add((*tmp_link).type);
            int j = lms.count((*tmp_link).type);
            if(j>0)
            {
                int k = count((*tmp_link).type);
                if(j<k)
                {
                    for(int l=0; l<k-j; l++)
                    {
                        remove((*tmp_link).type);
                    }
                }
            }
            else
            {
                remove_all((*tmp_link).type);
            }
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
    if(!is_empty())
    {
        if((*_head).type == type)
        {
            _link *rm_link = _head;
            _head = (*_head).next;
            delete rm_link;
            _size--;
        }
        else
        {
            _link *pre_link = _head;
            _link *tmp_link = (_head).next;
            while(tmp_link != 0)
            {
                if((*tmp_link).type == type)
                {
                    (*pre_link).next = (*tmp_link).next;
                    delete tmp_link;
                    _size--;
                    break;
                }
                pre_link = tmp_link;
                tmp_link = (*tmp_link).next;
            }
        }
    }
}

template <typename T>
void link_multi_set<T>::remove_all(T type)
{
    if(!is_empty())
    {
        while((*_head).type == type)
        {
            _link *rm_link = _head;
            _head = (*_head).next;
            delete rm_link;
            _size--;
        }
        if(!is_empty())
        {
            _link *pre_link = _head;
            _link *tmp_link = (_head).next;
            while(tmp_link != 0)
            {
                if((*tmp_link).type == type)
                {
                    (*pre_link).next = (*tmp_link).next;
                    delete tmp_link;
                    _size--;
                    tmp_link = (*pre_link).next;
                }
                else
                {
                    pre_link = tmp_link;
                    tmp_link = (*tmp_link).next;
                }
            }
        }
    }
}

template <typename T>
int link_multi_set<T>::size()
{
    return _size;
}

template <typename T>
void link_multi_set<T>::sub(const link_multi_set &lms)
{
    link_multi_set tmp_lms;
    _link *tmp_link = _head;
    while(tmp_link != 0)
    {
        if(tmp_lms.count((*tmp_link).type) < 1)
        {
            tmp_lms.add((*tmp_link).type);
            int j = lms.count((*tmp_link).type);
            if(j>0)
            {
                int k = count((*tmp_link).type);
                if(k-j < 1)
                {
                    remove_all((*tmp_link).type);
                }
                else
                {
                    for(int l=0; l<k-j; l++)
                    {
                        remove((*tmp_link).type);
                    }
                }
            }
        }
        tmp_link = (*tmp_link).next;
    }
}

#endif
