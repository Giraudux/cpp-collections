// Alexis Giraudet
// Théo Cesbron

#ifndef NODE_HPP
#define NODE_HPP

#
#include <exception>
#include <list>

using namespace std;

template <typename K, typename V>
class node
{
    private:
        list<node> _children;//todo: use set
        K _key;
        V _value;

    public:
        node(K key);
        ~node();
        bool is_leaf();
        void add_child(node child);
        
};

template <typename K, typename V>
node::node(K key)
{
    _key = key;
}

template <typename K, typename V>
node::~node()
{
    ;
}

#endif
