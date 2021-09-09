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
        p = (*p).next;                      // но лучше использовать p->next
    }
}

const int count = 5;

int main(int argc, const char * argv[]) {
    
    node_t *pBegin = new node_t;            // выделяем память для структуры
    node_t *p = pBegin;                     // приваиваем указателю адрес
                                            // первой структуры
    
    // заполним струткуру: в data мы кладем значение i + 1, а в
    // next - указатель - мы кладем адрес следующей структуры
    for (int i = 0; i < count; ++i) {
        p->data = i + 1;            // просто чтобы начиналось с '1'
        p->next = new node_t;       // выделяем память под следующую структуру
        p = p->next;                // присваиваем указателю адрес следующей -
                                    // - вновь созданной структуры
    }
    // так как структур у нас 5 ( см. count) нужно в поле next текущей структуры
    // указать нулевой указатель, а не указатель на НЕСУЩЕСТВУЮЩУЮ шестую структуру
    p->next = nullptr;
    // ну и просто показать что этим мы завершили цепочку
    p->data = 777;
    
    goThrough(pBegin);
    
    // высвобождаем выделенную память
    delete pBegin;
    delete <#expression#>
    
    return 0;
}