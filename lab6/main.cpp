#include <iostream>
#include <string>
#include "InvertArray.h"
#include "Queue.h"

using namespace std;

int main() {
    try {
        //Завдання 1
        cout << "\nArray Inversion: " << endl;

        int intArr[] = { 10, 20, 30, 40, 50 };
        int intSize = 5;
        
        cout << "Original int array: ";
        for (int i = 0; i < intSize; ++i) cout << intArr[i] << " ";
        cout << endl;

        InvertArray(intArr, intSize); // Виклик шаблону для int

        cout << "Inverted int array: ";
        for (int i = 0; i < intSize; ++i) cout << intArr[i] << " ";
        cout << endl;

        // Комплект даних 2: Масив рядків
        string strArr[] = { "Alpha", "Beta", "Gamma", "Delta" };
        int strSize = 4;

        cout << "\nOriginal string array: ";
        for (int i = 0; i < strSize; ++i) cout << strArr[i] << " ";
        cout << endl;

        InvertArray(strArr, strSize); // Виклик шаблону для string

        cout << "Inverted string array: ";
        for (int i = 0; i < strSize; ++i) cout << strArr[i] << " ";
        cout << endl;

        //Завдання2
        cout << "\nQueue Based on Linked ListЖ" << endl;

        // Тест 1: Черга цілих чисел
        cout << "\n[Test 1] Working with Queue<int>:" << endl;
        Queue<int> intQueue;
        
        cout << "Pushing elements (100, 200, 300)..." << endl;
        intQueue.Push(100);
        intQueue.Push(200);
        intQueue.Push(300);

        intQueue.Print();
        cout << "Current elements count: " << intQueue.GetCount() << endl;

        cout << "Popped element: " << intQueue.Pop() << endl;
        intQueue.Print();
        cout << "Current elements count: " << intQueue.GetCount() << endl;


        // Тест 2: Черга рядків
        cout << "\nWorking with Queue<string>:" << endl;
        Queue<string> stringQueue;

        cout << "Pushing tasks (\"Task1\", \"Task2\", \"Task3\")..." << endl;
        stringQueue.Push("Task1");
        stringQueue.Push("Task2");
        stringQueue.Push("Task3");

        stringQueue.Print();
        cout << "Total tasks in queue: " << stringQueue.GetCount() << endl;

        cout << "Processing (Pop): " << stringQueue.Pop() << endl;
        stringQueue.Print();

    }
    catch (const exception& e) {
        cout << "\n[EXCEPTION CAUGHT]: " << e.what() << endl;
    }
    return 0;
}