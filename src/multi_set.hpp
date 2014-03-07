// Alexis Giraudet
// Théo Cesbron

#ifndef MULTI_SET_HPP
#define MULTI_SET_HPP

template <typename T>
class multi_set
{
    public:
        virtual bool add(T t_type) = 0;
        virtual void clear() = 0;
        virtual bool equal(const multi_set &mul) = 0;   
        virtual multi_set fusion(const multi_set &mul) = 0;
        virtual multi_set intersection(const multi_set &mul) = 0;
        virtual bool is_empty() = 0;
        virtual bool remove(T t_type) = 0;
        virtual bool remove_all(T t_type) = 0;
        virtual void sub(multi_set &mul) = 0;
};

#endif
