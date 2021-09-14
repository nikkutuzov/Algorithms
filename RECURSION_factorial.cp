//
//  main.cpp
//
//  cppEdu
//
//  Created by Николай Кутузов on 12.09.2021 - 13.09.2021.
//
//__________________________________________________________________________________
//                       РЕКУРСИЯ на примере факториала!                            |
//      Вообще нужно учесть, что вычислять факториал рекурсией - это не очень       |
//  хорошая идея, но для учебного примера вполне сойдет.                            |
//      Что же такое факториал? Для факториала верна следующая функция:             |
//                                 x! = 1 * 2 * 3 * 4 *...* x                       |
//      но можно сказать, что      x! = (x - 1)! * x                                |
//      если выразить как функцию: f(x) = f(x - 1) * x                              |
//                                                                                  |
//  Небольшое дополнение. Факториал как бы показывает нам сколько вариантов есть    |
//  разместить х предметов в х позициях. Например, 2! - это сколько способов есть,  |
//  чтобы расставить два предмета в двух позициях   1 и 2 - либо 1  2 либо 2  1     |
//                                                               ^  ^      ^  ^     |
//                                                              [1][2]    [1][2]    |
//                                                          и получаем, что 2! = 2  |
//  3! -  3 предмета, 3 позиции:                                                    |
//  либо 1  2  3 или 1  3  2 или 2  1  3, либо 2  3  1 или 3  1  2 или 3  2  1      |
//       ^  ^  ^     ^  ^  ^     ^  ^  ^       ^  ^  ^     ^  ^  ^     ^  ^  ^      |
//      [1][2][3]   [1][2][3]   [1][2][3]     [1][2][3]   [1][2][3]   [1][2][3]     |
//                                                                                  |
//  Как видно, есть ШЕСТЬ способов, то есть 3! = 6                                  |
//  Сколькими способами тогда можно расставить 1 предмет в одной позиции? - 1! = 1  |
//  А вот 0! = 1 - просто по определению!                                           |
//                                                                                  |
//                                                                                  |
//  РЕЗУЛЬТАТ ВЫПОЛНЕНИЯ ПРОГРАММЫ:                                                 |
//  Введите число для нахождения факториала: 5                                      |
//  Факториал числа [5] равен:                                                      |
//  factorial(5) is called.                                                         |
//  factorial(4) is called.                                                         |
//  factorial(3) is called.                                                         |
//  factorial(2) is called.                                                         |
//  factorial(1) is called.                                                         |
//  factorial(0) is called.                                                         |
//  factorial(0) is exitting.                                                       |
//  factorial(1) is exitting.                                                       |
//  factorial(2) is exitting.                                                       |
//  factorial(3) is exitting.                                                       |
//  factorial(4) is exitting.                                                       |
//  factorial(5) is exitting.                                                       |
//  120                                                                             |
//                                                                                  |
//  ЧТО ЖЕ ПРОИСХОДИТ?                                                              |
//  Функции вызываются СИНХРОННО! Когда вызывается функция из финкции - подпрограмма|
//  из подпрограммы - первая функция не перестает сужествовать и выполняться в том  |
//  смысле, что ее локальные переменные продолжают жить. Под переменные выделяются  |
//  ресурсы.                                                                        |
//  Рассмотрим СТЕК - служебную память компьютерной программы.                      |
//  Функция А вызывает (=>) функцию В, а она вызывает (=>) функцию С                |
//  Таймлайн выполнения:                                                            |
//  функия main() запустила     А(),                                                |
//  она начинает выполняться    *                                                   |
//  и в какой-то момент в ее    |                                                   |
//  тексте встречается вызов    |                                                   |
//  В() и...                    |   call <- вызов функцИИ В() функциЕЙ А()          |
//  ..она начинает выполняться->В()-------* <- В() начинает выполняться             |
//                                        |                                         |
//  функция А() как бы засыпает           | функция В() выполняется и...            |
//                                        |   call <- вызов функцИИ С() функциЕЙ В()|
//  ...в тексте В() встречается С() ----->C()-------* <- С() начинает выполняться   |
//                                                  |                               |
//          функция В() как бы засыпает             |                               |
//                                           return |                               |
//                                        x---------x <- С() завершает выполниение  |
//                                 return | будит В()  и возвращает результат в В() |
//                              x---------x <- B() завершает выполниение            |
//                       return | будит А()   и возвращает результат в A()          |
//               main()<--------x <- A()  возвращает результат в main()             |
//                                                                                  |
//                                  СТЕК STACK                                      |
//      прямой путь рекурсии                        обратный путь рекурсии          |
//                                                                                  |
//                     переходим от прямого пути к обратному                        |
//       |>===========================================================>|            |
//       ||      ................................................     ||            |
//       ||     |                                                |    \/            |
//       /\     |                                                |    ||            |
//       ||     |                                                |    ||            |
// Stack Pointer поднимается сюда|_______________________|1.1Функция С() заканчивает|
//       ||     |        функция С() выделяет память под | свое выполнение, делает  |
//       ||     |           СВОИ ЛОКАЛЬНЫЕ ПЕРЕМЕННЫЕ    | return в функцию B() и   |
//       ||     |                                        | выкидывает лок. перем.   |
//       ||     |________________________________________________|    ||            |
// С() кладет на Stack состояние базового ук-ля base pointer'а,  |3.1Восстанавливает|
//       ||     | который указывает на старое состояние базового | базовый указатель|
//       ||     |       указателя регистра процессора            | Снимает АДРЕС    |
//       ||     |________________________________________________| ВОЗВРАТА и..     |
// функция C() начинает работать|________________________________|    ||            |
//       ||     | автоматически падает АДРЕС ВОЗВРАТА в то место |    ||            |
//       ||     | откуда был вызов - нужно знать куда вернуться  |    ||            |
// функция В() засыпает|_________________________________________.будит функцию B() |
//       ||     |       функция В() выделяет память под  | Память высвобождается    |
//       ||     |           ПАРАМЕТРЫ для функции С()    | сразу после того, как С()|
//       ||     |                                        | выполнила return         |
//       ||     |________________________________________________|    ||            |
//       ||     |  функция B() выделяет память под ВОЗВРАЩАЕМОЕ | 2.1 Функция С()   |
//       ||     |              ЗНАЧЕНИЕ функции C()             | вернула результат |
//       ||     |         ______________________________________| После того как B()|
//       ||     |        | забрала возвращенный результат эта память высвобождается |
//       ||     |________________________________________________|    ||            |
// Stack Pointer поднимается сюда|_______________________|1.2Функция В() заканчивает|
//       ||     |        функция В() выделяет память под | свое выполнение, делает  |
//       ||     |           СВОИ ЛОКАЛЬНЫЕ ПЕРЕМЕННЫЕ    | return в функцию A() и   |
//       ||     |                                        | выкидывает лок. перем.   |
//       ||     |________________________________________________|    ||            |
// В() кладет на Stack состояние базового ук-ля base pointer'а,  |3.2Восстанавливает|
//       ||     | который указывает на старое состояние базового | базовый указатель|
//       ||     |       указателя регистра процессора            | Снимает АДРЕС    |
//       ||     |________________________________________________| ВОЗВРАТА и..     |
// функция В() начинает работать|________________________________|    ||            |
//       ||     | автоматически падает АДРЕС ВОЗВРАТА в то место |    ||            |
//       ||     | откуда был вызов - нужно знать куда вернуться  |    ||            |
// функция А() засыпает|_________________________________________|.будит функцию A()|
//       ||     |        функция А() выделяет память под | Память высвобождается    |
//       ||     |           ПАРАМЕТРЫ для функции В()    | сразу после того, как B()|
//       ||     |                                        | выполнила return         |
//       ||     |________________________________________________|    ||            |
//       ||     |  функция А() выделяет память под ВОЗВРАЩАЕМОЕ | 2.2 Функция B()   |
//       ||     |              ЗНАЧЕНИЕ функции В()             | вернула результат |
//       ||     |         ______________________________________| После того как А()|
//       ||     |        | забрала возвращенный результат эта память высвобождается |
// Stack Pointer|________________________________________________|    ||            |
//       ||     |  base pointer - состояние куда нужно вернуться |    \/            |
//     НАЧАЛО   |................................................|   КОНЕЦ          |
//__________________________________________________________________________________|

