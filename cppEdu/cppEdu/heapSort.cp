//
//  main.cpp
//  cppEdu
//
//  Created by Николай Кутузов on 23.08.2021.
//

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

// создаем синоним типа
typedef int heapData_t; // heapData_t - тип элемента в куче
// делается это для удобства, например: сейчас мне нужно, чтобы
// в куче были int'ы, а если вдруг я захочу чтобы были строки,
// я ТОЛЬКО ТУТ поменяю int на std::string
//
//-------------------------------------------------------------
//
// создаем прототипы функции
//

// ввод списка значений без терминального элемента
// из одной строки с разделителем - пробелом
std::vector<heapData_t> inputVector();

// пирамидальная сортировка массива
void heapSort(std::vector<heapData_t> &arr);

// распечатка вектора
void printVector(const std::vector<heapData_t> &arr);

int main(int argc, const char * argv[]) {
// создаем вектор
    std::vector<heapData_t> arr = inputVector();
// сортируем вектор
    heapSort(arr);
// распечатываем вектор
    printVector(arr);
    
    return 0;
}

//
// РЕАЛИЗАЦИИ ФУНКЦИЙ
//

std::vector<heapData_t> inputVector() {
    std::string line;
    getline(std::cin, line);
    std::stringstream lineStream(line);
    std::vector<heapData_t> arr;
    while (not lineStream.eof()) {
        heapData_t x;
        lineStream >> x;
        arr.push_back(x);
    }
    
    return arr;
}

void heapSort(std::vector<heapData_t> &arr) {
// если размер массива 1 - сортировать не нужно
// если размер массива 0 - его нет
// меньше 0 не может быть
    if (arr.size() <= 1) return;
    
    for (size_t k = 1; k < arr.size(); ++k) {
// подъем очередного элемента наверх
        size_t currentIndex = k;
        size_t parentIndex =(currentIndex - 1) / 2;
        while (currentIndex != 0 and arr[currentIndex] > arr[parentIndex]) {
            std::swap(arr[currentIndex], arr[parentIndex]);
            currentIndex = parentIndex;
            parentIndex = (currentIndex - 1) / 2;
       }
    }
    for (size_t top = (arr.size() - 1); top > 0; --top) {
        std::swap(arr[0], arr[top]); // последний наверх, макимальный - в конец
        
        size_t currentIndex = 0;             // текущий элемент
        size_t left = 2 * currentIndex + 1;  // левый дочерний
        size_t right = 2 * currentIndex + 2; // правый дочерний
            
        // автоматически, так как уже проверяли в условии входа
        // в цикл, что левый дочерний существует и он больше текущего или
        // правый дочерний существует и он больше текучего
        while (((left < top) and (arr[left] > arr[currentIndex])) or
               ((right < top) and (arr[right] > arr[currentIndex]))) {
                
            // правого элемента не существует или левый больше правого
            if ((right >= top) or (arr[left] > arr[right])) { //оп. or - ленивый!!!
                std::swap(arr[left], arr[currentIndex]);
                currentIndex = left;
            } else {
                std::swap(arr[right], arr[currentIndex]);
                currentIndex = right;
            }
            left = 2 * currentIndex + 1;
            right = 2 * currentIndex + 2;
        }
    }
}

void printVector(const std::vector<heapData_t> &arr) {
    for (auto &x: arr) {
        std::cout << x << ' ';
    }
    std::cout << '\n';
}
