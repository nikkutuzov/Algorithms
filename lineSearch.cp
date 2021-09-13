//
//  main.cpp
//
//  cppEdu
//
//  Created by Николай Кутузов on 10.09.2021.
//
// Линейный поиск

#include <iostream>

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
