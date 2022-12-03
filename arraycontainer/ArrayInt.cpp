#include "ArrayInt.h"
#include <cassert>
#include <string_view>

ArrayInt::ArrayInt(int length) :m_length(length)
{
    m_array = new int[length];
}

ArrayInt::~ArrayInt()
{
    delete[] m_array;
}

ArrayInt::ArrayInt(const std::initializer_list<int>& list) :ArrayInt(list.size())
{
    for (int i = 0; i < m_length; ++i)
        m_array[i] = list.begin()[i];
}

int& ArrayInt::operator[](int index)
{
    return m_array[index];
}

ArrayInt& ArrayInt::operator=(const std::initializer_list<int>& l)
{
    delete[] m_array;
    m_length = l.size();
    m_array = new int[m_length];
    for (int i = 0; i < m_length; ++i)
        m_array[i] = l.begin()[i];
    return *this;
}

int ArrayInt::getLength()
{
    return m_length;
}

void ArrayInt::erase()
{
    delete[] m_array;
    m_length = 0;
}

void ArrayInt::resize(int size)
{
    assert(size >= 0 && size <= m_length);
    int* data = new int[size];
    for (int index = 0; index < size; ++index)
        data[index] = m_array[index];
    delete m_array;
    m_array = data;
    m_length = size;

}

void ArrayInt::remove(int del_index)
{
    assert(del_index < m_length&& del_index >= 0);
    int* data = new int[m_length - 1];
    if (del_index >= 0 && del_index < m_length) {
        for (int index = 0; index < del_index; ++index)
            data[index] = m_array[index];
        for (int index = del_index; index < m_length - 1; ++index)
            data[index] = m_array[index + 1];
    }
    delete[] m_array;
    m_array = data;
    m_length--;
}

void ArrayInt::insertBefore(int value, int index)
{
    assert(index < m_length&& index >= 0);
    int* data = new int[m_length + 1];

    for (int i = 0; i < index; ++i)
        data[i] = m_array[i];
    data[index] = value;
    for (int i = index + 1; i < m_length + 1; ++i)
        data[i] = m_array[i - 1];

    delete[] m_array;
    m_array = data;
    m_length++;
}


void ArrayInt::insertAtEnd(int value)
{
    int* data = new int[m_length + 1];
    for (int i = 0; i < m_length; ++i)
        data[i] = m_array[i];
    data[m_length] = value;
    delete[] m_array;
    m_array = data;
    m_length++;
}
void ArrayInt::insertAtBeginning(int value)
{
    int* data = new int[m_length + 1];
    data[0] = value;
    for (int i = 1; i < m_length + 1; ++i)
        data[i] = m_array[i - 1];
    delete[] m_array;
    m_array = data;
    m_length++;
}

bool containsNut(std::string_view view)
{
    return (view.find("nut") != std::string_view::npos);
}