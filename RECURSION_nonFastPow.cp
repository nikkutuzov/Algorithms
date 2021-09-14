//
//  main.cpp
//  cppEdu
//
//  Created by Николай Кутузов on 13.09.2021.
//
//__________________________________________________________________________________
//                  РЕКУРСИЯ на НЕбыстрого возведения в степень.                    |
//                                                                                  |
//  Постановка задачи:                                                              |
//  Есть число a, которое нужно возвести в степень n. Первое, что приходит в голову |
//  1 * a * a * a... и так n раз. Ну как-то не очень :(                             |
//                                                                                  |
//  Можно попробовать решить рекуррентно:                                           |
//  тогда имеем:                                                                    |
//                        | a^0 = 1             // если n = 0                       |
//                  a^n = | a * (a^(n - 1))     // если n > 0                       |
//                        | значок "^" - возвести в степень                         |
//__________________________________________________________________________________|

#include <iostream>

// объявление функции НЕбыстрого возведения в степень
double nonFastPOW(double inputNumber, int power);

int main(int argc, const char * argv[]) {
    std::cout << "Введите число, которое нужно возвести в степень: ";
        double inputNumber;
        std::cin >> inputNumber;
        std::cout << "Введите степень, в которую нужно возвести число: ";
        int power;
        std::cin >> power;

        std::cout << "Число " << inputNumber << " в степени " <<
               power << " равно " << nonFastPOW(inputNumber, power);
        std::cout << std::endl;
    
    return 0;
}

double nonFastPOW(double inputNumber, int power){
    if (power == 0) {
        return 1;
    } else {
        return nonFastPOW(inputNumber, power - 1) * inputNumber;
    }
}
