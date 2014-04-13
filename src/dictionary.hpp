// Alexis Giraudet
// Théo Cesbron

#ifndef DICTIONARY_HPP
#define DICTIONARY_HPP

#include <ostream>
#include <iostream>
#include <exception>

/**
 * Classe dictionary: tableau associatif
 * Implémentation avec double chaînage de couples.
**/
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
        bool contains_key(const K& key) const;
        bool contains_value(const V& value) const;
        V get(const K& key) const;
        bool is_empty() const;
        K* keys_array() const;
        std::ostream& print() const;
        std::ostream& print(std::ostream& os) const;
        bool put(const K& key, const V& value);
        bool remove(const K& key);
        int size() const;
        V* values_array() const;
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

/**
 * Vide le dictionnaire.
 * O(n)
**/
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

/**
 * Retourne vrai si le dictionnaire contient la clef key, retourne faux dans le cas contraire.
 * O(n)
**/
template <typename K, typename V>
bool dictionary<K,V>::contains_key(const K& key) const
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

/**
 * Retourne vrai si le dictionnaire contient la valeur value, retourne faux dans le cas contraire.
 * O(n)
**/
template <typename K, typename V>
bool dictionary<K,V>::contains_value(const V& value) const
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

/**
 * Retourne la valeur associée à la clef key si le dictionnaire contient la clef key, lève une exception dans le cas contraire.
 * O(n)
**/
template <typename K, typename V>
V dictionary<K,V>::get(const K& key) const
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

/**
 * Retourne vrai si le dictionnaire est vide, retourne faux dans le cas contraire.
 * O(1)
**/
template <typename K, typename V>
bool dictionary<K,V>::is_empty() const
{
    return (_head == 0) && (_tail == 0);
}

/**
 * Retourne un tableau contenant toutes les clefs du dictionnaire.
 * O(n)
**/
template <typename K, typename V>
K* dictionary<K,V>::keys_array() const
{
    K *res = new K[_size];
    int i=0;
    _link *tmp_link = _head;
    while(tmp_link != 0)
    {
        res[i] = (*tmp_link).key;
        i++;
        tmp_link = (*tmp_link).next;
    }
    return res;
}

/**
 * Affiche le dictionnaire sur la sortie standard.
 * O(n)
**/
template <typename K, typename V>
std::ostream& dictionary<K,V>::print() const
{
    return print(std::cout);
}

/**
 * Affiche le dictionnaire sur la sortie os.
 * O(n)
**/
template <typename K, typename V>
std::ostream& dictionary<K,V>::print(std::ostream& os) const
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

/**
 * Ajoute un nouveau couple clef/valeur au dictionnaire si celui-ci ne contient pas la clef key, si le dictionnaire contient la clef key alors la valeur associée à la clef sera remplacée par value.
 * O(n)
**/
template <typename K, typename V>
bool dictionary<K,V>::put(const K& key, const V& value)
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

/**
 * Supprime le couple clef/valeur associé à la clef key du dictionnaire.
 * O(n)
**/
template <typename K, typename V>
bool dictionary<K,V>::remove(const K& key)
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

/**
 * Retourne la taille du dictionnaire.
 * O(1)
**/
template <typename K, typename V>
int dictionary<K,V>::size() const
{
    return _size;
}

/**
 * Retourne un tableau contenant toutes les valeurs du dictionnaire.
 * O(n)
**/
template <typename K, typename V>
V* dictionary<K,V>::values_array() const
{
    V *res = new V[_size];
    int i=0;
    _link *tmp_link = _head;
    while(tmp_link != 0)
    {
        res[i] = (*tmp_link).value;
        i++;
        tmp_link = (*tmp_link).next;
    }
    return res;
}

/**
 * Définition de l'opérateur << pour gérer les flux.
**/
template <typename K, typename V>
std::ostream& operator<<(std::ostream& os, const dictionary<K,V>& m)
{
    return m.print(os);
}

#endif