#include <iostream>

// Объявление функции (мой вариан - см. ниже)
// uint64_t factorial(uint16_t inputNumber);

//  Вариант для того, чтобы видеть как вызываются функции из функции:
int64_t factorial(int16_t inputNumber)
{
    std::cout << "factorial(" << inputNumber << ") is called. \n";
    int64_t result;
    if (inputNumber == 0) {  // base case:
        result = 1;
    } else {       // recurrent case:
        result = factorial(inputNumber - 1) * inputNumber;
    }
    std::cout << "factorial(" << inputNumber << ") is exitting.\n";
    
    return result;
}

int main(int argc, const char * argv[]) {
    std::cout << "Введите число для нахождения факториала: ";
//  Число будет положительным и маленьким, но будет использовать не uint8_t -
//  оно плохо считывается, а именно воспринимается как символ, а не число.
//  Будем использовать uint16_t
    uint16_t inputNumber;
    std::cin >> inputNumber;
    
    std::cout << "Факториал числа [" << inputNumber
            << "] равен: " << factorial(inputNumber);
    std::cout << std::endl;
    
    return 0;
}

/*      МОЙ ВАРИАНТ
//  Функция будет возвращать достаточно большое и положительное число
//  Для выхода из рекурсии нам нужен крайний случай!
uint64_t factorial(uint16_t inputNumber) {
    if (inputNumber == 0) {     // крайний случай (0! = 1 - по определению)
        return 1;
    } else {                    // рекуррентный случай
    return factorial(inputNumber - 1) * inputNumber;
    }
}
*/
