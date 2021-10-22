//
//  main.cpp
//  cppEdu
//
//  Created by Николай Кутузов on 22.10.2021.
//
//__________________________________________________________________________________
//                                                                                  |
//                               Перегрузка функции!                                |
//                                                                                  |
//  Полиморфизм - единый интерфейс, множество реализаций!                           |
//  #include <iostream>                                                             |
//                                                                                  |
//  //  создадим функцию                                                            |
//  void foo(int x){                                                                |
//      std::cout << "foo(int) is called!" << std::endl;                            |
//  }                                                                               |
//                                                                                  |
//  //  создадим такую же функцию, но она принимает НЕ целое число,                 |
//  //  а число с плавающей точкой!                                                 |
//  void foo(double x){                                                             |
//      std::cout << "foo(double) is called!" << std::endl;                         |
//  }                                                                               |
//                                                                                  |
//  int main(int argc, const char * argv[]){                                        |
//      foo(1);                                                                     |
//      foo(3.14);                                                                  |
//                                                                                  |
//      return 0;                                                                   |
//  }                                                                               |
//                                                                                  |
//  ВЫВОД:                                                                          |
//  foo(int) is called!                                                             |
//  foo(double) is called!                                                          |
//                                                                                  |
//  А как сделать так, чтобы не городить кучу функций для каждого типа, а сделать   |
//  шаблон функции?                                                                 |
//                                                                                  |
//  #include <iostream>                                                             |
//                                                                                  |
//  //  создаем ШАБЛОН ФУНКЦИИ (ИНСТАНЦИРОВАНИЕ)                                    |
//  template <typename T>                                                           |
//  T myABS(T x){                                                                   |
//      if (x < 0) {                                                                |
//          return -x;                                                              |
//      } else {                                                                    |
//          return x;                                                               |
//      }                                                                           |
//  }                                                                               |
//                                                                                  |
//  int main(int argc, const char * argv[]){                                        |
//      std::cout << myABS('a') << std::endl;                                       |
//      std::cout << myABS(-23) << std::endl;                                       |
//      std::cout << myABS(-3.14) << std::endl;                                     |
//      std::cout << myABS(1023) << std::endl;                                      |
//                                                                                  |
//      return 0;                                                                   |
//  }                                                                               |
//     ВЫВОД:                                                                       |
//  a                                                                               |
//  23                                                                              |
//  3.14                                                                            |
//  1023                                                                            |
//__________________________________________________________________________________|

#include <iostream>

//  создаем ШАБЛОН ФУНКЦИИ (ИНСТАНЦИРОВАНИЕ)
template <typename T>
T myABS(T x){
    if (x < 0) {
        return -x;
    } else {
        return x;
    }
}

int main(int argc, const char * argv[]){
    std::cout << myABS('a') << std::endl;
    std::cout << myABS(-23) << std::endl;
    std::cout << myABS(-3.14) << std::endl;
    std::cout << myABS(1023) << std::endl;
    
    return 0;
}
