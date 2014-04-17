// Alexis Giraudet
// Théo Cesbron

#ifndef HASH_DICTIONNAIRE_HPP
#define HASH_DICTIONNAIRE_HPP

#include "abstract_dictionnaire.hpp"
#include "hash_table.hpp"

using namespace std;

/**
 * Classe hash_hash_dictionnaire:
 * 
**/
template <typename V, int S=26>
class hash_dictionnaire: public abstract_dictionnaire<V>
{
    protected:
        hash_table<string,V,S> _data;

    public:
        hash_dictionnaire();
        ~hash_dictionnaire();
        bool contientMot(const string& mot) const;
        void ajouterMot(const string& mot, const V& v);
        void associerMot(const string& mot, const V& v);
        void supprimerMot(const string& mot);
        V valeurAssociee(const string& mot) const;
        triplet<string*,V*,int> to_array() const;
};

template <typename V, int S>
hash_dictionnaire<V,S>::hash_dictionnaire()
{
    ;
}

template <typename V, int S>
hash_dictionnaire<V,S>::~hash_dictionnaire()
{
    ;
}

/**
 * vrai ssi la chaîne mot figure dans le hash_dictionnaire
**/
template <typename V, int S>
bool hash_dictionnaire<V,S>::contientMot(const string& mot) const
{
    return _data.contains_key(mot);
}


/**
 * ajoute la chaîne mot au hash_dictionnaire, avec la valeur v, mot étant supposé absent du hash_dictionnaire
**/
template <typename V, int S>
void hash_dictionnaire<V,S>::ajouterMot(const string& mot, const V& v)
{
    _data.put(mot,v);
}

/**
 * associe la valeur v à la chaîne mot dans le hash_dictionnaire, mot pouvant être présent ou absent du hash_dictionnaire
**/
template <typename V, int S>
void hash_dictionnaire<V,S>::associerMot(const string& mot, const V& v)
{
    _data.put(mot,v);
}

/**
 * supprime l'éventuelle chaîne mot du hash_dictionnaire
**/
template <typename V, int S>
void hash_dictionnaire<V,S>::supprimerMot(const string& mot)
{
    _data.remove(mot);
}

/**
 * donne la valeur correspondant à la chaîne mot (supposée figurer dans le hash_dictionnaire)
**/
template <typename V, int S>
V hash_dictionnaire<V,S>::valeurAssociee(const string& mot) const
{
    return _data.get(mot);
}

/**
 * retourne un triplet contenant le tableau des mots du dictionnaire, le tableau des valeurs associées aux mots et la taille de ces tableaux
**/
template <typename V, int S>
triplet<string*,V*,int> hash_dictionnaire<V,S>::to_array() const
{
    triplet<string*,V*,int> res;
    res.first = _data.keys_array();
    res.second = _data.values_array();
    res.third = _data.size();
    return res;
}

#endif
