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
        typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

        vector() { create(); }
        explicit vector(size_t n, const T& t = T{}) { create(n, t); }
        ~vector() { del(); }
        vector(const vector& v) { create(v.begin(), v.end()); }
        
        vector& operator=(const vector&);
        T& operator[](size_t i) { return dt[i]; }
        const T& operator[](size_t i) const { return dt[i]; }

        void assign(size_t, const T&);
        T& at(size_t);
        T& back();
        iterator begin() { return dt; }
        size_t capacity() const { return cap - dt; }
        const_iterator cbegin() const { return dt; }
        const_iterator cend() const { return sz; }
        void clear();
        const_reverse_iterator crbegin() const { return const_reverse_iterator(cend()); }
        const_reverse_iterator crend() const { return const_reverse_iterator(cbegin()); }
        T* data() { return dt; }

        iterator end() { return sz; }

        void push_back (const T& value) {
            if (sz == cap)
                expand();
            unchecked_append(value);
        }

        void reserve(size_t);

        void shrink_to_fit();
        size_t size() const { return sz - dt; }

    private:
        iterator dt;
        iterator sz;
        iterator cap;

        std::allocator<T> alloc;

        void create() ;
        void create(size_t, const T&);
        void create(const_iterator, const_iterator);

        void del();

        void resize(size_t);
        void expand();
        void unchecked_append(const T&);
};