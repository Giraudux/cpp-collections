// Alexis Giraudet
// Théo Cesbron

#ifndef MULTI_SET_HPP
#define MULTI_SET_HPP

/**
 * Classe abstraite multi_set: multi-ensemble
**/
template <typename T>
class multi_set
{
    public:
        
        /**
         * Ajoute une occurrence de l'élément type au multi-ensemble.
        **/
        virtual void add(T type) = 0;
        
        /**
         * Vide le multi-ensemble.
        **/
        virtual void clear() = 0;
        
        /**
         * Retourne le nombre d’occurrences de l'élément type dans le multi-ensemble.
        **/
        virtual int count(T type) = 0;
        
        /**
         * Retourne vrai si le multi-ensemble est égal au multi-ensemble ms, retourne faux dans le cas contraire.
        **/
        virtual bool equal(const multi_set &ms) = 0;
        
        /**
         * Fusionne les éléments du multi-ensemble avec les éléments du multi-ensemble ms.
        **/
        virtual void fusion(const multi_set &ms) = 0;
        
        /**
         * Intersecte les éléments du multi-ensemble avec les éléments du multi-ensemble ms.
        **/
        virtual void intersection(const multi_set &ms) = 0;
        
        /**
         * Retourne vrai si le multi-ensemble est vide, retourne faux dans le cas contraire.
        **/
        virtual bool is_empty() = 0;
        
        /**
         * Supprime une occurrence de l'élément type du multi-ensemble.
        **/
        virtual void remove(T type) = 0;
        
        /**
         * Supprime toutes les occurrences de l'élément type du multi-ensemble.
        **/
        virtual void remove_all(T type) = 0;
        
        /**
         * Retourne la taille du multi-ensemble.
        **/
        virtual int size() = 0;
        
        /**
         * Soustrait les éléments du multi-ensemble avec les éléments du multi-ensemble ms.
        **/
        virtual void sub(const multi_set &ms) = 0;
};

#endif
