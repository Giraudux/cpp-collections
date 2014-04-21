/*!
 * \file dictionary.hpp
 * \brief Classe dictionary
 * \author Alexis Giraudet
 * \author Théo Cesbron
 * \version 1.0
 * \date 18 avril 2014
 * Classe dictionary.
 */

#ifndef DICTIONARY_HPP
#define DICTIONARY_HPP

#include <iostream>
#include <exception>

/*!
 * \class dictionary
 * \brief Classe dictionary
 * Implémentation d'un tableau associatif avec double chaînage de couples.
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
    
    protected:
        _link *_head;
        _link *_tail;
        int _size;
    
    public:

        /*!
         * \brief Constructeur
         * Constructeur de la classe dictionary
         */
        dictionary();

        /*!
         * \brief Destructeur
         * Destructeur de la classe dictionary
         */
        ~dictionary();

        /*!
         * \brief Nettoyer
         * Vide le dictionnaire.
         * O(n)
         */
        void clear();

        /*!
         * \brief Contient clef
         * \param key : la clef recherchée
         * \return vrai si le dictionnaire contient la clef key, sinon faux
         * Retourne vrai si le dictionnaire contient la clef key, retourne faux dans le cas contraire.
         * O(n)
         */
        bool contains_key(const K& key) const;

        /*!
         * \brief Contient valeur
         * \param value : la valeur recherchée
         * \return vrai si le dictionnaire contient la valeur value, sinon faux
         * Retourne vrai si le dictionnaire contient la valeur value, retourne faux dans le cas contraire.
         * O(n)
         */
        bool contains_value(const V& value) const;

        /*!
         * \brief Récupérer valeur
         * \param key : la clef
         * \return la valeur associée à la clef key
         * Retourne la valeur associée à la clef key si le dictionnaire contient la clef key, lève une exception dans le cas contraire.
         * O(n)
         */
        V get(const K& key) const;

        /*!
         * \brief Récupérer référence valeur
         * \param key : la clef
         * \return la référence de la valeur associée à la clef key
         * Retourne la référence de la valeur associée à la clef key si le dictionnaire contient la clef key, lève une exception dans le cas contraire.
         * O(n)
         */
        V& get_ref(const K& key) const;

        /*!
         * \brief Est vide
         * \return vrai si le dictionnaire est vide, sinon faux
         * Retourne vrai si le dictionnaire est vide, retourne faux dans le cas contraire.
         * O(1)
         */
        bool is_empty() const;

        /*!
         * \brief Tableau des clefs
         * \return le tableau des clefs
         * Retourne un tableau contenant toutes les clefs du dictionnaire.
         * O(n)
         */
        K* keys_array() const;

        /*!
         * \brief Afficher
         * \return la sortie standard
         * Affiche le dictionnaire sur la sortie standard.
         * O(n)
         */
        std::ostream& print() const;

        /*!
         * \brief Afficher
         * \param os : le flux sur lequel afficher le dictionnaire
         * \return le flux passé en paramètre
         * Affiche le dictionnaire sur la sortie os.
         * O(n)
         */
        std::ostream& print(std::ostream& os) const;

        /*!
         * \brief Ajouter/Remplacer
         * \param key : 
         * \param value : 
         * \return vrai si la clef n'était pas présente, sinon faux (la valeur précédente a été écrasée)
         * Ajoute un nouveau couple clef/valeur au dictionnaire si celui-ci ne contient pas la clef key, si le dictionnaire contient la clef key alors la valeur associée à la clef sera remplacée par value.
         * O(n)
         */
        bool put(const K& key, const V& value);

        /*!
         * \brief Supprimer
         * \param key : la clef à supprimer
         * \return vrai si la clef et la valeur associée ont bien été supprimé, sinon faux
         * Supprime le couple clef/valeur associé à la clef key du dictionnaire.
         * O(n)
         */
        bool remove(const K& key);

        /*!
         * \brief Taille
         * \return la taille (le nombre de couples clef-valeur)
         * Retourne la taille du dictionnaire.
         * O(1)
         */
        int size() const;

        /*!
         * \brief Tableau des valeurs
         * \return le tableau des valeurs
         * Retourne un tableau contenant toutes les valeurs du dictionnaire.
         * O(n)
         */
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

template <typename K, typename V>
V& dictionary<K,V>::get_ref(const K& key) const
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
bool dictionary<K,V>::is_empty() const
{
    return (_head == 0) && (_tail == 0);
}

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

template <typename K, typename V>
std::ostream& dictionary<K,V>::print() const
{
    return print(std::cout);
}

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

template <typename K, typename V>
int dictionary<K,V>::size() const
{
    return _size;
}

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

template <typename K, typename V>
std::ostream& operator<<(std::ostream& os, const dictionary<K,V>& m)
{
    return m.print(os);
}

#endif
