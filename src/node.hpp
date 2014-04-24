/*!
 * \file node.hpp
 * \brief Classe node
 * \author Alexis Giraudet
 * \author Théo Cesbron
 * \version 1.0
 * \date 24 avril 2014
 */

#ifndef NODE_HPP
#define NODE_HPP

#include "map.hpp"

using namespace std;

/*!
 * \class node
 * \brief Implémentation d'un arbre-noeud (un arbre est un noeud qui n'a pas de père, la racine). V le type des valeurs.
 */
template <typename V>
class node
{
    protected:
        map<char,node<V>> _children;
        V* _value;

    public:
        /*!
         * \brief Constructeur. O(1)
         */
        node();

        /*!
         * \brief Destructeur. O(n)
         */
        ~node();

        /*!
         * \brief Vide le noeud (supprime tous ses fils et sa valeur). O(n)
         */
        void clear();

        /*!
         * \brief Teste si le noeud contient un mot à partir de ses itérateurs. O(log(n))
         * \param it : l'itérateur courant
         * \param end : l'itérateur de fin
         * \return vrai si la valeur de l'un des fils du noeud n'est pas nulle lorsque l'itérateur courant est égal à l'itérateur de fin, sinon faux
         */
        bool contains(string::const_iterator it, string::const_iterator end) const;

        /*!
         * \brief Retourne la valeur associée à un mot à partir de ses itérateurs. O(log(n))
         * \param it : l'itérateur courant
         * \param end : l'itérateur de fin
         * \return la valeur associée au mot si l'arbre contient une valeur non nulle pour ce mot, sinon lève une exception
         */
        V get(string::const_iterator it, string::const_iterator end) const;

        /*!
         * \brief Teste si la valeur du noeud est nulle. O(1)
         * \return vrai si la valeur du noeud est nulle, sinon faux
         */
        bool is_empty() const;

        /*!
         * \brief Teste si le noeud est une feuille. O(1)
         * \return vrai si le noeud n'a pas de fils, sinon faux
         */
        bool is_leaf() const;

        /*!
         * \brief Supprime un mot à partir de ses itérateurs (supprime les noeuds lorsque la branche menant au mot supprimé ne contient plus de valeurs non nulles). O(log(n))
         * \param it : l'itérateur courant
         * \param end : l'itérateur de fin
         * \return vrai si le mot a bien été supprimé, sinon faux
         */
        bool remove(string::const_iterator it, string::const_iterator end);

        /*!
         * \brief Associe une valeur à un mot à partir de ses itérateurs (crée une branche ou remplace la valeur d'un noeud). O(log(n))
         * \param value : la valeur associée au mot
         * \param it : l'itérateur courant
         * \param end : l'itérateur de fin
         * \return vrai si le mot n'était pas présent, sinon faux (la valeur précédente a été écrasée)
         */
        bool set(const V& value, string::const_iterator it, string::const_iterator end);

        /*!
         * \brief Retourne la taille de l'arbre (le nombre de noeuds non vides, dont la valeur n'est pas nulle). O(n)
         * \return la taille de l'arbre
         */
        int size() const;

        /*!
         * \brief Retourne un couple contenant les tableaux des mots et des valeurs de l'arbre.
         * \return le couple contenant les tableaux des mots et des valeurs de l'arbre
         */
        pair<string*,V*> to_array() const;

        /*!
         * \brief Charge les couples mot-valeur de l'arbre dans la liste passée en paramètre. O(n)
         * \param ls : la liste où charger les couples clef-valeur
         * \param acc : l'accumulateur contenant le mot correspondant au chemin parcouru
         */
        void to_list(list< pair<string,V> >& ls, string acc=string()) const;

    protected:
        /*!
         * \brief Retourne la valeur du noeud si celle-ci n'est pas nulle, sinon lève une exception. O(1)
         * \return la valeur du noeud si celle-ci n'est pas nulle, sinon lève une exception
         */
        V get_value() const;

        /*!
         * \brief Supprime la valeur du noeud. O(1)
         * \return vrai si la valeur a bien été supprimé, sinon faux (valeur nulle)
         */
        bool remove_value();

        /*!
         * \brief Modifie la valeur du noeud. O(1)
         * \param value : la nouvelle valeur
         * \return vrai si la valeur a été écrasé, sinon faux (valeur nulle)
         */
        bool set_value(const V& value);

        /*!
         * \brief Charge les mots et les valeurs de l'arbre dans les tableaux passés en paramètre.
         * \param strings_array : le tableau contenant les mots
         * \param values_array : le tableau contenant les valeurs
         * \param index : l'indice courant des tableaux
         * \param acc : l'accumulateur contenant le mot correspondant au chemin parcouru
         * \return le couple contenant les tableaux des mots et des valeurs de l'arbre
         */
        int to_array(string* strings_array ,V* values_array, int index=0, string acc=string()) const;
};

template <typename V>
node<V>::node(): _value(0)
{
    ;
}

