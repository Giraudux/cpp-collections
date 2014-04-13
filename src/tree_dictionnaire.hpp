// Alexis Giraudet
// Théo Cesbron

#ifndef TREE_DICTIONNAIRE_HPP
#define TREE_DICTIONNAIRE_HPP

#include <string>
#include "node.hpp"

using namespace std;

/**
 * Classe tree_dictionnaire:
 * 
**/
template <typename V>
class tree_dictionnaire
{
    private:
        node<char,string> _root;

    public:
        tree_dictionnaire();
        ~tree_dictionnaire();
        bool contientMot(string mot);
        void ajouterMot(string mot, V v);
        void associerMot(string mot, V v);
        void supprimerMot(string mot);
        V valeurAssociee(string mot);
};

template <typename V>
tree_dictionnaire<V>::tree_dictionnaire()
{
    ;
}

template <typename V>
tree_dictionnaire<V>::~tree_dictionnaire()
{
    ;
}

/**
 * vrai ssi la chaîne mot figure dans le tree_dictionnaire
**/
template <typename V>
bool tree_dictionnaire<V>::contientMot(string mot)
{
    return false;
}


/**
 * ajoute la chaîne mot au tree_dictionnaire, avec la valeur v, mot étant supposé absent du tree_dictionnaire
**/
template <typename V>
void tree_dictionnaire<V>::ajouterMot(string mot, V v)
{
    ;
}

/**
 * associe la valeur v à la chaîne mot dans le tree_dictionnaire, mot pouvant être présent ou absent du tree_dictionnaire
**/
template <typename V>
void tree_dictionnaire<V>::associerMot(string mot, V v)
{
    ;
}

/**
 * supprime l'éventuelle chaîne mot du tree_dictionnaire
**/
template <typename V>
void tree_dictionnaire<V>::supprimerMot(string mot)
{
    ;
}

/**
 * donne la valeur correspondant à la chaîne mot (supposée figurer dans le tree_dictionnaire)
**/
template <typename V>
V tree_dictionnaire<V>::valeurAssociee(string mot)
{
    ;
}

#endif

