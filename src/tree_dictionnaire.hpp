// Alexis Giraudet
// Théo Cesbron

#ifndef TREE_DICTIONNAIRE_HPP
#define TREE_DICTIONNAIRE_HPP

#include "abstract_dictionnaire.hpp"
#include "node.hpp"

using namespace std;

/**
 * Classe tree_dictionnaire:
 * 
**/
template <typename V>
class tree_dictionnaire: public abstract_dictionnaire<V>
{
    private:
        node<V> _root;

    public:
        tree_dictionnaire();
        ~tree_dictionnaire();
        bool contientMot(const string& mot) const;
        void ajouterMot(const string& mot, const V& v);
        void associerMot(const string& mot, const V& v);
        void supprimerMot(const string& mot);
        V valeurAssociee(const string& mot) const;
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
bool tree_dictionnaire<V>::contientMot(const string& mot) const
{
    return _root.contains(mot.begin(),mot.end());
}


/**
 * ajoute la chaîne mot au tree_dictionnaire, avec la valeur v, mot étant supposé absent du tree_dictionnaire
**/
template <typename V>
void tree_dictionnaire<V>::ajouterMot(const string& mot, const V& v)
{
    _root.set(v,mot.begin(),mot.end());
}

/**
 * associe la valeur v à la chaîne mot dans le tree_dictionnaire, mot pouvant être présent ou absent du tree_dictionnaire
**/
template <typename V>
void tree_dictionnaire<V>::associerMot(const string& mot, const V& v)
{
    _root.set(v,mot.begin(),mot.end());
}

/**
 * supprime l'éventuelle chaîne mot du tree_dictionnaire
**/
template <typename V>
void tree_dictionnaire<V>::supprimerMot(const string& mot)
{
    _root.remove(mot.begin(),mot.end());
}

/**
 * donne la valeur correspondant à la chaîne mot (supposée figurer dans le tree_dictionnaire)
**/
template <typename V>
V tree_dictionnaire<V>::valeurAssociee(const string& mot) const
{
    return _root.get(mot.begin(),mot.end());
}

#endif

