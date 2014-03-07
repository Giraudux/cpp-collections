// Alexis Giraudet
// Théo Cesbron

#ifndef MULTI_SET_HPP
#define MULTI_SET_HPP

template <typename T>
class multi_set
{
    public:
        virtual void add(T type) = 0;
        virtual void clear() = 0;
        virtual bool equal(const multi_set &mul) = 0;   
        virtual void fusion(const multi_set &mul) = 0;
        virtual void intersection(const multi_set &mul) = 0;
        virtual bool is_empty() = 0;
        virtual void remove(T type) = 0;
        virtual void remove_all(T type) = 0;
        virtual void sub(multi_set &mul) = 0;
};

#endif
