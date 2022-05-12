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
    dt = sz = cap = nullptr;
}

template <class T>
void vector<T>::create(size_t n, const T& val) {
    dt = alloc.allocate(n);
    cap = sz = dt + n;
    std::uninitialized_fill(dt, cap, val);
}

template <class T>
void vector<T>::create(const_iterator i, const_iterator j) {
    dt = alloc.allocate(j - i);
    cap = sz = std::uninitialized_copy(i, j, dt);
}

template <class T>
void vector<T>::del() {
    if (dt) {
        iterator it = sz;
        while (it != dt)
            alloc.destroy(--it);
        alloc.deallocate(dt, this->capacity());
    }
    dt = cap = sz = nullptr;
}

template <class T>
void vector<T>::resize(size_t new_cap) {
    iterator new_dt = alloc.allocate(new_cap);
    iterator new_sz = std::uninitialized_copy(dt, sz, new_dt);

    del();

    dt = new_dt;
    sz = new_sz;
    cap = dt + new_cap;
}

template <class T>
void vector<T>::expand() {
    size_t new_cap = 2 * (this->capacity());

    iterator new_dt = alloc.allocate(new_cap);
    iterator new_sz = std::uninitialized_copy(dt, sz, new_dt);

    del();

    dt = new_dt;
    sz = new_sz;
    cap = dt + new_cap;
}

template <class T>
void vector<T>::unchecked_append(const T& val) {
    alloc.construct(sz++, val);
}

template <class T>
void vector<T>::reserve(size_t s) {
    if (s >= this->size() && s >= 0)
        resize(s);
    else {
        std::bad_alloc exception;
        throw exception;
    }
}

template <class T>
void vector<T>::shrink_to_fit() {
    resize(this->size());
}

template <class T>
T& vector<T>::at(size_t i) {
    if (i >= this->size()) {
        throw std::out_of_range("vector::_M_range_check: __n (which is " + std::to_string(i) + " ) >= this->size() (which is " + std::to_string(i) + " )");
    } else
        return dt[i];
}

template <class T>
void vector<T>::assign(size_t n, const T& value) {
    del();
    create(n, value);
}

template <class T>
T& vector<T>::back() {
    return *(this->end()-1);
}

template <class T>
void vector<T>::clear() {
    size_t cap = this->capacity();
    del();
    resize(cap);
}