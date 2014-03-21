// Alexis Giraudet

#ifndef HEAP_HPP
#define HEAP_HPP

#include <exception>

template <typename T, int S>
class heap
{
    private:
        T *_data;
        int _n;

    public:
        heap();
        ~heap();
        void add(T elt);
        int index_of_father(T elt)
        T get_max();//throw std::exception
        void heap_up(int k);
        bool is_empty();
        void remove_max();
};

template <typename T, int S>
heap<T,S>::heap(): _n(0)
{
    _data = new T[S];
}

template <typename T, int S>
heap<T,S>::~heap()
{
    delete[] _data;
}

template <typename T, int S>
void heap<T,S>::add(T elt)
{
    //todo: test size max and throw exception
    _data[n] = elt;
    heap_up(n);
    n++;
}

template <typename T, int S>
T heap<T,S>::get_max()
{
    if(is_empty())
    {
        throw std::exception();
    }
    return _data[0];
}
template <typename T, int S>
void heap<T,S>::heap_up(int k)
{
    T v = _data[k];
    while((k>0) && (v>_data[index_of_father(k)]))
    {
        _data[k] = _datat[index_of_father(k)];
        k = index_of_father(k);
    }
    _data[k] = v;
}

template <typename T, int S>
bool heap<T,S>::is_empty()
{
    return n == 0;
}

template <typename T, int S>
void heap<T,S>::remove_max()
{
    n--;
    _data[0] = _data[n];
    //todo: retasser(0);
}

#endif
