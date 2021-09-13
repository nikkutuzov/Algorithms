//
//  main.cpp
//  cppEdu
//
//  Created by Николай Кутузов on 23.08.2021.
//

/*__________________________________________
                                            |
              массив                        |
            указателей  0   1   2   3       |
     **arr -> 0 [*] -> [ ] [ ] [ ] [ ]      |
        ^     1 [*] -> [ ] [ ] [ ] [ ]      |
     int**    2 [*] -> [ ] [ ] [ ] [ ]      |
                 ^     ^             ^      |
               arr[i]  |  arr[i][j]  |      |
                int*   |     int     |      |
                 N            M             |
 ___________________________________________|
*/
#include <iostream>

void fillArray (int **arr, int N, int M);
void printArray (int **arr, int N, int M);

int main(int argc, const char * argv[]) {
    int N, M;
    std::cout << "Введите количество строк: ";
    std::cin >> N;
    std::cout << "Введите количество столбцов: ";
    std::cin >> M;
    
    // выделяем память
//______________________________________________    //Есть альтернативный вариант:
    // N - кол-во строк                             //
    // **arr - указатель на массив указателей       //
    int **arr = new int *[N];                       // int **arr = new int *[N];
    // M - кол-во столбцов                          // выделяем сразу всю память в arr[0]:
    // arr[i] - указатель на массив int'ов          // arr[0] = new int[N * M];
    for (int i = 0; i < N; ++i) {                   // for (int i = 1; i < N; i++) { <-[ i = 1 ]
        arr[i] = new int[M];                        //     arr[i] = arr[0] + M * i; <- просто
    }                                               // }                          раскладываем адреса
//_______________________________________________   // Но! тогда и память высобождать будем по-другому
                                                    // см. ниже:
    // заполняем массив
    fillArray(arr, N, M);
    
    // распечатываем массив
    printArray(arr, N, M);
                                                    //                  ^
                                                    //                  |
    // высвобождаем выделенную ранее память         // высвоб. при альтернативном выделении памяти
    for (int i = 0; i < N; ++i) {                   // цикл более не нужен
        delete[] arr[i];                            // delete[] arr[0];
    }                                               //
    delete[] arr;                                   // delete[] arr;
    
    return 0;
}

void fillArray (int **arr, int N, int M) {
    for (int i = 0; i < N; ++i) {       // i - номер строки
        for (int j = 0; j < M; ++j) {   // j - номер столбца
            arr[i][j] = i * M + j + 1;
        }
    }
}

void printArray (int **arr, int N, int M) {
    for (int i = 0; i < N; ++i) {       // i - номер строки
        for (int j = 0; j < M; ++j) {   // j - номер столбца
            std::cout << arr[i][j] << '\t';
        }
        std::cout << std::endl;
    }
}
