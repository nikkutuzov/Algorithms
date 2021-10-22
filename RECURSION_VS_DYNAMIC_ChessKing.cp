//
//  main.cpp
//  cppEdu
//
//  Created by Николай Кутузов on 16.10.2021.
//
//__________________________________________________________________________________
//                                                                                  |
//                      ДВУМЕРНОЕ ДИНАМИЧЕСКОЕ ПРОГРАММИРОВАНИЕ                     |
//                                                                                  |
//                                  ШАХМАТНЫЙ КОРОЛЬ!                               |
//                                                                                  |
//      Рассмотрим на примере следующей задачи: имеется шахматное поле, НО с произ- |
//  вольным количеством клеточек. В верхнем левом углу стоит король, но двигаться   |
//  он может только вправо или вниз и только на одну клеточку. Найти общее количест-|
//  во траекторий по которым он может добраться до точки (n, m), где n - стока, а   |
//  m - столбец.                                                                    |
//                                                                                  |
//                      K[n,m] = K[n, m-1] + K[n-1, m]                              |
//                                                                                  |
//   ___1___  ___2___  ___3___  ___4___  ___5___  ___6___  ___7___  ___m_           |
//  |    o  ||       ||       ||       ||       ||       ||       ||     §          |
//  1  /()\====> 1   ||   1   ||   1   ||   1   ||   1   ||   1   ||     §          |
//  |___/\__||_______||_______||_______||_______||_______||_______||_____§          |
//   ___||__  _______  _______  _______  _______  _______  _______  _____           |
//  |   ||  ||       ||       ||       ||       ||       ||       ||     §          |
//  2 1 \/  ||   2   ||   3   ||   4   ||   5   ||   6   ||   7   ||     §          |
//  |_______||_______||_______||_______||_______||_______||_______||_____§          |
//   _______  _______  _______  _______  _______  _______  _______  _____           |
//  |       ||       ||       ||       ||       ||       ||       ||     §          |
//  3   1   ||   3   ||   6   ||  10   ||  15   ||  21   ||  28   ||     §          |
//  |_______||_______||_______||_______||_______||_______||_______||_____§          |
//   _______  _______  _______  _______  _______  _______  _______  _____           |
//  |       ||       ||       ||       ||       ||       ||       ||     §          |
//  4   1   ||   4   ||  10   ||  20   ||  35   ||  56   ||  84   ||     §          |
//  |_______||_______||_______||_______||_______||_______||_______||_____§          |
//   _______  _______  _______  _______  _______  _______  _______  _____           |
//  |       ||       ||       ||       ||       ||       ||       ||     §          |
//  5   1   ||   5   ||  15   ||  35   ||  70   ||  126  ||  210  ||     §          |
//  |_______||_______||_______||_______||_______||_______||_______||_____§          |
//   _______  _______  _______  _______  _______  _______  _______  _____           |
//  |       ||       ||       ||       ||       ||       ||       ||     §          |
// n|       ||       ||       ||       ||       ||       ||       ||     §          |
//   ~~~~~~~  ~~~~~~~  ~~~~~~~  ~~~~~~~  ~~~~~~~  ~~~~~~~  ~~~~~~~  ~~~~~           |
//                                                                                  |
//      Числа в клетках - это количества способов попасть в эту клетку.             |
//                                                                                  |
//      Если n = 1, то в любую m в этой строке можно попасть только одним способом, |
//  аналогично и если m = 1, то в любую n в этом столбце можно попасть только одним |
//  способом. Из этого следует: базовыми(крайними) случаями будут n = 1 или m = 1   |
//      Попробуем эту задачу рассмотреть на рекуррентном и динамическом варианте!   |
//                                                                                  |
//      Динамический вариант рассматривается как с использованием C_style:          |
//  Там, чтобы создать двумерный массив (он требует, чтобы вторая величина была     |
//  константой, а у нас вторая величина вводится пользователем с клавиатуры во      |
//  время исполнения программы) мы создаем указатель на указатели. Динамически      |
//  выделяем память (не забывая при этом ее высвобождать).                          |
//      И рассматриваем вариант с использованием векторов - CppStyle:               |
//  Создаем вектор векторов (при этом нам не нужно заботится о выделении и освобож- |
//  дении памяти - объект vector все сделаем самостоятельно). И отпадает необходи-  |
//  мость в использовании переменной result!                                        |
//__________________________________________________________________________________|