template <typename V>
node<V>::~node()
{
    clear();
}

template <typename V>
void node<V>::clear()
{
    delete _value;
    _value = 0;
    _children.clear();
}

template <typename V>
bool node<V>::contains(string::const_iterator it, string::const_iterator end) const
{
    try
    {
        if(it == end)
        {
            return _children.get_ref(*it).is_empty();
        }
        else
        {
            string::const_iterator next(it);
            next++;
            return _children.get_ref(*it).contains(next,end);
        }
    }
    catch(exception& e)
    {
        return false;
    }
}

template <typename V>
V node<V>::get(string::const_iterator it, string::const_iterator end) const
{
    if(it == end)
    {
        return _children.get_ref(*it).get_value();
    }
    else
    {
        string::const_iterator next(it);
        next++;
        return _children.get_ref(*it).get(next,end);
    }
}

template <typename V>
V node<V>::get_value() const
{
    if(is_empty())
    {
        throw exception();
    }
    else
    {
        return *_value;
    }
}

template <typename V>
bool node<V>::is_empty() const
{
    return _value == 0;
}

template <typename V>
bool node<V>::is_leaf() const
{
    return _children.is_empty();
}

template <typename V>
bool node<V>::remove(string::const_iterator it, string::const_iterator end)
{
    try
    {
        if(it == end)
        {
            if(_children.get_ref(*it).is_leaf())
            {
                return _children.remove(*it);
            }
            else
            {
                return _children.get_ref(*it).remove_value();
            }
        }
        else
        {
            string::const_iterator next(it);
            next++;
            if(_children.get_ref(*it).remove(next,end))
            {
                if(_children.get_ref(*it).is_leaf())
                {
                    _children.remove(*it);
                }
                return true;
            }
            else
            {
                return false;
            }
        }
    }
    catch(exception& e)
    {
        return false;
    }
}

template <typename V>
bool node<V>::remove_value()
{
    if(is_empty())
    {
        return false;
    }
    else
    {
        delete _value;
        _value = 0;
        return true;
    }
}

template <typename V>
bool node<V>::set(const V& value, string::const_iterator it, string::const_iterator end)
{
    try
    {
        if(it == end)
        {
            return _children.get_ref(*it).set_value(value);
        }
        else
        {
            string::const_iterator next(it);
            next++;
            return _children.get_ref(*it).set(value,next,end);
        }
    }
    catch(exception& e)
    {
        _children.put(*it,node<V>());
        return set(value,it,end);
    }
}

template <typename V>
bool node<V>::set_value(const V& value)
{
    if(_value == 0)
    {
        _value = new V(value);
        return false;
    }
    else
    {
        *_value = value;
        return true;
    }
}

template <typename V>
int node<V>::size() const
{
    int acc = 0;
    if(!is_empty())
    {
        acc++;
    }
    char* keys = _children.keys_array();
    for(int i=0; i<_children.size(); i++)
    {
        acc += _children.get_ref(keys[i]).size();
    }
    delete[] keys;
    return acc;
}

template <typename V>
pair<string*,V*> node<V>::to_array() const
{
    int _size = size();
    string* strings_array = new string[_size];
    V* values_array = new V[_size];
    pair<string*,V*> res(strings_array,values_array);
    to_array(strings_array,values_array);
    return res;
}

template <typename V>
int node<V>::to_array(string* strings_array ,V* values_array, int index, string acc) const
{
    char* keys = _children.keys_array();
    for(int i=0; i<_children.size(); i++)
    {
        string key(acc);
        key.push_back(keys[i]);
        if(!_children.get_ref(keys[i]).is_empty())
        {
            strings_array[index] = key;
            values_array[index] = _children.get_ref(keys[i]).get_value();
            index++;
        }
        index = _children.get_ref(keys[i]).to_array(strings_array,values_array,index,key);
    }
    delete[] keys;
    return index;
}

template <typename V>
void node<V>::to_list(list< pair<string,V> >& ls, string acc) const
{
    char* keys = _children.keys_array();
    for(int i=0; i<_children.size(); i++)
    {
        string key(acc);
        key.push_back(keys[i]);
        if(!_children.get_ref(keys[i]).is_empty())
        {
            pair<string,V> tmp(key,_children.get_ref(keys[i]).get_value());
            ls.push_front(tmp);
        }
        _children.get_ref(keys[i]).to_list(ls,key);
    }
    delete[] keys;
}

/*!
 * \brief Surchage de l'opérateur de flux pour afficher le noeud. O(n)
 * \param os : le flux de sortie
 * \param m : le noeud à afficher
 * \return le flux de sortie
 */
template <typename V>
ostream& operator<<(ostream& os, const node<V>& n)
{
    list<pair<string,V> > ls;
    n.to_list(ls);
    os << n.size() << endl;
    for(typename list<pair<string,V> >::iterator it=ls.begin(); it != ls.end(); it++)
    {
        os << (*it).first << " : " << (*it).second << endl;
    }
    return os;
}

#endif
