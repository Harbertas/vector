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