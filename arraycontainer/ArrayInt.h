#pragma once
#include <iostream>

class ArrayInt
{
public:
    ArrayInt(int length);
    ~ArrayInt();
    ArrayInt(const std::initializer_list<int> &);
    int& operator[](int index);
    int getLength();
    void erase();
    void resize(int size);
    void remove(int del_index);
    void insertBefore(int value, int index);
    void insertAtEnd(int value);
    void insertAtBeginning(int value);
    ArrayInt& operator=(const std::initializer_list<int>& list);

private:
    int* m_array;
    int m_length;
    
};

bool containsNut(std::string_view view);