#include <iostream>
// В динамической функции нам нужно использовать ДВУМЕРНЫЙ массив. Там при
// использовании массива нужна КОНСТАНТНАЯ j - вторая размерность. Для решения
// этой проблемы будем использовать объект vector - динамически расширяемый
// массив для любого типа. Это шаблонный класс.
#include <vector>

// объявляем функции:
int chessKingRecursive(int n, int m);
int chessKingDynamicC_Style(int n, int m);
int chessKingDynamicCppStyle(int n, int m);

int main(int argc, const char * argv[]){
    std::cout << "Задача \"Шахматный Король\" на примере \"Динамческое vs Рекурсия\"!\n";
    
    // объявляем переменные искомых координат
    int n;
    int m;
    std::cout << "Введите координаты для поиска решения!\n";
    std::cout << "Введите координату n: ";
    std::cin >> n;
    std::cout << "Введите координату m: ";
    std::cin >> m;
    
    std::cout << "Рекуррентное решение дало РЕЗУЛЬТАТ: \n";
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            std::cout << chessKingRecursive(i, j) << '\t';
        }
        std::cout << std::endl;
    }
    
    std::cout << "Динамическое программирование (массивы в стиле С) дало РЕЗУЛЬТАТ: \n";
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            std::cout << chessKingDynamicC_Style(i, j) << '\t';
        }
        std::cout << std::endl;
    }
    
    std::cout << "Динамическое программирование (массивы в стиле С++) дало РЕЗУЛЬТАТ: \n";
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            std::cout << chessKingDynamicCppStyle(i, j) << '\t';
        }
        std::cout << std::endl;
    }
    
    return 0;
}

// реализации функций

int chessKingRecursive(int n, int m){
    if(n == 1 or m == 1) {          // базовый случай
        return 1;
    } else {                        // рекуррентный случай
        return chessKingRecursive(n, m - 1) + chessKingRecursive(n - 1, m);
    }
}

int chessKingDynamicC_Style(int n, int m){
    
    // выделяем память под ДВУМЕРНЫЙ массив (ведь у нас таблица двумерная):
    // для этого будем использовать указатель на указатель
    int **K = new int*[n + 1];
    for (int i = 0; i <= n; ++i) {
        K[i] = new int[m + 1];
    }
    
    // базовые(крайние) случаи:
    for (int i = 1; i <= n; ++i) {
        K[i][1] = 1;
    }
    for (int j = 1; j <= m; ++j) {
        K[1][j] = 1;
    }
    
    // рекуррентный случай
    for (int i = 2; i <= n; ++i) {
        for (int j = 2; j <= m; ++j) {
            K[i][j] = K[i][j - 1] + K[i - 1][j];
        }
    }
    int result;
    result = K[n][m];
    
// высвобожаем память:
    // сначала удаляем каждый K[i], то есть массив строк
    for (int i = 0; i <= n; ++i) {
        delete[] K[i] ;
    }
    // затем удаляем массив столбцов
    delete[] K;
    
    return result;
}

int chessKingDynamicCppStyle(int n, int m){
    
    // используем вектор, чтобы явно НЕ выделять и высвобождать память
    // создаем вектор векторов
    std::vector<std::vector<int>> K;
    
    // делаем количество строк и стобцов равное заданным (помним, что подсчет
    // начинается с нуля, поэтому прибавляем по единичке к строкам и столбцам)
    // прибвляем строчку
    K.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        // и в каждой строчке прибавляем по элементу
        K[i].resize(m + 1);
    }
    
    // базовые(крайние) случаи:
    for (int i = 1; i <= n; ++i) {
        K[i][1] = 1;
    }
    for (int j = 1; j <= m; ++j) {
        K[1][j] = 1;
    }
    
    // рекуррентный случай
    for (int i = 2; i <= n; ++i) {
        for (int j = 2; j <= m; ++j) {
            K[i][j] = K[i][j - 1] + K[i - 1][j];
        }
    }

    return K[n][m];
}
