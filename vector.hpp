#pragma once
#include <memory>

#include <iostream>
#include <string>

template <class T>
class vector {
    public:
        typedef T* iterator;
        typedef const T* const_iterator;
        typedef T value_type;
        typedef size_t size_type;
        typedef const T const_value_type;
        typedef T& reference;
        typedef const T& const_reference;
        typedef std::reverse_iterator<iterator> reverse_iterator;
        typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

        vector() { create(); }
        explicit vector(size_type n, const value_type& t = value_type{}) { create(n, t); }
        vector(std::initializer_list<value_type> l) { create(l.begin(), l.end()); }
        ~vector() { del(); }
        vector(const vector& v) { create(v.begin(), v.end()); }
        vector(const_iterator b, const_iterator e) { create(b, e); }
        
        vector& operator=(const vector&);
        T& operator[](size_type i) { return dt[i]; }
        const T& operator[](size_type i) const { return dt[i]; }


        void assign(iterator, iterator);
        void assign(size_type, const value_type&);
        void assign (std::initializer_list<value_type>);

        reference at(size_type);
        const_reference at (size_type n) const;

        reference back() { return *(end() - 1); };
        const_reference back() const { return *(end() - 1); }

        iterator begin() noexcept { return dt; }
        const_iterator begin() const noexcept { return dt; }

        size_type capacity() const noexcept { return cap - dt; }
        
        const_iterator cbegin() const noexcept { return dt; }

        const_iterator cend() const noexcept { return sz; }

        void clear() noexcept;

        const_reverse_iterator crbegin() const noexcept { return const_reverse_iterator(cend()); }

        const_reverse_iterator crend() const noexcept { return const_reverse_iterator(cbegin()); }

        value_type* data() noexcept { return dt; }
        const_value_type* data() const noexcept { return dt; }

        iterator emplace(iterator, const value_type&);

        void emplace_back(const value_type&);

        bool empty() const noexcept { return (sz - dt) == 0 || dt == nullptr; }

        iterator end() noexcept { return sz; }
        const_iterator end() const noexcept { return sz; }

        void erase(iterator);
        void erase(iterator, iterator);
        
        reference front() { return *(dt); }
        const_reference front() const { return *(dt); }

        std::allocator<T> get_allocator() const noexcept { return alloc; }

        iterator insert(const_iterator , const value_type&);
        void insert(const_iterator , size_type, const value_type&);
        void insert(const_iterator , iterator, iterator);
        iterator insert(const_iterator, value_type&&);
        iterator insert(const_iterator, std::initializer_list<value_type>);

        size_type max_size() const noexcept { return alloc.max_size(); }

        void pop_back() { sz--; }

        void push_back (const value_type& value) {
            if (sz == cap)
                expand();
            unchecked_append(value);
        }
        void push_back (value_type&& value) {
            if (sz == cap)
                expand();
            unchecked_append(value);
        }

        reverse_iterator rbegin() noexcept { return reverse_iterator(end()); }
        const_reverse_iterator rbegin() const noexcept { return const_reverse_iterator(cend()); }

        reverse_iterator rend() noexcept { return reverse_iterator(begin()); }
        const_reverse_iterator rend() const noexcept { return const_reverse_iterator(cbegin()); }
        
        void reserve(size_type);

        void resize(size_type);
        void resize (size_type, const value_type&);
        
        void shrink_to_fit();

        size_type size() const noexcept { return sz - dt; }

        void swap(vector&);

        bool operator==(const vector& stud);
        bool operator!=(const vector& stud);

        template<class t>
        friend bool operator<(const vector<t>& a, const vector<t>& b);
        template<class t>
        friend bool operator>(const vector<t>& a, const vector<t>& b);
        template<class t>
        friend bool operator<=(const vector<t>& a, const vector<t>& b);
        template<class t>
        friend bool operator>=(const vector<t>& a, const vector<t>& b);

