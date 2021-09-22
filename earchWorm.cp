//
//  main.cpp
//
//  cppEdu
//
//  Created by Николай Кутузов on 21.09.2021.
//
//__________________________________________________________________________________
//                   Самая сложная задача из ЕГЭ по информатике                     |
//  Постановка задачи:                                                              |
//                                                                                  |
//      Найти максимальную сумму двух чисел, находящихся на расстоянии... а вот     |
//  расстояние задает пользователь! Данные постоянно приходят.                      |
//                                                                                  |
//  Решение:                                                                        |
//                                                                                  |
//      Предположим, что расстояние задано равное 5. Есть вариант решения этой      |
//  с использованием массив. Второй вариант сложнее - БЕЗ использования массива!    |
//                                                                                  |
//      Вариант первый:                                                             |
//                                                                                  |
//  1.  Создаем массив и сохраняем все входные данные                               |
//  2.  Затем берем НУЛЕВОЙ элемент массива и скадываем его с 5, 6, 7, 8... и так   |
//  далее элементами. После всех сложений выбираем максимальную сумму.              |
//  3.  Потом берем ПЕРВЫЙ элемент массива и скадываем его с 6, 7, 8, 9... и так    |
//  далее элементами. После всех сложений выбираем максимальную сумму.              |
//  4.  Берем ВТОРОЙ элемент массива и скадываем его с 7, 8, 9, 10... и так         |
//  ... и так до того, пока вторым слагаемым не станет ПОСЛЕДНИЙ элемент            |
//  5.  Так как в процессе сложений мы запомнили МАКСИМАЛЬНУЮ сумму, см:            |
//              if (pair_sum > max_pair_sum) {                                      |
//                  max_pair_sum  = pair_sum;                                       |
//              }                                                                   |
//  6. Распечатываем результат:                                                     |
//      cout << max_pair_sum << '\n';                                               |
//                                                                                  |
//  int main()                                                                      |
//  {                                                                               |
//      vector<int> A;                                                              |
//      int N = 10;                                                                 |
//      A.resize(N);                                                                |
//      for (int i = 0; i < A.size(); i++) {                                        |
//          cin >> A[i];                                                            |
//      }                                                                           |
//      int max_pair_sum = -1;                                                      |
//      int x, y;                                                                   |
//      for (int i = 0; i < N-1; i++) {                                             |
//        // расстояние между элементами i и k не менее 5                           |
//          for (int k = i + 5; k < N; k++) {                                       |
//              int pair_sum = A[i] + A[k];                                         |
//              if (pair_sum > max_pair_sum) {                                      |
//                  max_pair_sum  = pair_sum;                                       |
//              }                                                                   |
//          }                                                                       |
//      }                                                                           |
//      cout << max_pair_sum << '\n';                                               |
//      return 0;                                                                   |
//  }                                                                               |
//                                                                                  |
//  Решение простое, но требует памяти! Пока чисел мало - ничего страшного. А если  |
//  таковых будет большое количество? Потребуется большой объем оперативной памяти  |
//  Для избежания этого рассмотрим ВТОРОЙ ВАРИАНТ решения этой задачи.              |
//                                                                                  |
//      Вариант второй:                                                             |
//                                                                                  |
//  Идея очень простая. Нам нужно научиться экономить. Фишка в том, чтобы вообще не |
//  запоминать ВЕСЬ ряд чисел.                                                      |
//      Имеется ряд:                                                                |
//                  1   2   3   4   5   6   7   8   9   10  3   2   0   4           |
//      Представим, что через это рад, как дождевой червяк в земле, проходит некий  |
//  буфер, который хранит в себе только количество чисел, равное РАССТОЯНИЮ:        |
//                 [1   2   3   4   5]---->                                         |
//                                      6   7   8   9   10  3   2   0   4           |
//  ШЕСТЕРКУ я буду складывать с ЕДИНИЦЕЙ и проверять                               |
//----------------------------------------------------------------------------------|
//                     [2   3   4   5   6]---->                                     |
//                  1                       7   8   9   10  3   2   0   4           |
//  СЕМЕРКУ я буду складывать уже с ЕДИНИЦЕЙ и ДВОЙКОЙ...                           |
//----------------------------------------------------------------------------------|
//                         [3   4   5   6   7]---->                                 |
//                  1   2                       8   9   10  3   2   0   4           |
//  ВОСЬМЕРКУ я буду складывть уже с ЕДИНИЦЕЙ, ДВОЙКОЙ и ТРОЙКОЙ...                 |
//----------------------------------------------------------------------------------|
//                             [4   5   6   7   8]---->                             |
//                  1   2   3                       9   10  3   2   0   4           |
//  ДЕВЯТКУ - с ЕДИНИЦЕЙ, ДВОЙКОЙ, ТРОЙКОЙ и ЧЕТВЕРКОЙ                              |
//----------------------------------------------------------------------------------|
//                                 [5   6   7   8   9]---->                         |
//                  1   2   3   4                       10  3   2   0   4           |
//  ДЕСЯТКУ - с ЕДИНИЦЕЙ, ДВОЙКОЙ, ТРОЙКОЙ, ЧЕТВЕРКОЙ и ПЯТЕРКОЙ                    |
//  и так далее... НО! Это же нужно запоминать все эти, вышедшие из червяка числа.  |
//  А что если просто запоминать максимальное из вышедших число? ИДЕЯ!              |
//                                                                                  |
//  КАК ЖЕ РЕАЛИЗОВАТЬ ЧЕРВЯКА?                                                     |
//                                                                                  |
//                                   ОЧЕРЕДЬ (QUEIE)                                |
//                        POP----->[5   6   7   8   9]<----- PUSH                   |
//                  1   2   3   4                       10  3   2   0   4           |
//                                                                                  |
//  Очередь на массиве - плохая идея, потому что в ней приходится сдвигать все      |
//  элементы в массиве! Как этого избежать? Идея вот такая:                         |
//                                                                                  |
//  Нужно реализовать ЦИКЛИЧЕСКУЮ очередь, ну как бы заернуть червяка в КОЛЬЦО, как |
//  обойма револьвера.                                                              |
//              схема 1:                                                            |
//                                                                                  |
//                                 [ 7 ]                                            |
//                             /           \                                        |
//                         [ 8 ]           [ 6 ]                                    |
//                                                                                  |
//                              \          /                                        |
//                            [ 4 ]  -  [ 5 ]                                       |
//                            ||/\                                                  |
//                            \/||                                                  |
//                 1   2   3       9   10  3   2   0   4                            |
//                                                                                  |
//              схема 2:                                                            |
//                                 [ 8 ]                                            |
//                             /           \                                        |
//                         [ 9 ]           [ 7 ]                                    |
//                                                                                  |
//                             \           /                                        |
//                            [ 5 ]  -  [ 6 ]                                       |
//                            ||/\                                                  |
//                            \/||                                                  |
//              1   2   3   4      10  3   2   0   4                                |
//                                                                                  |
//  Рассмотрим схематичный пример. На схеме 1 цисло [4] подошло к месту выброса, оно|
//  выходит и тут же на его место встает число [9]. Затем обойма прокручивается см. |
//  схему 2 и все повторяется.                                                      |
//  Как это выглядит на массиве?                                                    |
//                                                                                  |
//                  1   2   3   4   5   6   7   8   9   10  3   2   0   4           |
//  Вначале должна выпрыгнуть ЕДИНИЦА, а запрыгнуть ШЕСТЕРКА                        |
//                                                                                  |
//              [| 1 |  2   3   4   5 ]   6   7   8   9   10  3   2   0   4         |
//               ||/\                    \ /                                        |
//          <=====|||                    | |                                        |
//                 |_=====================_|                                        |
//                                                                                  |
//              [ 6 | 2 |  3   4   5 ]   7   8   9   10  3   2   0   4              |
//                  ||/\                \ /                                         |
//           1 <=====|||                | |                                         |
//                    |_=================_|                                         |
//                                                                                  |
//              [ 6   7  | 3 |  4   5 ]   8   9   10  3   2   0   4                 |
//                       ||/\            \ /                                        |
//          1   2   <=====|||            | |                                        |
//                         |_=============_|                                        |
//                                                                                  |
//  Такой проход по очереди мы будем осуществлять сдвигом индекса элемента в очереди|
//  А когда дойдет до конца этой очереди - не всего списка чисел, а только червя -  |
//  просто обнулим индекс - сделаем снова равным нулю.                              |
//                                                                                  |
//  РАССМОТРИМ ТАКУЮ ЗАДАЧУ, НО УСЛОЖНИМ ЕЕ УСЛОВИЯМИ:                              |
//                                                                                  |
//  1.  РАССМАТРИВАТЬ БУДЕМ НЕ СЛОЖЕНИЕ, А ПРОИЗВЕДЕНИЕ ДВУХ ЧИСЕЛ                  |
//  2.  ЕЩЕ МЫ ЗАДАДИМ УСЛОВИЕ - ЧТО РАССМАТРИВАЮТСЯ ДЛЯ СРАВНЕНИЯ ТОЛЬКО           |
//  ПРОИЗВЕДЕНИЯ, ДАЮЩИЕ В ИТОГЕ НЕЧЕТНЫЕ ЧИСЛА                                     |
//  3.  ВСЕ ДАННЫЕ: КОЛИЧЕСТВО ВХОДЯЩИХ ЧИСЕЛ, САМИ ЧИСЛА, РАЗМЕР ОЧЕРЕДИ (ЧЕРВЯКА) |
//  ПОЛЬЗОВАТЕЛЬ БУДЕТ ВВОДИТЬ С КЛАВИАТУРЫ                                         |
//  4.  ЕСЛИ ТАКАЯ ПАРА НЕ НАШЛАСЬ - БУДЕМ ВЫВОДИТЬ СООТВЕТСТВУЮЩЕЕ СООБЩЕНИЕ       |
//__________________________________________________________________________________|

