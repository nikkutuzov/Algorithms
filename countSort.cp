//
//  main.cpp
//  cppEdu
//
//  Created by Николай Кутузов on 10.09.2021.
//
//__________________________________________________________________________________
//                                                                                  |
//                          Сортировка подсчетом count sort                         |
//                                                                                  |
//      Основная идея заключается в следующем: допустим, имеется ряд:               |
//                                                                                  |
//              1   5   2   3   2   2   5   2   3   1   3   0   3                   |
//                                                                                  |
//      Делаем следующее:                                                           |
//  считаем сколько у нас штук каждых элементов                                     |
//  0 - 1 штука        можем              key[0] = 1                                |
//  1 - 2 штуки     представить           key[1] = 2                                |
//  2 - 5 штук         их как             key[2] = 5                                |
//  3 - 4 штуки       массив с            key[3] = 4                                |
//  4 - 0 штук        числами             key[4] = 0                                |
//  5 - 4 штуки                           key[5] = 4                                |
//                                                                                  |
//  После этого нам остается пробижаться по массиву и распечатать НОЛЬ один раз,    |
//  ЕДИНИЦУ два раза, ДВОЙКУ пять раз, ТРОЙКУ четыре раза, ЧЕТВЕРКУ ноль раз и      |
//  ПЯТЕРКУ четыре раза.                                                            |
//                                                                                  |
//  Асимптотика очень хорошая, если числа расположены компактно - O(N)              |
//                                                                                  |
//  НО! Если вдруг у нас будет вот, например, такой ряд, то нам нужно более         |
//  2 миллионов (2'345'678 + 1) счетчиков (ключей):                                 |
//                          76  5   2'345'678                                       |
//  Асимптотика сразу возрастает до O(N + M), где М - количество ключей (key)       |
//                                                                                  |
//__________________________________________________________________________________|

#include <iostream>
#include <cstdlib>              // для rand()

void countSort(int arr[], int arrLength, int numberLimit);
void printArray(int arr[], int arrLength);
void generateRandomArray(int arr[], int arrLength, int numberLimit);

int main(int argc, const char * argv[]) {
    std::cout << "Введите размер массива: ";
    int arrLength;
    std::cin >> arrLength;
    int arr[arrLength];
    std::cout << "Введите предел максимального генерируемого числа: ";
    int numberLimit;
    std::cin >> numberLimit;
    
//  генерируем случайный массив (+ 1 - чтобы макс. число включить)
    generateRandomArray(arr, arrLength, numberLimit + 1);
//  распечатываем случайно сгенерированный массив
    printArray(arr, arrLength);
//  сортируем массив (+ 1 - чтобы макс. число включить)
    countSort(arr, arrLength, numberLimit + 1);
// распечатываем отсортированный массив
    printArray(arr, arrLength);
    
    return 0;
}

//  генерируем случайный массив из целых чисел
void generateRandomArray(int arr[], int arrLength, int numberLimit) {
    for (int i = 0; i < arrLength; ++i) {
        arr[i] = rand() % numberLimit;
    }
}

//  сортируем массив методом сортировки подсчетом
void countSort(int arr[], int arrLength, int numberLimit) {
    int key[numberLimit];                         // создаем массив ключей
    for (int i = 0; i < numberLimit; ++i) {       // инициализируем нулями
        key[i] = 0;
    }
    for (int i = 0; i < arrLength; ++i) {       // собираем частоты - сколько раз
        key[arr[i]]++;                          // встречалось определенное число
    }
    int i = 0;
    for (int x = 0; x < numberLimit; ++x) {     // перебираю всевозможные значения
                                                // ключей (их numberLimit штук)
        for (int k = 0; k < key[x]; ++k) {      // сколько раз распечатать число
            arr[i] = x;                         // это значение храниться в key[x]
            i++;
        }
    }
}

//  распечатываем массив: отсортированный
//  или еще не отсортированный - все зависит
//  от места вызова функции!
void printArray(int arr[], int arrLength) {
    for (int i = 0; i < arrLength; ++i) {
        std::cout << arr[i] << '\t';
    }
    std::cout << std::endl;
}
