/*!
 * \file abstract_dictionnaire.hpp
 * \brief Classe abstraite dictionnaire
 * \author Alexis Giraudet
 * \author Théo Cesbron
 * \version 1.0
 * \date 18 avril 2014
 */

#ifndef ABSTRACT_DICTIONNAIRE_HPP
#define ABSTRACT_DICTIONNAIRE_HPP

#include <iostream>
#include <string>

using namespace std;

/*!
 * \struct triplet
 * \brief Structure générique permettant de stocker trois objets.
 */
template <typename X, typename Y, typename Z>
struct triplet
{
    X first;
    Y second;
    Z third;
};

/*!
 * \class abstract_dictionnaire
 * \brief Classe abstraite abstract_dictionnaire.
 */
template <typename V>
class abstract_dictionnaire
{
    public:
        /*!
         * \brief Destructeur virtuel.
         */
        virtual ~abstract_dictionnaire() {};

        /*!
         * \brief Teste si le dictionnaire contient un mot
         * \param mot : Le mot recherché
         * \return Vrai si le dictionnaire contient le mot sinon faux.
         */
        virtual bool contientMot(const string& mot) const = 0;

        /*!
         * \brief Ajoute la chaîne mot au dictionnaire, avec la valeur v, mot étant supposé absent du dictionnaire.
         */
        virtual void ajouterMot(const string& mot, const V& v) = 0;

        /*!
         * \brief Associe la valeur v à la chaîne mot dans le dictionnaire, mot pouvant être présent ou absent du dictionnaire.
         */
        virtual void associerMot(const string& mot, const V& v) = 0;

        /*!
         * \brief Supprime l'éventuelle chaîne mot du dictionnaire.
         */
        virtual void supprimerMot(const string& mot) = 0;

        /*!
         * \brief Donne la valeur correspondant à la chaîne mot (supposée figurer dans le dictionnaire).
         */
        virtual V valeurAssociee(const string& mot) const = 0;

        /*!
         * \brief Retourne un triplet contenant le tableau des mots du dictionnaire, le tableau des valeurs associées aux mots et la taille de ces tableaux.
         */
        virtual triplet<string*,V*,int> to_array() const = 0;
};

template <typename V>
std::ostream& operator<<(std::ostream& os, const abstract_dictionnaire<V>& ad)
{
    triplet<string*,V*,int> tr = ad.to_array();
    for(int i=0; i<tr.third; i++)
    {
        os << tr.first[i] << " : " << tr.second[i] << endl;
    }
    delete[] tr.first;
    delete[] tr.second;
    return os;
}

#endif