    private:
        iterator dt;
        iterator sz;
        iterator cap;

        std::allocator<T> alloc;

        void create() ;
        void create(size_type, const T&);
        void create(const_iterator, const_iterator);

        void del();

        void expand();
        void expand(size_type);
        void unchecked_append(const T&);
};

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
void vector<T>::create(size_type n, const T& val) {
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
void vector<T>::resize(size_type new_cap) {
    size_type old_size = this->size();
    if (new_cap > this->capacity()) {
        iterator new_dt = alloc.allocate(new_cap);
        iterator new_sz = std::uninitialized_copy(dt, dt + new_cap, new_dt);

        del();

        dt = new_dt;
        sz = new_sz;
        cap = dt + new_cap;
    } else {
        sz = dt + new_cap;
    }
    if (new_cap > old_size) {
        auto it = dt + old_size;
        while (it != sz) {
            *it = 0;
            it++;
        }
    }
}

template <class T>
void vector<T>::resize(size_type new_cap, const value_type& val) {
    size_type old_size = this->size();
    if (new_cap > this->capacity()) {
        iterator new_dt = alloc.allocate(new_cap);
        iterator new_sz = std::uninitialized_copy(dt, dt + new_cap, new_dt);

        del();

        dt = new_dt;
        sz = new_sz;
        cap = dt + new_cap;
    } else {
        sz = dt + new_cap;
    }

    if (new_cap > old_size) {
        auto it = dt + old_size;
        while (it != sz) {
            *it = val;
            it++;
        }
    }
}

template <class T>
void vector<T>::expand() {
    size_type new_cap = std::max(2 * (cap - dt), ptrdiff_t(1));

    iterator new_dt = alloc.allocate(new_cap);
    iterator new_sz = std::uninitialized_copy(dt, sz, new_dt);

    del();

    dt = new_dt;
    sz = new_sz;
    cap = dt + new_cap;
}

template <class T>
void vector<T>::expand(size_type new_cap) {
    auto old_size = this->size();
    iterator new_dt = alloc.allocate(new_cap);
    iterator new_sz = std::uninitialized_copy(dt, dt + new_cap, new_dt);

    del();

    dt = new_dt;
    sz = new_sz;
    cap = dt + new_cap;
    
    if (this->size() > old_size) {
        sz -= this->size() - old_size;
    }
}

template <class T>
void vector<T>::unchecked_append(const T& val) {
    alloc.construct(sz++, val);
}

template <class T>
void vector<T>::reserve(size_type s) {
    if (s >= this->size() && s >= 0)
        expand(s);
    else {
        std::bad_alloc exception;
        throw exception;
    }
}

template <class T>
void vector<T>::shrink_to_fit() {
    expand(this->size());
}

template <class T>
typename vector<T>::reference vector<T>::at(size_type i) {
    if (i >= this->size()) {
        throw std::out_of_range("vector::_M_range_check: __n (which is " + std::to_string(i) + " ) >= this->size() (which is " + std::to_string(i) + " )");
    } else
        return dt[i];
}

template <class T>
typename vector<T>::const_reference vector<T>::at(size_type i) const {
    if (i >= this->size()) {
        throw std::out_of_range("vector::_M_range_check: __n (which is " + std::to_string(i) + " ) >= this->size() (which is " + std::to_string(i) + " )");
    } else
        return dt[i];
}

template <class T>
void vector<T>::assign(size_type n, const T& value) {
    del();
    create(n, value);
}

template <class T>
void vector<T>::assign(iterator first, iterator last) {
    del();
    create(first, last);
}

template <class T>
void vector<T>::assign(std::initializer_list<T> l) {
    del();
    create(l.begin(), l.end());
}

template <class T>
void vector<T>::clear() noexcept {
    sz = dt;
}

template <class T>
typename vector<T>::iterator vector<T>::emplace(iterator position, const value_type& value) {
    int pos = position - dt;

    if (sz == cap)
        expand();

    iterator it = dt + pos;

    for (iterator i = sz - 1; i != it - 1; i--)
        *(i+1) = *i;
    sz++;

    *it = value;
    return it;
}

template <class T>
void vector<T>::emplace_back(const T& value) {
    if (sz == cap)
        expand();
    *sz = value;
    sz++;
}

template <class T>
void vector<T>::erase(iterator it) {
    for (iterator i = it; i != this->end()-1; i++)
        *i = *(i+1);
    sz--;
}

template <class T>
void vector<T>::erase(iterator b, iterator e) {
    for (iterator i = b; i != e + (e - b); i++)
        *i = *(i + (e - b));
    sz -= (e - b);
}

template <class T>
typename vector<T>::iterator vector<T>::insert(const_iterator position, const value_type& value) {
    int pos = position - dt;

    if (sz == cap)
        expand();

    iterator it = dt + pos;

    for (iterator i = sz - 1; i != it - 1; i--)
        *(i+1) = *i;
    sz++;

    *it = value;
    return it;
}

template <class T>
void vector<T>::insert(const_iterator position, size_type n, const value_type& val) {
    int pos = position - dt;

    if ((sz + n) > cap)
        expand((sz+n) - dt);

    iterator it = dt + pos;

    for (iterator i = sz - 1; i != it - 1; i--)
        *(i+n) = *i;
    sz += n;

    for (int i = 0; i < n; i++)
        *(it + i) = val;
}

template <class T>
void vector<T>::insert(const_iterator position, iterator first, iterator last) {
    size_type n = last - first;
    int pos = position - dt;

    if ((sz + n) > cap)
        expand((sz+n) - dt);

    iterator it = dt + pos;

    for (iterator i = sz - 1; i != it - 1; i--)
        *(i+n) = *i;
    sz += n;

    for (int i = 0; i < n; i++)
        *(it + i) = *(first + i);
}

template <class T>
typename vector<T>::iterator vector<T>::insert(const_iterator position, value_type&& val) {
    int pos = position - dt;

    if (sz == cap)
        expand();

    iterator it = dt + pos;

    for (iterator i = sz - 1; i != it - 1; i--)
        *(i+1) = *i;
    sz++;

    *it = val;
    return it;
}

template <class T>
typename vector<T>::iterator vector<T>::insert(const_iterator position, std::initializer_list<value_type> l) {
    size_type n = l.size();
    int pos = position - dt;

    if ((sz + n) > cap)
        expand((sz+n) - dt);

    iterator it = dt + pos;

    for (iterator i = sz - 1; i != it - 1; i--)
        *(i+n) = *i;
    sz += n;

    auto lit = l.begin();
    for (int i = 0; i < n; i++)
        *(it + i) = *(lit + i);

    return it;
}


template <class T>
void vector<T>::swap(vector& vec) {
    auto tmp (vec);

    vec.clear();
    for (auto it = dt; it != sz; it++) {
        vec.push_back(*it);
    }

    this->del();
    this->create(tmp.begin(), tmp.end());
}

template <class T>
bool vector<T>::operator==(const vector& v) {
    return (this->size() == v.size() && std::equal(this->begin(), this->end(), v.begin()));
}

template <class T>
bool vector<T>::operator!=(const vector& v) {
    return !(this->size() == v.size() && std::equal(this->begin(), this->end(), v.begin()));
}

template <class T>
bool operator<(const vector<T>& a, const vector<T>& b) {
    return std::lexicographical_compare(a.begin(), a.end(), b.begin(), b.end());
}

template <class T>
bool operator>(const vector<T>& a, const vector<T>& b) {
    return (b < a);
}

template <class T>
bool operator<=(const vector<T>& a, const vector<T>& b) {
    return !(b < a);
}

template <class T>
bool operator>=(const vector<T>& a, const vector<T>& b) {
    return !(a < b);
}