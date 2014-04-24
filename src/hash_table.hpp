/*!
 * \file hash_table.hpp
 * \brief Classe hash_table
 * \author Alexis Giraudet
 * \author Théo Cesbron
 * \version 1.0
 * \date 18 avril 2014
 */

#ifndef HASH_TABLE_HPP
#define HASH_TABLE_HPP

#include <functional>
#include "map.hpp"

/*!
 * \class map
 * \brief Implémentation générique d'une table de hachage avec taleaux associatifs. K le type des clefs, V le type des valeurs et S le nombre de maps.
 */
template <typename K, typename V, int S>
class hash_table
{
    private:
        map<K,V>* _data;
        std::hash<K> _hash_fn;        
    
    public:
        /*!
         * \brief Constructeur. O(1)
         */
        hash_table();

        /*!
         * \brief Destructeur. O(n)
         */
        ~hash_table();

        /*!
         * \brief Vide la hash_table. O(n)
         */
        void clear();

        /*!
         * \brief Retourne vrai si la hash_table contient la clef key, retourne faux dans le cas contraire. O(n)
         * \param key : la clef recherchée
         * \return vrai si la hash_table contient la clef key, sinon faux
         */
        bool contains_key(const K& key) const;

        /*!
         * \brief Retourne vrai si la hash_table contient la valeur value, retourne faux dans le cas contraire. O(n)
         * \param value : la valeur recherchée
         * \return vrai si la hash_table contient la valeur value, sinon faux
         */
        bool contains_value(const V& value) const;

        /*!
         * \brief Retourne la valeur associée à la clef key si la hash_table contient la clef key, lève une exception dans le cas contraire. O(n)
         * \param key : la clef
         * \return la valeur associée à la clef key
         */
        V get(const K& key) const;

        /*!
         * \brief Retourne la référence de la valeur associée à la clef key si la hash_table contient la clef key, lève une exception dans le cas contraire. O(n)
         * \param key : la clef
         * \return la référence de la valeur associée à la clef key
         */
        V& get_ref(const K& key) const;

        /*!
         * \brief Retourne vrai si la hash_table est vide, retourne faux dans le cas contraire. O(1)
         * \return vrai si la hash_table est vide, sinon faux
         */
        bool is_empty() const;

        /*!
         * \deprecated utiliser to_list()
         * \brief Retourne un tableau contenant toutes les clefs de la hash_table. O(n)
         * \return le tableau des clefs
         */
        K* keys_array() const;

        /*!
         * \brief Ajoute un nouveau couple clef-valeur à la hash_table si celle-ci ne contient pas la clef key, si la hash_table contient la clef key alors la valeur associée à la clef sera remplacée par value. O(n)
         * \param key : la clef
         * \param value : la valeur associée à la clef
         * \return vrai si la clef n'était pas présente, sinon faux (la valeur précédente a été écrasée)
         */
        bool put(const K& key, const V& value);

        /*!
         * \brief Supprime le couple clef-valeur associé à la clef key de la hash_table. O(n)
         * \param key : la clef à supprimer
         * \return vrai si la clef et la valeur associée ont bien été supprimé, sinon faux
         */
        bool remove(const K& key);

        /*!
         * \brief Retourne la taille de la hash_table. O(1)
         * \return la taille (le nombre de couples clef-valeur)
         */
        int size() const;

        /*!
         * \brief Charge les élément de la hash_table dans la liste passée en paramètre. O(n)
         * \param ls : la liste où charger les couples clef-valeur
         */
        void to_list(std::list<std::pair<K,V> >& ls) const;

        /*!
         * \deprecated Utiliser to_list()
         * \brief Retourne un tableau contenant toutes les valeurs de la hash_table. O(n)
         * \return le tableau des valeurs
         */
        V* values_array() const;
};

template <typename K, typename V, int S>
hash_table<K,V,S>::hash_table(): _data(0)
{
    _data = new map<K,V>[S];
}

template <typename K, typename V, int S>
hash_table<K,V,S>::~hash_table()
{
    delete[] _data;
}

template <typename K, typename V, int S>
void hash_table<K,V,S>::clear()
{
    for(int i=0; i<S; i++)
    {
        _data[i].clear();
    }
}

template <typename K, typename V, int S>
bool hash_table<K,V,S>::contains_key(const K& key) const
{
    return _data[_hash_fn(key)%S].contains_key(key);
}

template <typename K, typename V, int S>
bool hash_table<K,V,S>::contains_value(const V& value) const
{
    for(int i=0; i<S; i++)
    {
        if(_data[i].contains_value(value))
        {
            return true;
        }
    }
    return false;
}

template <typename K, typename V, int S>
V hash_table<K,V,S>::get(const K& key) const
{
    return _data[_hash_fn(key)%S].get(key);
}

template <typename K, typename V, int S>
V& hash_table<K,V,S>::get_ref(const K& key) const
{
    return _data[_hash_fn(key)%S].get(key);
}

template <typename K, typename V, int S>
bool hash_table<K,V,S>::is_empty() const
{
    for(int i=0; i<S; i++)
    {
        if(!_data[i].is_empty())
        {
            return false;
        }
    }
    return true;
}

template <typename K, typename V, int S>
K* hash_table<K,V,S>::keys_array() const
{
    K *res = new K[size()];
    int i=0;
    for(int j=0; j<S; j++)
    {
        K *tmp = _data[j].keys_array();
        for(int k=0; k<_data[j].size(); k++)
        {
            res[i] = tmp[k];
            i++;
        }
        delete[] tmp;
    }
    return res;
}

template <typename K, typename V, int S>
bool hash_table<K,V,S>::put(const K& key, const V& value)
{
    return _data[_hash_fn(key)%S].put(key,value);
}

template <typename K, typename V, int S>
bool hash_table<K,V,S>::remove(const K& key)
{
    return _data[_hash_fn(key)%S].remove(key);
}

template <typename K, typename V, int S>
int hash_table<K,V,S>::size() const
{
    int res=0;
    for(int i=0; i<S; i++)
    {
        res += _data[i].size();
    }
    return res;
}

template <typename K, typename V, int S>
void hash_table<K,V,S>::to_list(std::list<std::pair<K,V> >& ls) const
{
    for(int i=0; i<S; i++)
    {
        _data[i].to_list(ls);
    }
}

template <typename K, typename V, int S>
V* hash_table<K,V,S>::values_array() const
{
    V *res = new V[size()];
    int i=0;
    for(int j=0; j<S; j++)
    {
        V *tmp = _data[j].values_array();
        for(int k=0; k<_data[j].size(); k++)
        {
            res[i] = tmp[k];
            i++;
        }
        delete[] tmp;
    }
    return res;
}

/*!
 * \brief Surchage de l'opérateur de flux pour afficher la map. O(n)
 * \param os : le flux de sortie
 * \param m : la map à afficher
 * \return le flux de sortie
 */
template <typename K, typename V, int S>
std::ostream& operator<<(std::ostream& os, const hash_table<K,V,S>& ht)
{
    std::list<std::pair<K,V> > ls;
    ht.to_list(ls);
    for(typename std::list<std::pair<K,V> >::iterator it=ls.begin(); it != ls.end(); it++)
    {
        os << (*it).first << " : " << (*it).second << std::endl;
    }
    return os;
}

#endif
