//
//  main.cpp
//
//  cppEdu
//
//  Created by Николай Кутузов on 13.09.2021.
//
//__________________________________________________________________________________
//                          РЕКУРСИЯ на алгоритма Евклида.                          |
//  Нахождение Наибольшего Общего Делителя. НОД(a, b) - если а != 0, а b = 0, тогда |
//  а и есть НОД. Если b > a, a != 0, тогда НОД(b - a, a). Если a > b, тогда        |
//  НОД(a - b, b)Можно упростить и делать НОД(b, a % b).                            |
//  Можно быть уверенным, что a % b всегда меньше b, например, a = 2, b = 5,        |
//  тогда 2 % 5 = 2, а если (b > a) -> a = 5, b = 2, то 5 % 2 = 1, что 2, что       |
//  1 - оба меньше 5. Значит справедливо считать НОД((5, (2 % 5 = 2)) - правильно.  |
//  При этом главное правило: b != 0                                                |
//  В итоги имеем:                                                                  |
//                  | НОД(b, a % b), при b != 0                                     |
//     НОД(a, b) = <                                                                |
//                  |  a, при b = 0                                                 |
//                                                                                  |
//  Реализация на с++:                                                              |
//                                                                                  |
//  Можно использовать тривиальное решение:                                         |
//  int gcd(int a, int b) {                                                         |
//      if (b == 0)                                                                 |
//          return a;                                                               |
//      else                                                                        |
//          return gcd(b, a % b);                                                   |
//  }                                                                               |
//                                                                                  |
//  А можно воспользоваться тернарным орератором                                    |
//  int gcd(int a, int b) {                                                         |
//      return (b == 0) ? a : gcd(b, a % b);                                        |
//  }     ^       ^       ^ ^       ^                                               |
//  Вернуть (если b == 0) а иначе gcd(b, a % b);                                    |
//__________________________________________________________________________________|

#include <iostream>

// Объявление функции
int gcd(int firstNumber, int secondNumber);

int main(int argc, const char * argv[]) {
    int firstNumber;
    int secondNumber;
    std::cout << "Введите первое число: ";
    std::cin >> firstNumber;
    std::cout << "Введите второе число: ";
    std::cin >> secondNumber;

    std::cout << "НОД(" << firstNumber << ", " << secondNumber
            << ") равен " << gcd(firstNumber, secondNumber) << '\n';

    return 0;
}

int gcd(int firstNumber, int secondNumber) {
    return (secondNumber == 0) ? firstNumber : gcd(secondNumber, firstNumber % secondNumber);
}
