#ifndef SORT
#define SORT
#include "stringProcessor.h"
#include <string.h> // Для strcmp

// Функція обміну двох вказівників на рядки
void swap(char** a, char** b)
{
    char* temp = *a;
    *a = *b;
    *b = temp;
}

// Допоміжна функція для QuickSort (розбиття масиву)
int partition(char** arr, int low, int high)
{
    char* pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        // Порівняння рядків лексикографічно
        if (strcmp(arr[j], pivot) < 0)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Рекурсивна функція QuickSort
void quick_sort_recursive(char** arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quick_sort_recursive(arr, low, pi - 1);
        quick_sort_recursive(arr, pi + 1, high);
    }
}

// Основна функція-обгортка (щоб відповідати сигнатурі в завданні)
void quick_sort(char** arr, size_t length)
{
    if (length > 0) {
        quick_sort_recursive(arr, 0, (int)length - 1);
    }
}
#endif // !SORT