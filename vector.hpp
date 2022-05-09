#pragma once
#include <memory>

template <class T>
class vector {
    public:
        typedef T* iterator;
        typedef const T* const_iterator;
        typedef size_t size_type;
        typedef T value_type;

        vector() { create(); }
        explicit vector(size_type n, const T& t = T{}) { create(n, t); }
        vector(const vector& v) { create(v.begin(), v.end()); }
        
        vector& operator=(const vector&);
        ~vector() { del(); }

        T& operator[](size_type i) { return data[i]; }
        const T& operator[](size_type i) const { return data[i]; }

        void push_back (const T& t) {
            if (sz == cap)
                expand();
            unchecked_append(t);
        }

        size_type size() const { return sz - data; }
        size_type capacity() const { return cap - data; }
        iterator begin() { return data; }
        const_iterator begin() const { return data; }
        iterator end() { return sz; }
        const_iterator end() const { return sz; }
    private:
        iterator data;
        iterator sz;
        iterator cap;

        std::allocator<T> alloc;

        void create() ;
        void create(size_type, const T&);
        void create(const_iterator, const_iterator);

        void del();

        void expand();
        void unchecked_append(const T&);
};