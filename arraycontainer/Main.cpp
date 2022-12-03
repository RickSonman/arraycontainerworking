#include <iostream>
#include "ArrayInt.h"
#include <string_view>
#include <array>

int main()
{
    ArrayInt array(10);

    // Заполняем массив числами от 1 до 10
    for (int i = 0; i < 10; i++)
        array[i] = i + 1;

    // Изменяем размер массива до 7 элементов
    array.resize(10);

    // Вставляем число 15 перед элементом с индексом 4
    array.insertBefore(15, 3);

    // Удаляем элемент с индексом 5
    array.remove(0);
    array.insertBefore(111, 0);
    //
    // Добавляем числа 35 и 50 в конец и в начало
    array.insertAtEnd(35);
    array.insertAtBeginning(50);

    // Выводим все элементы массива
    for (int j = 0; j < array.getLength(); j++)
        std::cout << array[j] << " ";


   /* std::array<std::string_view, 4> arr{ "apple", "banana", "walnut", "lemon" };

    auto found = std::find_if(arr.begin(), arr.end(), containsNut);
    std::cout << *found << std::endl;*/
    
    return 0;
}