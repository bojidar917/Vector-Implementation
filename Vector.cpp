#include "Vector.h"
#include <assert.h>
#include <iostream>

Vector::Vector() : arr_size(0), arr_capacity(4), array(nullptr)
{
    array = new int[arr_capacity];
}

Vector::Vector(const int capacity) : Vector()
{
    array = new int[capacity];
}

Vector::Vector(const Vector &other)
{
    copy(other);
}

Vector &Vector::operator=(const Vector &other)
{
    if(this != &other)
    {
        clear();
        copy(other);
    }
    return *this;
}

Vector::~Vector()
{
    clear();
}

int Vector::size() const
{
    return this->arr_size;
}

int Vector::capacity() const
{
    return this->arr_capacity;
}

void Vector::resize()
{
    int* temp = new int[arr_capacity*2];
    for (int i = 0; i < arr_size; i++) 
    {
        temp[i] = this->array[i];
    }
    delete[] this->array;
    this->array = temp;
    this->arr_capacity *= 2;
}

int Vector::find(const int element) const
{
    for (int i = 0; i < arr_size; i++)
    {
        if(this->array[i] == element)
            return i;
    }
    
    return -1;
}

void Vector::clear()
{
    delete[] array;
    array = nullptr;
}

int Vector::get(const int index) const
{
    if(index > arr_size)
        return -2;
    for (int i = 0; i < arr_size; i++)
    {
        //prints the element on the given index
        if(i == index)
            return array[i];
    }
    
    return -1;
}

void Vector::copy(const Vector &vector)
{
    arr_size = vector.arr_size;
    arr_capacity = vector.arr_capacity;

    this->array = new int[arr_capacity];
    for (int i = 0; i < arr_size; i++)
    {
        array[i] = vector.array[i];
    }
}

int &Vector::at(const int index)
{
    // assert(index >= size); // edin variant
    if(index >= arr_size)
    {
        throw "Out of range index";
    }
    return array[index];
}

void Vector::pushBack(const int element)
{
    if(arr_size >= arr_capacity)
    {
        // resize();
        reserve(this->arr_capacity*2);
    }

    array[arr_size++] = element;
}

void Vector::erase(const int index)
{
    for (int i = index; i < arr_size-1; i++)
    {
        array[i] = array[i+1];
    }
    this->arr_size -= 1;
}

void Vector::reserve(const int capacity)
{
    if (capacity <= this->arr_capacity)
    {
        std::cout << "You cannot set less than or equal to the current capacity" << std::endl;
        return;
    }
    
    int* temp = new int[capacity];
    for (int i = 0; i < arr_size; i++)
    {
        temp[i] = array[i];
    }
    delete[] array;
    this->array = temp;
    this->arr_capacity = capacity;
}

void Vector::see() const
{
    for (int i = 0; i < arr_size; i++)
    {
        std::cout << this->array[i] << " ";
    }
    std::cout << std::endl;   
}
