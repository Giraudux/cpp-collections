// Alexis Giraudet
// Théo Cesbron

#ifndef ABSTRACT_DICTIONNAIRE_HPP
#define ABSTRACT_DICTIONNAIRE_HPP

#include <string>

using namespace std;

/**
 * Classe abstraite abstract_dictionnaire:
 * 
**/
template <typename V>
class abstract_dictionnaire
{
    public:
        /**
         * vrai ssi la chaîne mot figure dans le dictionnaire
        **/
        virtual bool contientMot(const string& mot) const = 0;
        /**
         * ajoute la chaîne mot au dictionnaire, avec la valeur v, mot étant supposé absent du dictionnaire
        **/
        virtual void ajouterMot(const string& mot, const V& v) = 0;
        /**
         * associe la valeur v à la chaîne mot dans le dictionnaire, mot pouvant être présent ou absent du dictionnaire
        **/
        virtual void associerMot(const string& mot, const V& v) = 0;
        /**
         * supprime l'éventuelle chaîne mot du dictionnaire
        **/
        virtual void supprimerMot(const string& mot) = 0;
        /**
         * donne la valeur correspondant à la chaîne mot (supposée figurer dans le dictionnaire)
        **/
        virtual V valeurAssociee(const string& mot) const = 0;
};

#endif
