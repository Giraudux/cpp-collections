// Alexis Giraudet
// Théo Cesbron

#ifndef LINK_MULTI_SET_HPP
#define LINK_MULTI_SET_HPP

/**
 * Classe link_multi_set: multi-ensemble
 * Implémentation avec chaînage simple.
**/
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
        bool equal(link_multi_set &lms);   
        void fusion(link_multi_set &lms);
        void intersection(link_multi_set &lms);
        bool is_empty();
        void remove(T type);
        void remove_all(T type);
        int size();
        void sub(link_multi_set &lms);
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

/**
 * Ajoute une occurrence de l'élément type au multi-ensemble.
 * O(1)
**/
template <typename T>
void link_multi_set<T>::add(T type)
{
    _link *new_link = new _link;
    (*new_link).type = type;
    (*new_link).next = _head;
    _head = new_link;
}

/**
 * Vide le multi-ensemble.
 * O(n)
**/
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

/**
 * Retourne le nombre d’occurrences de l'élément type dans le multi-ensemble.
 * O(n)
**/
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

/**
 * Retourne vrai si le multi-ensemble est égal au multi-ensemble lms, retourne faux dans le cas contraire.
 * O(n^2)
**/
template <typename T>
bool link_multi_set<T>::equal(link_multi_set &lms)
{
    if(size() != lms.size())
    {
        return false;
    }
    _link *tmp_link = _head;
    while(tmp_link != 0)
    {
        if(count((*tmp_link).type) != lms.count((*tmp_link).type))
        {
            return false;
        }
        tmp_link = (*tmp_link).next;
    }
    return true;
}

/**
 * Fusionne les éléments du multi-ensemble avec les éléments du multi-ensemble lms.
 * O(n)
**/
template <typename T>
void link_multi_set<T>::fusion(link_multi_set &lms)
{
    _link *tmp_link = lms._head;
    while(tmp_link != 0)
    {
        add((*tmp_link).type);
        tmp_link = (*tmp_link).next;
    }
}

/**
 * Intersecte les éléments du multi-ensemble avec les éléments du multi-ensemble lms.
 * O(n^2)
**/
template <typename T>
void link_multi_set<T>::intersection(link_multi_set &lms)
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

/**
 * Retourne vrai si le multi-ensemble est vide, retourne faux dans le cas contraire.
 * O(1)
**/
template <typename T>
bool link_multi_set<T>::is_empty()
{
    return _head == 0;
}

/**
 * Supprime une occurrence de l'élément type du multi-ensemble.
 * O(n)
**/
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
            _link *tmp_link = (*_head).next;
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

/**
 * Supprime toutes les occurrences de l'élément type du multi-ensemble.
 * O(n)
**/
template <typename T>
void link_multi_set<T>::remove_all(T type)
{
    if(!is_empty())
    {
        while(!is_empty() && ((*_head).type == type))
        {
            _link *rm_link = _head;
            _head = (*_head).next;
            delete rm_link;
            _size--;
        }
        if(!is_empty())
        {
            _link *pre_link = _head;
            _link *tmp_link = (*_head).next;
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

/**
 * Retourne la taille du multi-ensemble.
 * O(1)
**/
template <typename T>
int link_multi_set<T>::size()
{
    return _size;
}

/**
 * Soustrait les éléments du multi-ensemble avec les éléments du multi-ensemble lms.
 * O(n^2)
**/
template <typename T>
void link_multi_set<T>::sub(link_multi_set &lms)
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
