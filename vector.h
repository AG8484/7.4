#ifndef VECTOR_H
#define VECTOR_H

#include <stdexcept>
#include <utility>
#include <iostream>

namespace mine 
{
    template <typename T>
    class Vector 
    {
        private:
            T* arrayofelements;
            size_t m_size;
            size_t m_capacity;

            void reallocate(size_t new_capacity);

        public:
            Vector();
            explicit Vector(size_t count);
            Vector(size_t count, const T& value);
            Vector(const Vector& other);
            Vector(Vector&& other) noexcept;
            ~Vector();

            T& operator[](size_t pos);
            T& at(size_t pos);
            T& front();
            T& back();

            bool empty() const noexcept;
            size_t size() const noexcept;
            size_t capacity() const noexcept;
            void reserve(size_t new_cap);
            void resize(size_t count) noexcept;

            void pushback(const T& value);
            void pushback(T&& value);
            void popback();
            void clear() noexcept;

            Vector& operator=(const Vector& other);
            Vector& operator=(Vector&& other) noexcept;

        class iterator 
        {
            private:
                T* current;
            public:
                explicit iterator(T* ptr) : current(ptr) 
                {

                }
                iterator& operator++() 
                { 
                    ++current; 
                    return *this; 
                }
                iterator operator++(int) 
                { 
                    iterator temp = *this; ++(*this); 
                    return temp; 
                }
                T& operator*() const 
                { 
                    return *current; 
                }
                T* operator->() const 
                { 
                    return current; 
                }
                bool operator!=(const iterator& other) const 
                { 
                    return current != other.current; 
                }
            };

            iterator begin() 
            { 
                return iterator(arrayofelements); 
            }
            iterator end() 
            { 
                return iterator(arrayofelements + m_size); 
            }
    };

}

#include "vector.cpp"

#endif