#include <iostream>

int main(int argc, const char * argv[]) {
    int quantityTotalNumbers; // количество входящих значений
    int range; // размер червяка
    int minOddNumber = 1000;
    int livingNumber; // число, которое покинуло очередь
    int qEnd = 0;   //  конец очереди
    int production = 10000;
    bool flag = false;  // для вывода -1, если не найдется пары
    // общее количество входящих чисел
    std::cout << "Введите количество чисел: ";
    std::cin >> quantityTotalNumbers;
    //задаем размер червяка
    std::cout << "Введите размер очереди(червяка): ";
    std::cin >> range;
    int earthWorm [range]; // сам червяк
    // Заполним червяка
    for (int i = 0; i < range; ++i) {
        std::cout << "Введите " << i + 1 << " число из "
                << quantityTotalNumbers << " : ";
        std::cin >> earthWorm[i];
    }
    //проходим по дальнейшим числам и вытаскиваем/засовываем их из/в червяка
    for (int i = range; i < quantityTotalNumbers; ++i) {
        int currentNumber;
        std::cout << "Введите " << i + 1 << " число из "
                << quantityTotalNumbers << " : ";
        std::cin >> currentNumber;
        livingNumber = earthWorm[qEnd];
        earthWorm[qEnd++] = currentNumber;
        //  Если индекс элемента в числе превышает размер червяка
        if (qEnd > range)
            // обнуляем индекс - переводим на начало червяка
            qEnd = 0;
        //ищем минималное нечетное число
        if (livingNumber % 2 != 0 and livingNumber < minOddNumber) {
            minOddNumber = livingNumber;
        }
        //ищем минимальное произведение
        if (currentNumber % 2 != 0 and minOddNumber * currentNumber < production) {
            production = minOddNumber * currentNumber;
            flag = true;
        }
    }
    if (flag)
        // если пара нашлась, выводим МАКСИМАЛЬНУЮ из возможных сумму
        std::cout << "Произведение = " << production << std::endl;
    else
        // если пары не нашлось - вы
        std::cout << "Пары не нашлось!\n";
    
        return 0;
}
