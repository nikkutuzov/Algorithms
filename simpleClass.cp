//
//  main.cpp
//  cppEdu
//
//  Created by Николай Кутузов on 20.10.2021.
//
//__________________________________________________________________________________
//                                                                                  |
//                                      Классы!                                     |
//                                                                                  |
//      Класс - это тип, а экземпляр класса - это конкретный объект. Можно грубо    |
//  сравнить как переменная и значение переменной - но это очень грубое сравнение.  |
//                                     x = 5.                                       |
//                                                                                  |
// Класс нужен класс? В первую очередь, когда много данных, которую нужно объединить|
// в некую структуру.                                                               |
//                                                                                  |
//  #include <iostream>                                                             |
//  #include <string>                                                               |
//                                                                                  |
//  //  создадим структуру                                                          |
//  struct Student_s {                                                              |
//      std::string name;                                                           |
//      std::string group;                                                          |
//      int ageOfStudent;                                                           |
//  };                                                                              |
//                                                                                  |
//  void studentInit(Student_s &a);                                                 |
//  void studentAgeing(Student_s &a);                                               |
//  void studentPrint(const Student_s &obj);                                        |
//                                                                                  |
//  int main(int argc, const char * argv[]){                                        |
//      Student_s a;                                                                |
//      studentInit(a);                                                             |
//      studentPrint(a);                                                            |
//      studentAgeing(a);                                                           |
//      studentPrint(a);                                                            |
//      return 0;                                                                   |
//  }                                                                               |
//  void studentInit(Student_s &a){                                                 |
//      a.name = "Вася";                                                            |
//      a.group = "B02";                                                            |
//      a.ageOfStudent = 21;                                                        |
//  }                                                                               |
//  void studentAgeing(Student_s &a){                                               |
//      std::cout << "Сегодня мой День рождения! Я стал на год старше!" << '\n';    |
//      a.ageOfStudent++;                                                           |
//  }                                                                               |
//  void studentPrint(const Student_s &s){                                          |
//      std::cout << s.name << ' ' << s.group << ' ' << s.ageOfStudent << std::endl;|
//  }                                                                               |
//                                  Инкапсуляция                                    |
//                                  /          \                                    |
//                                 /            \                                   |
//                               КОД          Принцып                               |
//                                +          сокрытия                               |
//                              данные        данных                                |
//                                                                                  |
//  Функции, помещенные с структуру, называются методами!                           |
//                                                                                  |
//      "КОД + данные":                                                             |
//                                                                                  |
//  #include <iostream>                                                             |
//  #include <string>                                                               |
//                                                                                  |
//  //  создадим структуру                                                          |
//  struct Student_s {                                                              |
//      std::string name;                                                           |
//      std::string group;                                                          |
//      int ageOfStudent;                                                           |
//                                                                                  |
//  // внесем в структуру методы - этим мы объединим код и данные:                  |
//      void studentInit(){                                                         |
//          name = "Вася";                                                          |
//          group = "B02";                                                          |
//          ageOfStudent = 21;                                                      |
//      }                                                                           |
//      void studentAgeing(){                                                       |
//          std::cout << "Сегодня мой День рождения! Я стал на год старше!"         |
//                  << '\n';                                                        |
//          ageOfStudent++;                                                         |
//      }                                                                           |
//      void Print() const{                                                         |
//      std::cout << name << ' ' << group << ' ' << ageOfStudent << std::endl;      |
//      }                                                                           |
//  };                                                                              |
//                                                                                  |
//  int main(int argc, const char * argv[]){                                        |
//      Student_s a;                                                                |
//                                                                                  |
//      a.Init();                                                                   |
//      a.Print();                                                                  |
//      a.Ageing();                                                                 |
//      a.Print();                                                                  |
//      return 0;                                                                   |
//  }                                                                               |
//                                                                                  |
//  Сокроем данные:                                                                 |
//                                                                                  |
//  //  создадим КЛАСС                                                              |
//  class Student_s { <- если тут написать struct вместо class, то тоже все ОК      |
//    // сокроем данные - сделаем их недоступными из вне                            |
//  private:                                                                        |
//      std::string name;                                                           |
//      std::string group;                                                          |
//      int ageOfStudent;                                                           |
//                                                                                  |
//  //  а методы сделаем доступными из вне. Теперь к данным мы сможем обратиться    |
//  //  ТОЛЬКО через методы!                                                        |
//  public:                                                                         |
//  // внесем в структуру методы - этим мы объединим код и данные:                  |
//      // Конструктор для создания студента - можно задать параметры по умолчанию  |
//      Student_s(std::string name_, std::string group_, int age_){                 |
//          name = name_;                                                           |
//          group = group_;                                                         |
//          AgeOfStudent = age_;                                                    |
//      }                                                                           |
//      //Деструктор для студента                                                   |
//      ~Student_s(){                                                               |
//          std::cout << "Ой! " << name << " отчислен! :(" << std::endl;            |
//      }                                                                           |
//      ...... продожление кода .............                                       |
//      void Print() const{                                                         |
//      std::cout << name << ' ' << group << ' ' << ageOfStudent << std::endl;      |
//      }                                                                           |
//  };                                                                              |
//                                                                                  |
//  int main(int argc, const char * argv[]){                                        |
//  // теперь создавать студента нужно так!                                         |
//      Student_s ("Вася", "В31", 18);                                              |
//                                                                                  |
//      a.Print();                                                                  |
//      a.Ageing();                                                                 |
//      a.Print();                                                                  |
//  // а так НЕЛЬЗЯ!                                                                |
//      Student_s b;                                                                |
//                                                                                  |
//      return 0;                                                                   |
//  }                                                                               |
//__________________________________________________________________________________|

#include <iostream>
#include <string>

//  создадим структуру
class Student_s { // по сути clacc - это расширение понятия структуры!
                    // можно было и struct Student_s { написать!
    // сокроем данные - сделаем их недоступными из вне
private:
    std::string name;
    std::string group;
    int ageOfStudent;
//  а методы сделаем доступными из вне. Теперь к данным мы сможем обратиться
//  ТОЛЬКО через методы!
public:
    //
// внесем в структуру методы - этим мы объединим код и данные:
    // Конструктор для создания студента
    Student_s(std::string name_, std::string group_, int age_){
        name = name_;
        group = group_;
        ageOfStudent = age_;
        std::cout << "Создан новый студент" << std::endl;
    }
    // Деструктор!
    ~Student_s(){
        std::cout << "Ой! " << name << " отчислен! :(" << std::endl;
    }

    //метод
    void Ageing(){
        std::cout << "Сегодня мой День рождения! Я стал на год старше!" << '\n';
        ageOfStudent++;
    }

    //метод
    void Print() const {
        std::cout << name << ' ' << group << ' ' << ageOfStudent << std::endl;
    }
    
};

int main(int argc, const char * argv[]){
    // теперь создавать студента нужно так!
    Student_s a("Вася", "В31", 18);
    
    a.Print();
    a.Ageing();
    a.Print();
    
    Student_s b("Коля", "Е21", 33);
    return 0;
}
