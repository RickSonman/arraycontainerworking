#include <iostream>
#include "ArrayInt.h"
#include <string_view>
#include <array>

int main()
{
    ArrayInt array(10);

    // ��������� ������ ������� �� 1 �� 10
    for (int i = 0; i < 10; i++)
        array[i] = i + 1;

    // �������� ������ ������� �� 7 ���������
    array.resize(10);

    // ��������� ����� 15 ����� ��������� � �������� 4
    array.insertBefore(15, 3);

    // ������� ������� � �������� 5
    array.remove(0);
    array.insertBefore(111, 0);
    //
    // ��������� ����� 35 � 50 � ����� � � ������
    array.insertAtEnd(35);
    array.insertAtBeginning(50);

    // ������� ��� �������� �������
    for (int j = 0; j < array.getLength(); j++)
        std::cout << array[j] << " ";


   /* std::array<std::string_view, 4> arr{ "apple", "banana", "walnut", "lemon" };

    auto found = std::find_if(arr.begin(), arr.end(), containsNut);
    std::cout << *found << std::endl;*/
    
    return 0;
}