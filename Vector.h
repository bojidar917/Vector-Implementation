#pragma once
#include <iostream>

class  Vector
{
public:
    Vector();
    Vector(const int capacity); 
    Vector(const Vector& other);
    Vector& operator=(const Vector& other);
    ~Vector();

    int size() const;
    int capacity() const;
    int& at(const int index);
    void pushBack(const int element);
    void erase(const int index);
    void reserve(const int capacity);
    void see() const;
    int find(const int element) const;
    int get(const int index) const;
 
private:
    int *array;
    size_t arr_size; 
    size_t arr_capacity;

    void resize();
    void clear();
    void copy(const Vector& vector);
};
