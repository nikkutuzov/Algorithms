//
//  main.cpp
//  cppEdu
//
//  Created by Николай Кутузов on 14.09.2021.
//
//__________________________________________________________________________________
//                РЕКУРСИЯ на примере НЕбыстрого возведения в степень.              |
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
//                                                                                  |
//  Рассмотрим пример: 2 в степени 15:                                              |
//  2^15 -> 2^14 -> 2^13 ->2^12 -> 2^11 -> 2^10 ->2^9 ->                            |
//  2^8 -> 2^7 ->2^6 -> 2^5 -> 2^4 -> 2^3 ->2^2 -> 2^1 -> 2^0                       |
//                                                                                  |
//  Функция:                                                                        |
//                                                                                  |
//  double nonFastPOW(double inputNumber, int power){                               |
//      if (power == 0) {                                                           |
//          return 1;                                                               |
//      } else {                                                                    |
//          return nonFastPOW(inputNumber, power - 1) * inputNumber;                |
//      }                                                                           |
//  }                                                                               |
//                                                                                  |
//  Как все происходит под капотом?                                                 |
//  Функция main() вызывает nonfastPow(2,15) -> идет проверка(15 != 0) ->           |
//  функция nonfastPow(2, 15) выполняет->                                           |
//  ->return nonfastPow(2, 15 - 1)*2 -> call nonFastPow(2, 14)->проверка(14 != 0) ->|
//  функция nonfastPow(2, 14) выполняет->                                           |
//  ->return nonfastPow(2, 14 - 1)*2 -> call nonFastPow(2, 13)->проверка(13 != 0) ->|
//  функция nonfastPow(2, 13) выполняет->                                           |
//  ->return nonfastPow(2, 13 - 1)*2 -> call nonFastPow(2, 12)->проверка(12 != 0) ->|
//  функция nonfastPow(2, 12) выполняет->                                           |
//  ->return nonfastPow(2, 12 - 1)*2 -> call nonFastPow(2, 11)->проверка(11 != 0) ->|
//  функция nonfastPow(2, 11) выполняет->                                           |
//  ->return nonfastPow(2, 11 - 1)*2 -> call nonFastPow(2, 10)->проверка(10 != 0) ->|
//  функция nonfastPow(2, 10) выполняет->                                           |
//  ->return nonfastPow(2, 10 - 1)*2 -> call nonFastPow(2, 9)->проверка(9 != 0) ->  |
//  функция nonfastPow(2, 9) выполняет->                                            |
//  ->return nonfastPow(2, 9 - 1)*2 -> call nonFastPow(2, 8)->проверка(8 != 0) ->   |
//  функция nonfastPow(2, 8) выполняет->                                            |
//  ->return nonfastPow(2, 8 - 1)*2 -> call nonFastPow(2, 7)->проверка(7 != 0) ->   |
//  функция nonfastPow(2, 7) выполняет->                                            |
//  ->return nonfastPow(2, 7 - 1)*2 -> call nonFastPow(2, 6)->проверка(6 != 0) ->   |
//  функция nonfastPow(2, 6) выполняет->                                            |
//  ->return nonfastPow(2, 6 - 1)*2 -> call nonFastPow(2, 5)->проверка(5 != 0) ->   |
//  функция nonfastPow(2, 5) выполняет->                                            |
//  ->return nonfastPow(2, 5 - 1)*2 -> call nonFastPow(2, 4)->проверка(4 != 0) ->   |
//  функция nonfastPow(2, 4) выполняет->                                            |
//  ->return nonfastPow(2, 4 - 1)*2 -> call nonFastPow(2, 3)->проверка(3 != 0) ->   |
//  функция nonfastPow(2, 3) выполняет->                                            |
//  ->return nonfastPow(2, 3 - 1)*2 -> call nonFastPow(2, 2)->проверка(2 != 0) ->   |
//  функция nonfastPow(2, 2) выполняет->                                            |
//  ->return nonfastPow(2, 2 - 1)*2 -> call nonFastPow(2, 1)->проверка(1 != 0) ->   |
//  функция nonfastPow(2, 1) выполняет->                                            |
//  ->return nonfastPow(2, 1 - 1)*2 -> call nonFastPow(2, 0)->проверка(0 == 0) ->   |
//  ->функция nonFastPow(2,0) после проверки делает возврат в вызвавщую ее функцию->|
//  ->return 1 в nonfastPow(2, 1) -> 1 * 2 = 2 ->                                   |
//  Функция nonFastPow(2,1) делает возврат в вызвавщую ее функцию ->                |
//  ->return 2 в nonfastPow(2, 2) -> 2 * 2 = 4 ->                                   |
//  Функция nonFastPow(2,2) делает возврат в вызвавщую ее функцию ->                |
//  ->return 4 в nonfastPow(2, 3) -> 4 * 2 = 8 ->                                   |
//  Функция nonFastPow(2,3) делает возврат в вызвавщую ее функцию ->                |
//  ->return 8 в nonfastPow(2, 4) -> 8 * 2 = 16 ->                                  |
//  Функция nonFastPow(2,4) делает возврат в вызвавщую ее функцию ->                |
//  ->return 16 в nonfastPow(2, 5) -> 16 * 2 = 32 ->                                |
//  Функция nonFastPow(2,5) делает возврат в вызвавщую ее функцию ->                |
//  ->return 32 в nonfastPow(2, 6) -> 32 * 2 = 64 ->                                |
//  Функция nonFastPow(2,6) делает возврат в вызвавщую ее функцию ->                |
//  ->return 64 в nonfastPow(2, 7) -> 64 * 2 = 128 ->                               |
//  Функция nonFastPow(2,7) делает возврат в вызвавщую ее функцию ->                |
//  ->return 128 в nonfastPow(2, 8) -> 128 * 2 = 256 ->                             |
//  Функция nonFastPow(2,8) делает возврат в вызвавщую ее функцию ->                |
//  ->return 256 в nonfastPow(2, 9) -> 256 * 2 = 512 ->                             |
//  Функция nonFastPow(2,9) делает возврат в вызвавщую ее функцию ->                |
//  ->return 512 в nonfastPow(2, 10) -> 512 * 2 = 1024 ->                           |
//  Функция nonFastPow(2,10) делает возврат в вызвавщую ее функцию ->               |
//  ->return 1024 в nonfastPow(2, 11) -> 1024 * 2 = 2048 ->                         |
//  Функция nonFastPow(2,11) делает возврат в вызвавщую ее функцию ->               |
//  ->return 2048 в nonfastPow(2, 12) -> 2048 * 2 = 4096 ->                         |
//  Функция nonFastPow(2,12) делает возврат в вызвавщую ее функцию ->               |
//  ->return 4096 в nonfastPow(2, 13) -> 4096 * 2 = 8192 ->                         |
//  Функция nonFastPow(2,13) делает возврат в вызвавщую ее функцию ->               |
//  ->return 8192 в nonfastPow(2, 14) -> 8192 * 2 = 2 -> 16384                      |
//  Функция nonFastPow(2,14) делает возврат в вызвавщую ее функцию ->               |
//  ->return 16384 в nonfastPow(2, 15) -> 16384 * 2 = 32768 ->                      |
//  Функция nonFastPow(2,15) делает возврат в вызвавщую ее функцию ->               |
//  ->return 32768 в main()                                                         |
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
