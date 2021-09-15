//
//  main.cpp
//  cppEdu
//
//  Created by Николай Кутузов on 10.09.2021.
//
//__________________________________________________________________________________
//              Бинарный поиск НОВАЯ РЕДАКЦИЯ - с ответом - если есть               |
//               элемент, то каков его индекс или элемента нет вовсе.               |
//                                                                                  |
//      Представим ситуацию поиска числа в отсортированном по возрастанию массиве:  |
// - Сначала мы "стреляем" в середину и смотрим, в какой половине искомое число.    |
// - "Стреляем" в середину той половины, где предположительно находится искомое     |
//число. Делаем так, пока не найдем то число или место, где оно могло бы находиться.|
//                                                                                  |
//                              Например, есть ряд:                                 |
//                   |     1, 3, 3, 4, 6, 7, 7, 7, 7, 9      |                      |
//                                                                                  |
// индексы:       -1   0   1   2   3   4   5   6   7   8   9  10                    |
// числа:         [ ] [1] [3] [3] [4] [6] [7] [7] [7] [7] [9] [ ]                   |
//                 ^                                           ^                    |
//      индекс -1 за границей массива           индекс 10 за границей массива       |
//       левая(left) граница поиска             правая(right) граница поиска        |
//                                                                                  |
//               середина(middle) =  (левая граница + правая граница) / 2           |
//                                                                                  |
//      Функция:                                                                    |
//  int leftBound(int arr[], int arrLength, int desiredNumber) {                    |
//      int left = -1;                                                              |
//      int right = arrLength;                                                      |
//      while (right - left > 1) {                                                  |
//      int middle = (left + right) / 2;                                            |
//          if (arr[middle] < desiredNumber)                                        |
//              left = middle;                                                      |
//          else                                                                    |
//              right = middle;                                                     |
//      }                                                                           |
//                                                                                  |
//      return left;                                                                |
//  }                                                                               |
// - Напимер, ищем число 5:                                                         |
// while (right - left > 1) ПОКА ПРАВАЯ ГРАНИЦА - ЛЕВАЯ ГРАНИЦА БОЛЬШЕ ЕДИНИЦЫ:     |
//            - проверяем условие while (10 - (-1)) > 1                             |
//            - стрелаям в середину (-1 + 10) / 2 = 4                               |
//            - под индексом 4 у нас число [6]:                                     |
//            - если число под индексом middle меньше искомого числа (5), то        |
//              левая(left) граница становится равна середине(middle) - 4, то есть  |
//              мы просто отбрасываем ту половину, в которой его быть не может      |
//            - (6 < 5) - нет => right = 4                                          |
//            - проверяем условие while (4 - (-1)) > 1                              |
//            - снова стреляем в середину (-1 + 4) / 2 = 1                          |
//            - под индексом 1 у нас число [3] - оно меньше, чем искомое (5),       |
//            - если число под индексом middle больше искомого числа (5), то        |
//              левая граница(left) становится равна середине(middle) - 1, то есть  |
//              мы просто отбрасываем ту половину, в которой его быть не может      |
//            - (3 < 5) - да => left = 1                                            |
//            - проверяем условие while (4 - 1)) > 1                                |
//            - снова стрелаям в середину (1 + 4) / 2 = 2                           |
//            - под индексом 2 у нас число [3] - оно меньше чем искомое (5),        |
//            - если число под индексом middle меньше искомого числа (5), то        |
//              левая(left) граница становится равна середине(middle) - 2, то есть  |
//              мы просто отбрасываем ту половину, в которой его быть не может      |
//            - (3 < 5) - да => left = 2                                            |
//            - проверяем условие while (4 - 2)) > 1                                |
//            - снова стреляем в середину (2 + 4) / 2 = 3                           |
//            - под индексом 3 у нас число [4] - оно меньше чем искомое (5),        |
//            - если число под индексом middle меньше искомого числа (5), то        |
//              левая(left) граница становится равна середине(middle) - 3, то есть  |
//              мы просто отбрасываем ту половину, в которой его быть не может      |
//            - (4 < 5) - да => left = 3                                            |
//            - проверяем условие while (4 - 3)) > 1                                |
//              СТОП! НА ЭТОМ ЭТАПЕ МЫ ИМЕЕМ:                                       |
//                              ЛЕВАЯ ГРАНИЦА = 3                                   |
//                              ПРАВАЯ ГРАНИЦА = 4                                  |
//                              right - left (4 - 3) = 1, а у нас строго > 1,       |
//                              значит выполнение цикла while прекращается.         |
//              И мы имеем, что число 5 будет между left = индексу 3,               |
//                                                  а right = индексу 4             |
//      По условию задачи нам нужно найти левую границу, значит левая граница       |
// числа 5 будет индекс 3.                                                          |
//__________________________________________________________________________________|

