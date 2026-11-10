#pragma once
#include <iostream>

using namespace std;

// Шаблонна функція для інверсії елементів масиву будь-якого типу
template <typename T>
void InvertArray(T arr[], int size) {
    if (!arr || size <= 1) return;
    for (int i = 0; i < size / 2; ++i) {
        T temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}