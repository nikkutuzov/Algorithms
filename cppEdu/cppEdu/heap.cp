//
//  main.cpp
//  cppEdu
//
//  Created by Николай Кутузов on 23.08.2021.
//

// Создаем пирамиду (eng. HEAP) - КУЧУ - и будем доставать и вставляеть
// из/в пирамиду элементы, а именно: доставать макисальный эелемент,
// а вставлять произвольный и помещать его согласно иерархии этой кучи.
//
//                 *
//              /     \
//             *       *
//            / \     / \
//           *   *   *   *
//          / \
//         *  *
//...

#include <iostream>
// пл сути куча - бинарное дерево, а его можно рассматривать
// как динамический массив, для этого будем использовать вектор
#include <vector>

// создаем синоним типа
typedef int heapData_t; // heapData_t - тип элемента в куче
// делается это для удобства, например: сейчас мне нужно, чтобы
// в куче были int'ы, а если вдруг я захочу чтобы были строки,
// я ТОЛЬКО ТУТ поменяю int на std::string
//
typedef std::vector<heapData_t> heap_t; // heap_t - сама куча

//
// создаем прототипы функции
//

// возвращает значение элемента на вершине кучи
// функция принимает в качестве параметра константную ссылку
// на кучу, так как в этой функции менять ничего не нужно
heapData_t top(const heap_t &h);

// функция убирает значение из вершины кучи
// значит кучу нужно менять, соответсвенно
// параметром буде ссылка НЕКОНСТАНТНАЯ на
// кучу! Возвращаемое значение нужно только
// для информации, можно сделать и void
heapData_t pop(heap_t &h);

// добавить новый элемент в кучу
// значит кучу передаем как параметр функции
// опять же по ссылке, но НЕ КОНСТАНТНОЙ!!!
// и принимет значение, которое будем вставлять
// Функция ничего не возвращает => void
void push(heap_t &h, heapData_t x);

// функция проверки кучи на пустоту
bool isEmpty(heap_t &h);

int main(int argc, const char * argv[]) {
// создаем нашу кучу - вектор!
    heap_t myHeap;
    
    heapData_t x;
    std::cin >> x;
// пока не ввели число 0 будем вставлять в пирамиду значения
    while (x != 0) {
        push(myHeap, x);
        std::cin >> x;
    }
// пока куча не пустая печатать элементы вершины
    while (not isEmpty(myHeap)) {
        std::cout << pop(myHeap) << '\t';
    }
    std::cout << '\n';
    
    return 0;
}

//
// РЕАЛИЗАЦИИ ФУНКЦИЙ
//

heapData_t top(const heap_t &h) {
    return h[0];
}

heapData_t pop(heap_t &h) {
    using namespace std;         // для использования ::size_type
    
    heapData_t value = h[0];    // запоминаем последний элемент
    h[0] = h.back();            // забрасываем последний наверх кучи
    h.pop_back();               // удаляем последний элемент
    
    // битва за вершину пирамиды
    heap_t::size_type currentIndex = 0;             // текущий элемент
    heap_t::size_type left = 2 * currentIndex + 1;  // левый дочерний
    heap_t::size_type right = 2 * currentIndex + 2; // правый дочерний
    
    // автоматически, так как уже проверяли в условии входа
    // в цикл, что левый дочерний существует и он больше текущего или
    // правый дочерний существует и он больше текучего
    while (((left < h.size()) and (h[left] > h[currentIndex])) or
           ((right < h.size()) and (h[right] > h[currentIndex]))) {
        
        // правого элемента не существует или левый больше правого
        if ((right >= h.size()) or (h[left] > h[right])) { //оп. or - ленивый!!!
            swap(h[left], h[currentIndex]);
            currentIndex = left;
        } else {
            swap(h[right], h[currentIndex]);
            currentIndex = right;
        }
        left = 2 * currentIndex + 1;
        right = 2 * currentIndex + 2;
    }
    
    return value;               // передаем запомненное  в вызывающую функцию
}

void push(heap_t &h, heapData_t x) {
    using namespace std;        // для использования ::size_type
    h.push_back(x);
    // попытка подъема на вершину пирамиды
    heap_t::size_type currentIndex =
                    h.size() - 1; // heap_t::size_type - какой тип для
    heap_t::size_type parentIndex =
                    (currentIndex - 1) / 2;  // индекса вектора (size_type >= 0)
    while (currentIndex != 0 and h[currentIndex] > h[parentIndex]) {
        swap(h[currentIndex], h[parentIndex]);
        currentIndex = parentIndex;
        parentIndex = (currentIndex - 1) / 2;
    }
}

bool isEmpty(heap_t &h) {
    return h.size() == 0;
}
