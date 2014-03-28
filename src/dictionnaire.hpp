// Alexis Giraudet
// Théo Cesbron

#ifndef DICTIONNAIRE_HPP
#define DICTIONNAIRE_HPP

#include "hash_table.hpp"
#include <exception>
#include <string>

using namespace std;

/**
 * Classe dictionnaire:
 * 
**/
template <typename V, int S=26>
class dictionnaire
{
    private:
        hash_table<string,V,S> _data;

    public:
        dictionnaire();
        ~dictionnaire();
        bool contientMot(string mot);
        void ajouterMot(string mot, V v);
        void associerMot(string mot, V v);
        void supprimerMot(string mot);
        V valeurAssociee(string mot);
};

template <typename V, int S>
dictionnaire<V,S>::dictionnaire()
{
    ;
}

template <typename V, int S>
dictionnaire<V,S>::~dictionnaire()
{
    ;
}

/**
 * vrai ssi la chaîne mot figure dans le dictionnaire
**/
template <typename V, int S>
bool dictionnaire<V,S>::contientMot(string mot)
{
    return _data.contains_key(mot);
}


/**
 * ajoute la chaîne mot au dictionnaire, avec la valeur v, mot étant supposé absent du dictionnaire
**/
template <typename V, int S>
void dictionnaire<V,S>::ajouterMot(string mot, V v)
{
    _data.put(mot,v);
}

/**
 * associe la valeur v à la chaîne mot dans le dictionnaire, mot pouvant être présent ou absent du dictionnaire
**/
template <typename V, int S>
void dictionnaire<V,S>::associerMot(string mot, V v)
{
    _data.put(mot,v);
}

/**
 * supprime l'éventuelle chaîne mot du dictionnaire
**/
template <typename V, int S>
void dictionnaire<V,S>::supprimerMot(string mot)
{
    _data.remove(mot);
}

/**
 * donne la valeur correspondant à la chaîne mot (supposée figurer dans le dictionnaire)
**/
template <typename V, int S>
V dictionnaire<V,S>::valeurAssociee(string mot)
{
    return _data.get(mot);
}

#endif
