//
//  main.cpp
//  cppEdu
//
//  Created by Николай Кутузов on 08.10.2021.
//
//__________________________________________________________________________________
//                                                                                  |
//                   ОДНОМЕРНОЕ ДИНАМИЧЕСКОЕ ПРОГРАММИРОВАНИЕ                       |
//                                                                                  |
//      Делов в том, что рекурсия очень ресурсоемка (это утверждение не совсем от-  |
//  носится к функциональному программированию) - требуется много повторных вычис-  |
//  лений. Рассмотрим разницу между рекуррентным решением и динамическим программи- |
//  рованием на примере чисел Фибоначчи (Леонардо Пизанский).                       |
//                                                                                  |
//      Из листинга видно, что главное отличие состоит в том, что в рекуррентном    |
//  случае мы погружаемся в рекурсию на глубину count и оттуда идем к крайнему      |
//  случаю.                                                                         |
//      В случае динамического программирования все наоборот: мы идем от крайнего   |
//  случая до того момента, пока не закончится count. ОБРАЩАЕМ ВНИМАНИЕ НА СКОРОСТЬ |
//  ВЫПОЛНЕНИЯ В ОБОИХ СЛУЧАЯХ! Для тех кому лень компилировать - динамическое вы-  |
//  числение НАМНОГО ПРЕВОСХОДИТ в скорости рекуррентное.                           |
//__________________________________________________________________________________|

#include <iostream>
#include <cassert>

// объявление функций
uint64_t recursiveFibonacci(int inputNumber);
uint64_t dynamycFibonacci(int inputNumber);

int main(int argc, const char * argv[]){
    
    const int endOfCount  = 47;
    // распечатываем рекуррентный подсчет чисел Фибоначчи
    for (int count = 0; count <= endOfCount; ++count) {
        std::cout << count << '\t' << "Recursive: "
                << recursiveFibonacci(count) << std::endl;
    }
    // распечатываем динамический подсчет чисел Фибоначчи
    for (int count = 0; count <= endOfCount; ++count) {
        std::cout << count << '\t' << "Dynamic: "
                << dynamycFibonacci(count) << std::endl;
    }
    return 0;
}

// определение функций

uint64_t recursiveFibonacci(int inputNumber){
    // гарантируем...
    assert(inputNumber >= 0);
    
    if (inputNumber == 0 or inputNumber == 1) { // крайний случай рекурсии
        return inputNumber;
    } else {                // рекуррентный случай
        return recursiveFibonacci(inputNumber - 1)
            + recursiveFibonacci(inputNumber - 2);
    }
}

uint64_t dynamycFibonacci(int inputNumber){
    // объявим переменную, содержащую результат
    uint64_t result;
    // выделяем память под массив ...
    uint64_t *fibonacci  = new uint64_t[inputNumber + 1]; // +1, чтобы номер
                                            // индекса БЫЛ РАВЕН inputNumber
    
    // крайние случаи заполним вручную:
    fibonacci[0] = 0;
    fibonacci[1] = 1;
    
    // начинаем вычесление чисел Фибоначчи, начиная с ТРЕТЬЕГО,
    // первое и второе мы указали вручную выше
    for (int index = 2; index <= inputNumber; ++index) {
        // вычисляем СЛЕДУЮЩЕЕ число, опираясь на предыдущие УЖЕ ВЫЧЕСЛЕННЫЕ!
        fibonacci[index] = fibonacci[index - 1] + fibonacci[index - 2];
    }
    
    result = fibonacci[inputNumber];
    // высвобождаем память
    delete [] fibonacci;
    
    return result;
}
