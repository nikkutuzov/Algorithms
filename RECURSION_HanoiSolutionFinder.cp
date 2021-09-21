//
//  main.cpp
//
//  cppEdu
//
//  Created by Николай Кутузов on 21.09.2021.
//
//__________________________________________________________________________________
//                  РЕКУРСИЯ на примере Задачи о Ханойских Башнях.                  |
//                              РЕКУРСИЯ С ВЕТВЛЕНИЕМ                               |
//                                                                                  |
//  Постановка задачи:                                                              |
//                                                                                  |
//  Имеется три сдержня: НАЧАЛЬНЫЙ ЦЕЛЕВОЙ и ВРЕМЕННЫЙ                              |
//  Имеется несколько дисков разного размера, повторяющихся нет. Изначально все     |
//  диски расположены на НАЧАЛЬНОМ стержне. Задача состоит в том, что нужно,        |
//  ВРЕМЕННЫЙ стержень перенести все диски с НАЧАЛЬНОГО на ЦЕЛЕВОЙ.                 |
//  Есть два условия:                                                               |
//  1. Диски можно переносить только по одному                                      |
//  2. Нельзя класть диск большего размера на диск меньшего размера                 |
//                                                                                  |
//  Функция:                                                                        |
//                                                                                  |
//  void hanoi(int startStick, int targetStick, int Disks){                         |
//      if (Disks == 1){                                                            |
//          std::cout << "Move disk 1 from pin " << startStick << " to pin "        |
//                   << targetStick << ".\n";                                       |
//      } else {                                                                    |
//          int tmpStick = 6 - startStick - targetStick;                            |
//          hanoi(startStick, tmpStick, Disks - 1);                                 |
//          std::cout << "Move disk " << Disks << " from pin "                      |
//                  << startStick  << " to pin " << targetStick << ".\n";           |
//          hanoi(tmpStick, targetStick, Disks - 1);                                |
//      }                                                                           |
//  }                                                                               |
//                                                                                  |
//  Рассмотрим работу функции на примере четырех дисков:                            |
//                                                                                  |
//  Прежде всего нужно рассмотреть выражение:                                       |
//                     tmpStick = 6 - startStik - targetStik;                       |
//  Вообще все сводится к тому, что мы каким-то образом на ВРЕМЕННЫЙ СТЕРЖЖЕНЬ(tmp) |
//  перемещаем пирамидку с количеством дисков на один меньше:                       |
//                                                                                  |
//                  hanoi(startStik, tmpStick, Disks - 1);                          |
//                                                                                  |
//  Потом я сообщаю, что я перекладываю САМЫЙ БОЛЬШОЙ диск:                         |
//                                                                                  |
//          std::cout << "Move disk " << Disks << " from pin "                      |
//                  << startStick  << " to pin " << targetStick << ".\n";           |
//                                                                                  |
//  Затем мы делаем перемещение с ВРЕМЕННОГО СТЕРЖНЯ(tmp) на ЦЕЛЕВОЙ СТЕРЖЕНЬ(trg): |
//                                                                                  |
//                  hanoi(tmpStick, targetStick, Disks - 1);                        |
//                                                                                  |
//  Задача выполняется до того момента, когда останется тодько один диск!           |
//                                                                                  |
//      if (Disks == 1){                                                            |
//          std::cout << "Move disk 1 from pin " << startStik << " to pin "         |
//                   << targetStik << ".\n";                                        |
//                                                                                  |
//  Нужно учесть, что ВРЕМЕННЫЙ СТЕРЖЕНЬ(tmp) каждый раз расчитывается по формуле:  |
//  Так как у нас три стержня: СТАРТОВЫЙ - первый(1), ЦЕЛЕВОЙ(2) и ВРЕМЕННЫЙ(3)     |
//  дают СУММУ 1 + 2 + 3 = 6, то можно рассчитать номер ВРЕМЕННОГО СТЕРЖНЯ(tmp):    |
//                                                                                  |
//                          TMP = 6 - START - TARGET                                |
//  TIMELINE:                                                                       |
//                                                                                  |
//  1. Функция main() вызывает функцию hanoi(1, 2, 4)                               |
//                                           /\ /\ /\                               |
//                                           || || ||                               |
//                            начальный стержень|| ||                               |
//                                 целевой стержень||                               |
//                                          количество дисков                       |
//                                                                                  |
//  2. Идет проверка if (Disks == 1), у нас 4 != 1                                  |
//     значит переходим к else, там мы видим int tmpStick = 6-startStick-targetStick|
//     выражение дает результат tmpStick = 6 - 1 - 2 => tmpStick = 3                |
//     это выражение вичисляет номер временного стержня для подзадачи, расположенной|
//     в следующей строке этой секции, то есть hanoi(startStick, tmpStick, Disks-1) |
//     Параметры: tmpStick = 3, startStick = 1, targetStick = 2, Disks = 4          |
//  3. Из функции (1, 2, 4) вызывается функция hanoi(startStick, tmpStick, Disks-1) |
//     то есть  -> hanoi(1, 3, 3);                                                  |
//  4. Идет проверка if (Disks == 1), у нас 3 != 1                                  |
//     значит переходим к else, там мы видим int tmpStick = 6-startStick-targetStick|
//     выражение дает результат tmpStick = 6 - 1 - 3 => tmpStick = 2                |
//     Параметры: tmpStick = 2, startStick = 1, targetStick = 3, Disks = 3          |
//  5. Из функции (1, 3, 3) вызывается функция hanoi(startStick, tmpStick, Disks-1) |
//     то есть  -> hanoi(1, 2, 2);                                                  |
//  6. Идет проверка if (Disks == 1), у нас 2 != 1                                  |
//     значит переходим к else, там мы видим int tmpStick = 6-startStick-targetStick|
//     выражение дает результат tmpStick = 6 - 1 - 2 => tmpStick = 3                |
//     Параметры: tmpStick = 3, startStick = 1, targetStick = 2, Disks = 2          |
//  7. Из функции (1, 2, 2) вызывается функция hanoi(startStick, tmpStick, Disks-1) |
//     то есть -> hanoi(1, 3, 1);                                                   |
//  8. Идет проверка if (Disks == 1), у нас 1 == 1 -> Значит мы распечатываем       |
//     std::cout<<"Move disk 1 from pin "<<startStick<<" to pin "<<targetStick<<";  |
//     Move disk 1 from pin 1 to pin 3                                              |
//  9. Функция hanoi(1, 3, 1) отработала, вызвана она была из hanoi(1, 2, 2), мы    |
//     возвращаемся туда и так как hanoi(1, 3, 1) отработала, переходим на следующую|
//     строку с параметрами:tmpStick = 3, startStick = 1, targetStick = 2, Disks = 2|
//  10.Move disk 2 from 1 to 2                                                      |
//  11.Переходим к следующей строке hanoi(tmpStick, targetStick, Disks - 1) и вводим|
//     значения из функции hanoi(1, 2, 2):                                          |
//     tmpStick = 3, startStick = 1, targetStick = 2, Disks = 2 -> hanoi(3, 2, 1)   |
//  12.Идет проверка if (Disks == 1), у нас 1 == 1 -> Значит мы распечатываем:      |
//     Move disk 1 from pin 3 to pin 2                                              |
//  13.Функция hanoi(3, 2, 1) отработала, вызвана она была из hanoi(1, 2, 2),       |
//     которая тоже отработала и мы возвращаемя в hanoi(1, 3, 3);                   |
//     Параметры: tmpStick = 2, startStick = 1, targetStick = 3, Disks = 3          |
//  14.Move disk 3 from 1 to 3                                                      |
//  15.Переходим к следующей строке hanoi(tmpStick, targetStick, Disks - 1) и вводим|
//     значения из функции hanoi(1, 3, 3):                                          |
//     tmpStick = 2, startStick = 1, targetStick = 3, Disks = 3 -> hanoi(2, 3, 2)   |
//  16.Идет проверка if (Disks == 1), у нас 2 != 1                                  |
//     значит переходим к else, там мы видим int tmpStick = 6-startStick-targetStick|
//     выражение дает результат tmpStick = 6 - 2 - 3 => tmpStick = 1                |
//     Параметры: tmpStick = 1, startStick = 2, targetStick = 3, Disks = 2          |
//  17.Вызывается функция hanoi(startStick, tmpStick, Disks - 1); -> hanoi(2, 1, 1);|
//  18.Идет проверка if (Disks == 1), у нас 1 == 1 -> Значит мы распечатываем:      |
//     Move disk 1 from pin 2 to pin 1                                              |
//  19.Функция hanoi(2, 1, 1) отработала, вызвана она была из hanoi(2, 3, 2), мы    |
//     возвращаемся туда и так как hanoi(2, 1, 1) отработала, переходим на следующую|
//     строку с параметрами:tmpStick = 1, startStick = 2, targetStick = 3, Disks = 2|
//  20.Move disk 2 from 2 to 3                                                      |
//  21.Переходим к следующей строке hanoi(tmpStick, targetStick, Disks - 1) и вводим|
//     значения из функции hanoi(2, 3, 2) -> hanoi(1, 3, 1)                         |
//  22.Идет проверка if (Disks == 1), у нас 1 == 1 -> Значит мы распечатываем:      |
//     Move disk 1 from pin 1 to pin 3                                              |
//  23.Функция hanoi(1, 3, 1) отработала, вызвана она была из hanoi(2, 3, 2), мы    |
//     возвращаемся туда и так как hanoi(2, 3, 2) тоже отработала, переходим в      |
//     hanoi(1, 2, 4) с: tmpStick = 2, startStick = 1, targetStick = 2, Disks = 4   |
//  24.Move disk 4 from 1 to 2                                                      |
//  25.Переходим к следующей строке hanoi(tmpStick, targetStick, Disks - 1) и вводим|
//     значения из функции hanoi(1, 2, 4) -> hanoi(3, 2, 3)                         |
//  26.Идет проверка if (Disks == 1), у нас 3 != 1                                  |
//     значит переходим к else, там мы видим int tmpStick = 6-startStick-targetStick|
//     выражение дает результат tmpStick = 6 - 3 - 2 => tmpStick = 1                |
//     Параметры: tmpStick = 1, startStick = 3, targetStick = 2, Disks = 3          |
//  27.Вызывается функция hanoi(startStik, tmpStick, Disks - 1); -> hanoi(3, 1, 2); |
//  28.Идет проверка if (Disks == 1), у нас 2 != 1                                  |
//     значит переходим к else, там мы видим int tmpStick = 6-startStick-targetStick|
//     выражение дает результат tmpStick = 6 - 1 - 2 => tmpStick = 2                |
//     Параметры: tmpStick = 2, startStick = 3, targetStick = 1, Disks = 2          |
//  29.Вызывается функция hanoi(startStick, tmpStick, Disks - 1); -> hanoi(3, 2, 1);|
//  30.Идет проверка if (Disks == 1), у нас 1 == 1 -> Значит мы распечатываем       |
//     std::cout<<"Move disk 1 from pin "<<startStick<<" to pin "<<targetStick<<";  |
//     Move disk 1 from pin 3 to pin 2                                              |
//  31.Функция hanoi(3, 2, 1) отработала, вызвана она была из hanoi(3, 1, 2), мы    |
//     возвращаемся туда и так как hanoi(3, 2, 1) отработала, переходим на следующую|
//     строку с параметрами:tmpStick = 2, startStick = 3, targetStick = 1, Disks = 2|
//  32.Move disk 2 from 3 to 1                                                      |
//  33.Переходим к следующей строке hanoi(tmpStick, targetStick, Disks - 1) и вводим|
//     значения из функции hanoi(3, 1, 2) -> hanoi(2, 1, 1)                         |
//  34.Идет проверка if (Disks == 1), у нас 1 == 1 -> Значит мы распечатываем:      |
//     Move disk 1 from pin 2 to pin 1                                              |
//  35.Функция hanoi(2, 1, 1) отработала, вызвана она была из hanoi(3, 1, 2),       |
//     которая тоже отработала и мы возвращаемя в hanoi(3, 2, 3);                   |
//     Параметры: tmpStick = 1, startStick = 3, targetStick = 2, Disks = 3          |
//  36.Move disk 3 from 3 to 2                                                      |
//  37.Переходим к следующей строке hanoi(tmpStick, targetStick, Disks - 1) и вводим|
//     значения из функции hanoi(3, 2, 3) -> hanoi(1, 2, 2)                         |
//  38.Идет проверка if (Disks == 1), у нас 2 != 1                                  |
//     значит переходим к else, там мы видим int tmpStick = 6-startStick-targetStick|
//     выражение дает результат tmpStick = 6 - 1 - 2 => tmpStick = 3                |
//     Параметры: tmpStick = 3, startStick = 1, targetStick = 2, Disks = 2          |
//  39.Вызывается функция hanoi(startStick, tmpStick, Disks - 1); -> hanoi(1, 3, 1);|
//  40.Идет проверка if (Disks == 1), у нас 1 == 1 -> Значит мы распечатываем:      |
//     Move disk 1 from pin 1 to pin 3                                              |
//  41.Функция hanoi(1, 3, 1) отработала, вызвана она была из hanoi(1, 2, 2), мы    |
//     возвращаемся туда и так как hanoi(1, 3, 1) отработала, переходим на следующую|
//     строку с параметрами:tmpStick = 3, startStick = 1, targetStick = 2, Disks = 2|
//  42.Move disk 2 from 1 to 2                                                      |
//  43.Переходим к следующей строке hanoi(tmpStick, targetStick, Disks - 1) и вводим|
//     значения из функции hanoi(1, 2, 2) -> hanoi(3, 2, 1)                         |
//  44.Идет проверка if (Disks == 1), у нас 1 == 1 -> Значит мы распечатываем:      |
//     Move disk 1 from pin 3 to pin 2                                              |
//  45.Функция hanoi(3, 2, 1) отработала, вызвана она была из hanoi(1, 2, 2),       |
//     которая тоже отработала и мы возвращаемя в hanoi(3, 2, 3), которая тоже      |
//     отработала, значит мы возвращаемся в hanoi(1, 2, 4). И hanoi(1, 2, 4) тоже   |
//     отратобала, таким образом мы возвращаемся в main()                           |
//                                                                                  |
//  ___________                                                                     |
//  |  main() |                                                                     |
//  -----------                                                                     |
//     |    ________________                                                        |
//     |-->|hanoi(1, 2, 4)  |                                                       |
//     |   |if(false) tmp=3 |                                                       |
//     |   |str=1,trg=2,D=4 |                                                       |
//     |    ----------------                                                        |
//     |        |    ________________                                               |
//     |        |-->|hanoi(1, 3, 3)  |                                              |
//     |        |   |if(false) tmp=2 |                                              |
//     |        |   |str=1,trg=3,D=3 |                                              |
//     |        |    ----------------                                               |
//     |        |       |    ________________                                       |
//     |        |       |-->|hanoi(1, 2, 2)  |                                      |
//     |        |       |   |if(false) tmp=3 |                                      |
//     |        |       |   |str=1,trg=2,D=2 |                                      |
//     |        |       |    ----------------                                       |
//     |        |       |       |    _______________                                |
//     |        |       |       |-->|hanoi(1, 3, 1) |                               |
//     |        |       |       |   |if(true) Move  |                               |
//     |        |       |       |   |D 1 from 1 to 3|                               |
//     |        |       |       |    ---------------                                |
//     |        |       |       |                |                                  |
//     |        |       |       |<---------------|                                  |
//     |        |       |       |    ____________                                   |
//     |        |       |       |-->|Move Disk 2 |                                  |
//     |        |       |       |   |from 1 to 2 |                                  |
//     |        |       |       |    ------------                                   |
//     |        |       |       |    _______________                                |
//     |        |       |       |-->|hanoi(3, 2, 1) |                               |
//     |        |       |       |   |if(true) Move  |                               |
//     |        |       |       |   |D 1 from 3 to 2|                               |
//     |        |       |       |    ---------------                                |
//     |        |       |       |           |                                       |
//     |        |       |       x-----------|                                       |
//     |        |       |<------|                                                   |
//     |        |       |                                                           |
//     |        |       |    ____________                                           |
//     |        |       |-->|Move Disk 3 |                                          |
//     |        |       |   |from 1 to 3 |                                          |
//     |        |       |    ------------                                           |
//     |        |       |    ________________                                       |
//     |        |       |-->|hanoi(2, 3, 2)  |                                      |
//     |        |       |   |if(false) tmp=1 |                                      |
//     |        |       |   |str=2,trg=3,D=2 |                                      |
//     |        |       |    ----------------                                       |
//     |        |       |       |    _______________                                |
//     |        |       |       |-->|hanoi(2, 1, 1) |                               |
//     |        |       |       |   |if(true) Move  |                               |
//     |        |       |       |   |D 1 from 2 to 1|                               |
//     |        |       |       |    ---------------                                |
//     |        |       |       |                |                                  |
//     |        |       |       |<---------------|                                  |
//     |        |       |       |    ____________                                   |
//     |        |       |       |-->|Move Disk 2 |                                  |
//     |        |       |       |   |from 2 to 3 |                                  |
//     |        |       |       |    ------------                                   |
//     |        |       |       |    _______________                                |
//     |        |       |       |-->|hanoi(1, 3, 1) |                               |
//     |        |       |       |   |if(true) Move  |                               |
//     |        |       |       |   |D 1 from 1 to 3|                               |
//     |        |       |       |    ---------------                                |
//     |        |       |       x--------------|                                    |
//     |        |       x-------|                                                   |
//     |        |<------|                                                           |
//     |        |    ____________                                                   |
//     |        |-->|Move Disk 4 |                                                  |
//     |        |   |from 1 to 2 |                                                  |
//     |        |    ------------                                                   |
//     |        |    ________________                                               |
//     |        |-->|hanoi(3, 2, 3)  |                                              |
//     |        |   |if(false) tmp=1 |                                              |
//     |        |   |str=3,trg=2,D=3 |                                              |
//     |        |    ----------------                                               |
//     |        |       |    ________________                                       |
//     |        |       |-->|hanoi(3, 1, 2)  |                                      |
//     |        |       |   |if(false) tmp=2 |                                      |
//     |        |       |   |str=3,trg=1,D=2 |                                      |
//     |        |       |    ----------------                                       |
//     |        |       |       |    _______________                                |
//     |        |       |       |-->|hanoi(3, 2, 1) |                               |
//     |        |       |       |   |if(true) Move  |                               |
//     |        |       |       |   |D 1 from 3 to 2|                               |
//     |        |       |       |    ---------------                                |
//     |        |       |       |                |                                  |
//     |        |       |       |<---------------|                                  |
//     |        |       |       |    ____________                                   |
//     |        |       |       |-->|Move Disk 2 |                                  |
//     |        |       |       |   |from 3 to 1 |                                  |
//     |        |       |       |    ------------                                   |
//     |        |       |       |    _______________                                |
//     |        |       |       |-->|hanoi(2, 1, 1) |                               |
//     |        |       |       |   |if(true) Move  |                               |
//     |        |       |       |   |D 1 from 2 to 1|                               |
//     |        |       |       |    ---------------                                |
//     |        |       |       |           |                                       |
//     |        |       |       x-----------|                                       |
//     |        |       |<------|                                                   |
//     |        |       |    ____________                                           |
//     |        |       |-->|Move Disk 3 |                                          |
//     |        |       |   |from 3 to 2 |                                          |
//     |        |       |    ------------                                           |
//     |        |       |    ________________                                       |
//     |        |       |-->|hanoi(1, 2, 2)  |                                      |
//     |        |       |   |if(false) tmp=3 |                                      |
//     |        |       |   |str=1,trg=2,D=2 |                                      |
//     |        |       |    ----------------                                       |
//     |        |       |       |    _______________                                |
//     |        |       |       |-->|hanoi(1, 3, 1) |                               |
//     |        |       |       |   |if(true) Move  |                               |
//     |        |       |       |   |D 1 from 1 to 3|                               |
//     |        |       |       |    ---------------                                |
//     |        |       |       |                |                                  |
//     |        |       |       |<---------------|                                  |
//     |        |       |       |    ____________                                   |
//     |        |       |       |-->|Move Disk 2 |                                  |
//     |        |       |       |   |from 1 to 2 |                                  |
//     |        |       |       |    ------------                                   |
//     |        |       |       |    _______________                                |
//     |        |       |       |-->|hanoi(3, 2, 1) |                               |
//     |        |       |       |   |if(true) Move  |                               |
//     |        |       |       |   |D 1 from 3 to 2|                               |
//     |        |       |       |    ---------------                                |
//     |        |       |       |                |                                  |
//     |        |       |       x----------------|                                  |
//     |        |       x-------|                                                   |
//     |        x-------|                                                           |
//     |<-------|                                                                   |
//__________________________________________________________________________________|

