//
//  main.cpp
//
//  cppEdu
//
//  Created by Николай Кутузов on 10.09.2021.
//
//__________________________________________________________________________________
//                                                                                  |
//                                 ЛИНЕЙНЫЙ ПОИСК                                   |
//                                                                                  |
//      Поиск элемента в массиве, линейно перебирая все элементы массива. А какой   |
//  результат будет возвращен? Мне видится только два варианта:                     |
//  1.  Возвращается просто ответ - есть таковой элемент или нет true/false         |
//  2.  Возвращается индекс найденного (первого найденного или полседнего - это как |
//  поставить задачу) или отрицательный индекс, если такового элемента нет.         |
//                                                                                  |
//      ПОСТАНОВКА ЗАДАЧИ:                                                          |
//                                                                                  |
//  Рассмотрим второй вариант с одной оговоркой - мы будем возвращать ПЕРВЫЙ ИНДЕКС.|
//  Все просто - мы пробегаем по массиву и как только встречаем индекс с элементом, |
//  равным искомому, возвращаем номер индекса, в котором это значение хранится.     |
//  Если искомое не находится, то возвращаем отрицательный индекс, в нашем случае -1|
//                                                                                  |
//                                                                                  |
//__________________________________________________________________________________|


#include <iostream>

//  прототипы функций
void printArr(int arr[], int arrLength);
int enterDesiredNumber();
int lineSearch(int arr[], int arrLength, int desiredNumber);
void printResult(int desiredNumber, int findedIndex);

int main(int argc, const char * argv[]) {
    int arr[] { 1, 3, 3, 7, 7, 7, 7, 9, 6, 4 };
    int arrLength = sizeof(arr) / sizeof(arr[0]);
    
    printArr(arr, arrLength);
    
    int desiredNumber = enterDesiredNumber();
    
    printResult (desiredNumber, lineSearch(arr, arrLength, desiredNumber));
    
    return 0;
}

//  реализация функций
void printArr(int arr[], int arrLength) {
    for (int i = 0; i < arrLength; ++i)
        std::cout << ' ' << i << "  ";
    std::cout << std::endl;
    
    for (int i = 0; i < arrLength; ++i)
        std::cout << "[" <<arr[i] << "]" << ' ';
    std::cout << std::endl;
}

int enterDesiredNumber() {
    std::cout << "Enter the desired number: ";
    int desiredNumber;
    std::cin >> desiredNumber;
    return desiredNumber;
}

int lineSearch(int arr[], int arrLength, int desiredNumber) {
    for (int i = 0; i < arrLength; ++i)
        if (arr[i] == desiredNumber)
            return i;
    return -1;
}

void printResult (int desiredNumber, int findedIndex) {
    if (findedIndex == -1) {
        std::cout << "The desired number [" << desiredNumber << "] is not found!";
        std::cout << std::endl;
    } else {
    std::cout << "First (maybe only one) index of the desired number ["
            << desiredNumber << "] is: " << findedIndex;
    std::cout << std::endl;
    }
}
