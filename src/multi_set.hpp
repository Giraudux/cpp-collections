// Alexis Giraudet
// Théo Cesbron

#ifndef MULTI_SET_HPP
#define MULTI_SET_HPP

#include <exception>

template <typename T>
class multi_set
{
    public:
        multi_set();
        ~multi_set();
        bool add(T t_type);
        void clear();
        bool is_empty();
        bool remove(T t_type);
        bool remove_all(T t_type);
        multi_set fusion(const multi_set &mul);
        multi_set inter(const multi_set &mul);
        void sub(multi_set &mul);
        bool equal(const multi_set &mul);   
};

template <typename T>
multi_set<T>::multi_set()
{
    ;
}

template <typename T>
multi_set<T>::~multi_set()
{
    
    ;
}

#endif
