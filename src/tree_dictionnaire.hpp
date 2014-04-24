/*!
 * \file tree_dictionnaire.hpp
 * \brief Classe tree_dictionnaire
 * \author Alexis Giraudet
 * \author Théo Cesbron
 * \version 1.0
 * \date 24 avril 2014
 */

#ifndef TREE_DICTIONNAIRE_HPP
#define TREE_DICTIONNAIRE_HPP

#include "abstract_dictionnaire.hpp"
#include "node.hpp"

using namespace std;

/*!
 * \class tree_dictionnaire
 * \brief Classe tree_dictionnaire implémente la classe abstraite abstract_dictionnaire avec un arbre. V le type des valeurs associées aux mots.
 */
template <typename V>
class tree_dictionnaire: public abstract_dictionnaire<V>
{
    protected:
        node<V> _root;

    public:
        tree_dictionnaire();
        ~tree_dictionnaire();
        /*!
         * \brief Affiche le dictionnaire sur le flux passé en paramètre. O(n)
         * \param os : le flux de sortie
         * \return le flux de sortie
         */
        ostream& afficher(ostream& os=cout) const;

        /*!
         * \brief Teste si le dictionnaire contient un mot. O(n*log(n))
         * \param mot : le mot recherché
         * \return vrai si le dictionnaire contient le mot sinon faux
         */
        bool contientMot(const string& mot) const;

        /*!
         * \brief Ajoute la chaîne mot au dictionnaire, avec la valeur v, mot étant supposé absent du dictionnaire. O(n*log(n))
         * \param mot : le mot à ajouter
         * \param v : la valeur associée au mot
         */
        void ajouterMot(const string& mot, const V& v);

        /*!
         * \brief Associe la valeur v à la chaîne mot dans le dictionnaire, mot pouvant être présent ou absent du dictionnaire. O(n*log(n))
         * \param mot : le mot à modifier
         * \param v : la valeur associée au mot
         */
        void associerMot(const string& mot, const V& v);

        /*!
         * \brief Supprime l'éventuelle chaîne mot du dictionnaire. O(n*log(n))
         * \param mot : le mot à supprimer
         */
        void supprimerMot(const string& mot);

        /*!
         * \brief Donne la valeur correspondant à la chaîne mot (supposée figurer dans le dictionnaire). O(n*log(n))
         * \param mot : le mot dont on veut récupérer la valeur associée
         * \return la valeur associée au mot
         */
        V valeurAssociee(const string& mot) const;

        /*!
         * \deprecated utiliser to_list()
         * \brief Retourne un triplet contenant le tableau des mots du dictionnaire, le tableau des valeurs associées aux mots et la taille de ces tableaux. O(n)
         * \return le triplet mots-valeurs-taille
         */
        triplet<string*,V*,int> to_array() const;

        /*!
         * \brief Charge les mots et les valeurs du dictionnaire dans la liste passée en paramètre. O(n)
         * \param ls : la liste où charger les couples mot-valeur
         */
        void to_list(list<pair<string,V> >& ls) const;
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

template <typename V>
ostream& tree_dictionnaire<V>::afficher(ostream& os) const
{
    os << _root;
    return os;
}
template <typename V>
bool tree_dictionnaire<V>::contientMot(const string& mot) const
{
    return _root.contains(mot.begin(),mot.end());
}

template <typename V>
void tree_dictionnaire<V>::ajouterMot(const string& mot, const V& v)
{
    _root.set(v,mot.begin(),mot.end());
}

template <typename V>
void tree_dictionnaire<V>::associerMot(const string& mot, const V& v)
{
    _root.set(v,mot.begin(),mot.end());
}

template <typename V>
void tree_dictionnaire<V>::supprimerMot(const string& mot)
{
    _root.remove(mot.begin(),mot.end());
}

template <typename V>
V tree_dictionnaire<V>::valeurAssociee(const string& mot) const
{
    return _root.get(mot.begin(),mot.end());
}

template <typename V>
triplet<string*,V*,int> tree_dictionnaire<V>::to_array() const
{
    triplet<string*,V*,int> res;
    pair<string*,V*> pa = _root.to_array();
    res.first = pa.first;
    res.second = pa.second;
    res.third = _root.size();
    return res;
}

template <typename V>
void tree_dictionnaire<V>::to_list(list<pair<string,V> >& ls) const
{
    _root.to_list(ls);
}

#endif

