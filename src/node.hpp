// Alexis Giraudet
// Théo Cesbron

#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
#include <exception>
#include <set>

using namespace std;

template <typename K, typename V>
class node
{

    struct node_comparator {
        bool operator()(const node* lhs, const node* rhs) const
        {
            return (*lhs).get_key() < (*rhs).get_key();
        }
    };

    private:
        set<node*,node_comparator> _children;
        K _key;
        V _value;

    public:
        node(K key);
        ~node();
        bool add_child(node* child);
        K get_key() const;
        V get_value() const;
        bool is_leaf() const;
        void set_value(V value);
        
};

template <typename K, typename V>
node<K,V>::node(K key): _key(key), _value()
{
    ;
}

template <typename K, typename V>
node<K,V>::~node()
{
    ;
}

template <typename K, typename V>
bool node<K,V>::add_child(node* child)
{
    pair<typename set<node<K, V>*>::iterator,bool> res = _children.insert(child);
    return res.second;
}

template <typename K, typename V>
K node<K,V>::get_key() const
{
    return _key;
}

template <typename K, typename V>
V node<K,V>::get_value() const
{
    return _value;
}

template <typename K, typename V>
bool node<K,V>::is_leaf() const
{
    return _children.empty();
}

template <typename K, typename V>
void node<K,V>::set_value(V value)
{
    _value = value;
}

#endif
