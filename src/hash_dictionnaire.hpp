/*!
 * \file hash_dictionnaire.hpp
 * \brief Classe hash_dictionnaire
 * \author Alexis Giraudet
 * \author Théo Cesbron
 * \version 1.0
 * \date 24 avril 2014
 */

#ifndef HASH_DICTIONNAIRE_HPP
#define HASH_DICTIONNAIRE_HPP

#include "abstract_dictionnaire.hpp"
#include "hash_table.hpp"

using namespace std;

/*!
 * \class hash_dictionnaire
 * \brief Classe hash_dictionnaire implémente la classe abstraite abstract_dictionnaire avec une table de hachage. V le type des valeurs associées aux mots.
 */
template <typename V, int S=26>
class hash_dictionnaire: public abstract_dictionnaire<V>
{
    protected:
        hash_table<string,V,S> _data;

    public:
        /*!
         * \brief Constructeur. O(1)
         */
        hash_dictionnaire();

        /*!
         * \brief Destructeur. O(n)
         */
        ~hash_dictionnaire();

        /*!
         * \brief Affiche le dictionnaire sur le flux passé en paramètre. O(n)
         * \param os : le flux de sortie
         * \return le flux de sortie
         */
        ostream& afficher(ostream& os=cout) const;

        /*!
         * \brief Teste si le dictionnaire contient un mot. O(n)
         * \param mot : le mot recherché
         * \return vrai si le dictionnaire contient le mot sinon faux
         */
        bool contientMot(const string& mot) const;

        /*!
         * \brief Ajoute la chaîne mot au dictionnaire, avec la valeur v, mot étant supposé absent du dictionnaire. O(n)
         * \param mot : le mot à ajouter
         * \param v : la valeur associée au mot
         */
        void ajouterMot(const string& mot, const V& v);

        /*!
         * \brief Associe la valeur v à la chaîne mot dans le dictionnaire, mot pouvant être présent ou absent du dictionnaire. O(n)
         * \param mot : le mot à modifier
         * \param v : la valeur associée au mot
         */
        void associerMot(const string& mot, const V& v);

        /*!
         * \brief Supprime l'éventuelle chaîne mot du dictionnaire. O(n)
         * \param mot : le mot à supprimer
         */
        void supprimerMot(const string& mot);

        /*!
         * \brief Donne la valeur correspondant à la chaîne mot (supposée figurer dans le dictionnaire). O(n)
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

template <typename V, int S>
ostream& hash_dictionnaire<V,S>::afficher(ostream& os) const
{
    os << _data;
    return os;
}

template <typename V, int S>
bool hash_dictionnaire<V,S>::contientMot(const string& mot) const
{
    return _data.contains_key(mot);
}

template <typename V, int S>
void hash_dictionnaire<V,S>::ajouterMot(const string& mot, const V& v)
{
    _data.put(mot,v);
}

template <typename V, int S>
void hash_dictionnaire<V,S>::associerMot(const string& mot, const V& v)
{
    _data.put(mot,v);
}

template <typename V, int S>
void hash_dictionnaire<V,S>::supprimerMot(const string& mot)
{
    _data.remove(mot);
}

template <typename V, int S>
V hash_dictionnaire<V,S>::valeurAssociee(const string& mot) const
{
    return _data.get(mot);
}

template <typename V, int S>
triplet<string*,V*,int> hash_dictionnaire<V,S>::to_array() const
{
    triplet<string*,V*,int> res;
    res.first = _data.keys_array();
    res.second = _data.values_array();
    res.third = _data.size();
    return res;
}

template <typename V, int S>
void hash_dictionnaire<V,S>::to_list(list<pair<string,V> >& ls) const
{
    _data.to_list(ls);
}

#endif