#include <iostream>

void printArr(int arr[], int arrLength);
int enterDesiredNumber();
int leftBound(int arr[], int arrLength, int desiredNumber);
int findElement(int arr[], int arrLength, int desiredNumber);
void printResultBound(int desiredNumber, int findedIndex);
void printResultFind(int desiredNumber, int findedIndex);

int main(int argc, const char * argv[]) {
    int arr[] { 1, 3, 3, 4, 6, 7, 7, 7, 7, 9 };
    int arrLength = sizeof(arr) / sizeof(arr[0]);
    
    printArr(arr, arrLength);
    
    int desiredNumber = enterDesiredNumber();
    
    printResultBound(desiredNumber, leftBound(arr, arrLength, desiredNumber));
    printResultFind(desiredNumber, findElement(arr, arrLength, desiredNumber));
    
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

int leftBound(int arr[], int arrLength, int desiredNumber) {
    int left = -1;          // я верю, что left < desiredNumber
    int right = arrLength;  // я верю, что right >= desiredNumber
    while (right - left > 1) {
        int middle = (left + right) / 2;
        if (arr[middle] < desiredNumber)
            left = middle;
        else
            right = middle;
    }
    
    return left;
}

// Договариваемся: если элемента нет - возвращаем '-1'
// если элемент есть - возвращаем первый слева индекс.
// То есть, если таких элементов несколько - то мы увидим
// только первый индекс, идущий слева
int findElement(int arr[], int arrLength, int desiredNumber) {
    // сначала находим индекс элемента, который является ЛЕВЫМ
    // КРАЕМ нашего искомого. То есть стоит слева от самогО
    // элемента, если таковой есть. Или слева от того места, где
    // этот искомый элемент мог бы находится
    int left = leftBound(arr, arrLength, desiredNumber);
    // Предполагаем, что следующий от ЛЕВОГО КРАЯ нашего искомого
    // элемента элемент и есть искомый!
    int potentialFirstIndexOfdesiredInArr = left + 1;
    
    // обращаем внимание, что оператор and - ленивый - если
    // первое условие ложь, второе проверяться не будет!!!
    if (potentialFirstIndexOfdesiredInArr < arrLength and          // если индекс нашего потенциального
                                                                   // элемента НЕ за правой границей массива
        arr[potentialFirstIndexOfdesiredInArr] == desiredNumber) { // и по этому индексу расположен элемент
                                                                   // равный нашему искомому -
        return potentialFirstIndexOfdesiredInArr;                  // возвращаем индекс найденного элемента
    } else {
        return -1;                                               // в ином случае возвращаем - 1 (см. leftBound)
    }
}

// распечатка резульата по поиску левого края
void printResultBound (int desiredNumber, int findedIndex) {
    std::cout << "Left boundary (index) of the desired number ["
            << desiredNumber << "] is: " << findedIndex;
    std::cout << std::endl;
}

// распечатка результата по поиску самогО элемента
void printResultFind (int desiredNumber, int findedIndex) {
    if (findedIndex == -1) {
        std::cout << "The desired number [" << desiredNumber
                << "] not found!";
        std::cout << std::endl;
    } else {
    std::cout << "The first/the only one desired number [" << desiredNumber
            << "] from left bound located in: index " << findedIndex;
    std::cout << std::endl;
    }
}
