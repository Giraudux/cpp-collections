// Alexis Giraudet
// Théo Cesbron

#ifndef HASH_TABLE_HPP
#define HASH_TABLE_HPP

#include <functional>
#include <exception>
#include "dictionary.hpp"

/**
 * Classe hash_table: table de hachage
 * Implémentation avec tableau de dictionnaires.
**/
template <typename K, typename V, int S>
class hash_table
{
    private:
        dictionary<K,V> *_dictionaries;
        std::hash<K> _hash_fn;
        
    
    public:
        hash_table();
        ~hash_table();
        void clear();
        bool contains_key(K key);
        bool contains_value(V value);
        V get(K key);
        bool is_empty();
        K* keys_array();
        std::ostream& print();
        std::ostream& print(std::ostream &os);
        bool put(K key, V value);
        bool remove(K key);
        int size();
        V* values_array();
};

template <typename K, typename V, int S>
hash_table<K,V,S>::hash_table(): _dictionaries(0)
{
    _dictionaries = new dictionary<K,V>[S];
}

template <typename K, typename V, int S>
hash_table<K,V,S>::~hash_table()
{
    delete[] _dictionaries;
}

/**
 * Vide la table de hachage.
 * O(n)
**/
template <typename K, typename V, int S>
void hash_table<K,V,S>::clear()
{
    for(int i=0; i<S; i++)
    {
        _dictionaries[i].clear();
    }
}

/**
 * Retourne vrai si la table de hachage contient la clef key, retourne faux dans le cas contraire.
 * O(n)
**/
template <typename K, typename V, int S>
bool hash_table<K,V,S>::contains_key(K key)
{
    size_t i = _hash_fn(key)%S;
    return _dictionaries[i].contains_key(key);
}

/**
 * Retourne vrai si la table de hachage contient la valeur value, retourne faux dans le cas contraire.
 * O(n)
**/
template <typename K, typename V, int S>
bool hash_table<K,V,S>::contains_value(V value)
{
    for(int i=0; i<S; i++)
    {
        if(_dictionaries[i].contains_value(value))
        {
            return true;
        }
    }
    return false;
}

/**
 * Retourne la valeur associée à la clef key si la table de hachage contient la clef key, lève une exception dans le cas contraire.
 * O(n)
**/
template <typename K, typename V, int S>
V hash_table<K,V,S>::get(K key)
{
    size_t i = _hash_fn(key)%S;
    return _dictionaries[i].get(key);
}

/**
 * Retourne vrai si la table de hachage est vide, retourne faux dans le cas contraire.
 * O(1)
**/
template <typename K, typename V, int S>
bool hash_table<K,V,S>::is_empty()
{
    for(int i=0; i<S; i++)
    {
        if(!_dictionaries[i].is_empty())
        {
            return false;
        }
    }
    return true;
}

/**
 * Retourne un tableau contenant toutes les clefs de la table de hachage.
 * O(n)
**/
template <typename K, typename V, int S>
K* hash_table<K,V,S>::keys_array()
{
    K *res = new K[size()];
    int i=0;
    for(int j=0; j<S; j++)
    {
        K *tmp = _dictionaries[j].keys_array();
        for(int k=0; k<_dictionaries[j].size(); k++)
        {
            res[i] = tmp[k];
            i++;
        }
        delete[] tmp;
    }
    return res;
}

/**
 * Ajoute un nouveau couple clef/valeur a la table de hachage si celle-ci ne contient pas la clef key, si la table de hachage contient la clef key alors la valeur associée à la clef sera remplacée par value.
 * O(n)
**/
template <typename K, typename V, int S>
bool hash_table<K,V,S>::put(K key, V value)
{
    size_t i = _hash_fn(key)%S;
    return _dictionaries[i].put(key,value);
}

/**
 * Supprime le couple clef/valeur associé à la clef key de la table de hachage.
 * O(n)
**/
template <typename K, typename V, int S>
bool hash_table<K,V,S>::remove(K key)
{
    size_t i = _hash_fn(key)%S;
    return _dictionaries[i].remove(key);
}

/**
 * Retourne la taille de la table de hachage.
 * 
**/
template <typename K, typename V, int S>
int hash_table<K,V,S>::size()
{
    int res=0;
    for(int i=0; i<S; i++)
    {
        res += _dictionaries[i].size();
    }
    return res;
}

/**
 * Retourne un tableau contenant toutes les valeurs de la table de hachage.
 * O(n)
**/
template <typename K, typename V, int S>
V* hash_table<K,V,S>::values_array()
{
    V *res = new V[size()];
    int i=0;
    for(int j=0; j<S; j++)
    {
        V *tmp = _dictionaries[j].values_array();
        for(int k=0; k<_dictionaries[j].size(); k++)
        {
            res[i] = tmp[k];
            i++;
        }
        delete[] tmp;
    }
    return res;
}

#endif
