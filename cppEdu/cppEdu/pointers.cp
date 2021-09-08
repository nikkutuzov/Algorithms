//
//  main.cpp
//  cppEdu
//
//  Created by Николай Кутузов on 23.08.2021.
//

#include <iostream>

struct node_t {
    int data;               // просто какие-то данные
    node_t *next;           // указатель на что-то - определим в main()
};

void goThrough(node_t *p) {
    while (p != nullptr) {
        // распечатываем то что находится в поле data в структуре
        // по адресу, начиная с p = pBegin
        std::cout << p->data << '\n';       // можно по старинке (*p).data
        // а потом меняем адрес согласно
        // что у нас в структуре по текущему
        // адресу указано в поле next адрес
        // следующей структуры см. цикл в main()
        p = (*p).next;                      // ну лучше использовать p->next
    }
}

const int lengthOfArr = 5;

int main(int argc, const char * argv[]) {
    
    node_t arr[lengthOfArr];
    // заполним струткуру: в data мы кладем значение i + 1, а в
    // next - указатель - мы кладем адрес следующей структуры
    for (int i = 0; i < lengthOfArr; ++i) {
        arr[i].data = i + 1;        // просто чтобы начиналось с '1'
        arr[i].next = arr + i + 1;  // arr[0] тоже самое что и &(*(arr + 0)),
                                    // а разыменование '*' и взятие адреса '&'
                                    // это взаимоуничтожающе операции
    }
    // после завершения цикла у нас создается опасная ситуация:
    // i == 4 => мы получаем указатель на arr[5] (arr + 4 + 1),
    // а его нет - последний элемент в массиве arr[4]
    // значит нам нужно в arr[4].next положить нулевой указатель
    arr[4].next = nullptr;
    arr[4].data = 777;
    
    // указатель на начало
    node_t *pBegin = arr;           // тоже что и node_t *pBegin = arr[0];
    goThrough(pBegin);
    return 0;
}
