#include "vector.hpp"

template <class T>
vector<T>& vector<T>::operator=(const vector& v) {
    if (&v != this) {
        del();
        create(v.begin(), v.end());
    }
 return *this;
}

template <class T>
void vector<T>::create() {
    data = sz = cap = nullptr;
}

template <class T>
void vector<T>::create(size_type n, const T& val) {
    data = alloc.allocate(n);
    cap = sz = data + n;
    uninitialized_fill(data, cap, val);
}

template <class T>
void vector<T>::create(const_iterator i, const_iterator j) {
    data = alloc.allocate(j - i);
    cap = sz = std::uninitialized_copy(i, j, data);
}

template <class T>
void vector<T>::del() {
    if (data) {
        iterator it = sz;
        while (it != data)
            alloc.destroy(--it);
        alloc.deallocate(data, cap - data);
    }
    data = cap = sz = nullptr;
}

template <class T>
void vector<T>::expand() {
    size_type new_cap = std::max(2 * (cap - data), ptrdiff_t(1));
    iterator new_data = alloc.allocate(new_cap);
    iterator new_sz = std::uninitialized_copy(data, sz, new_data);

    del();

    data = new_data;
    sz = new_sz;
    cap = data + new_cap;
}

template <class T>
void vector<T>::unchecked_append(const T& val) {
    alloc.construct(sz++, val);
}