#include <iostream>

// объявление функции
void hanoi(int startStick, int targetStick, int Disks);

int main(int argc, const char * argv[]) {
    int Disks;
    std::cout << "Enter number of disks: ";
    std::cin >> Disks;
    hanoi(1, 2, Disks);
    
    return 0;
}

// определение функции
void hanoi(int startStick, int targetStick, int Disks){
    if (Disks == 1){  // крайний случай, когда дисков осталось одна штука
        std::cout << "Move disk 1 from pin " << startStick << " to pin "
            << targetStick << ".\n";
    } else { // рекуррентный случай:
        int tmpStick = 6 - startStick - targetStick;    // ВРЕМЕННЫЙ СТЕРЖЕНЬ
    // сначала перекладываем со СТАРТОВОГО СТЕРЖНЯ(str) на ВРЕМЕННЫЙ СТЕРЖЕНЬ(tmp)
        hanoi(startStick, tmpStick, Disks - 1);
        std::cout << "Move disk " << Disks << " from pin "
                << startStick  << " to pin " << targetStick << ".\n";
    // теперь перекладываем с ВРЕМЕННОГО СТЕРЖНЯ(tmp) на ЦЕЛЕВОЙ СТЕРЖЕНЬ(trg)
        hanoi(tmpStick, targetStick, Disks - 1);
    }
}
