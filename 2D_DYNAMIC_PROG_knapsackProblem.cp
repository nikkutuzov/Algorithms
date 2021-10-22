//
//  main.cpp
//  cppEdu
//
//  Created by Николай Кутузов on 17.10.2021.
//
//__________________________________________________________________________________
//                                                                                  |
//                      ДВУМЕРНОЕ ДИНАМИЧЕСКОЕ ПРОГРАММИРОВАНИЕ                     |
//                                                                                  |
//                   ЗАДАЧА ОБ УКЛАДКЕ РЮКЗАКА (knapsack problem)                   |
//                                                                                  |
//    Задача заключается в следующем: имеется рюкзак, который вмещает сколько-то    |
//  килограмм. Имеется несколько вещей. Каждая вещь в единственном экземпляре и     |
//  имеет разные ВЕС и СТОИМОСТЬ. Нужно уложить вещи так, чтобы в рюкзаке была      |
//  максимальная сумма стоимостей предметов. Причем может быть так, что вес малый,  |
//  а стоимость большАя и наоборот.                                                 |
//      Данные:                                                                     |
//      m[1], m[2], m[3], m[4], m[5]...m[n] - массы предметов                       |
//      v[1], v[2], v[3], v[4], v[5]...v[n] - ценности(стоимости) предметов         |
//      Решение:                                                                    |
//  Решением будет являться подмножество предметов (будет выбор: этот предмет беру, |
//  а это НЕ беру - то есть булевское подмножество), при условии, что сумма масс    |
//  предметов НЕ превышает максимальную вместимость (по весу) рюкзака. В то же      |
//  время я хочу выбрать такое, у которого суммарная ценность(стоимость) этих       |
//  предметов - МАКСИМАЛЬНАЯ! Теперь представим, что у нас есть 6 предметов:        |
//                                                     ______                       |
//    o           _            @         <=|=>        | ABC  |         §            |
//  /()\<-Кукла  ( )<-Бутылка  v<-Цветок   |<-Ледоруб | book |<-книга | |<-свеча    |
//   /\          (_)           |           |          |______|        |_|           |
//                                                                                  |
//     Тогда мы можем представить комбинации "взяли/НЕ взяли предмет" как:          |
//  1 - взяли 0 - НЕ взяли:                                                         |
//                                                     ______                       |
//    o           _            @         <=|=>        | ABC  |         §            |
//  /()\<-Кукла  ( )<-Бутылка  v<-Цветок   |<-Ледоруб | book |<-книга | |<-свеча    |
//   /\          (_)           |           |          |______|        |_|           |
//                                                                                  |
//    0           0            0           0             0             1            |
//    0           0            0           0             1             0            |
//    0           0            0           0             1             1            |
//    0           0            0           1             0             0            |
//    0           0            0           1             0             1            |
//    0           0            0           1             1             1            |
//    0           0            1           0             0             0            |
//    0           0            1           0             0             1            |
//    0           0            1           0             1             0            |
//    .......................................................................       |
//    1           1            1           1             1             1            |
//      То есть 2 в степени n, где n - это количество предметов. В нашем случае 64  |
//  При шести предметах эта цифра не кажется большой. А что, если у нас 20 или 30   |
//  предметов? Задача алгоритмически сложная и решается только приближенно!         |
//  Рассмотрим следующий вариант - ДИСКРЕТНЫЙ. Это значит, что массы у нас будут    |
//  ТОЛЬКО ЦЕЛЫМИ ЧИСЛАМИ!                                                          |
//      Допустим, рюкзак может выдержать 11 килограмм, а вещи запишем так:          |
//                              ВЕЩЬ[МАССА/ЦЕННОСТЬ]                                |
//  КУКЛА[2/3], БУТЫЛКА[3/1], ЦВЕТОК[5/5], ЛЕДОРУБ[1/2], КНИГА[2/10], СВЕЧА[3/3]    |
//      Примечание: у нас может быть НОЛЬ предметов - отметим это как [0]           |
//                                                                                  |
//  Начинаем заполнять таблицу следующим образом. Если я беру НУЛЕВОЙ предмет, то   |
//  вес и ценность по нулям - заполняем по вертикали нулями. Если грузоподъемность  |
//  рюкзака равна НУЛЮ (смотрим вертикальную ось МАССА) равна нулю - заполняем      |
//  нулями по горизонтали. Затем, смотрим на вес куклы (вес равен 2) и ставим в     |
//  таблице ценность (у куклы 3) напротив МАССА(на этой шкале  отображается         |
//  грузоподъемномть рюкзака) 2 под ПРЕДМЕТОМ 1 и ниже, так как так как ниже увели- |
//  чивается грузоподъемность рюкзака. Теперь смотрим клетку [2,1] - туда нельзя ни |
//  куклу, ни бутылку положить, значит копируем значение из клетки [1,1]. Смотрим   |
//  на клетку [2,2] - мы можем положить куклу (вес куклы 2 равен грузоподъемности   |
//  рюкзака 2), но не можем положить бутылку (ее вес 3), поэтому выбираем класть    |
//  куклу или класть нулевой предмет. Выбираем куклу (нам же важна ценность) и      |
//  копируем 3 в клетку [2,2]. Переходим к клетке [2,3] - можем положить и куклу и  |
//  бутылку, но у куклы ценность выше - копируем 3. А вот в клетке [2,5] можем взять|
//  и куклу и бутылку - общий вес 2 + 3 = 5, общая ценность 3 + 1 = 4... Заполняя   |
//  по аналогии мы дошли до клетки [3,5] - мы можем взять либо ТОЛЬКО цветок, либо  |
//  куклу и бутылку, но у цветка ценность 5, а у куклы и бутылки вместе взятых - 4, |
//  значит берем цветок! И так заполняем до конца!                                  |
//                                                                                  |
//                                  ПРЕДМЕТЫ                                        |
//                                                                                  |
//           [2/3],     [3/1],       [5/5],     [1/2],        [2/10],       [3/3]   |
//                                                            ______                |
//             o          =            @        <=|=>        | ABC  |         §     |
//           /()\        ( )           v          |          | book |        | |    |
//            /\         (_)           |          |          |______|        |_|    |
//     [0]    [1]        [2]          [3]        [4]           [5]           [6]    |
//   ______________________________________________________________________________ |
//  |                                                                               |
//  |0  0      0          0            0          0             0             0     |
//  |                                                                               |
//  |1  0      0--------> 0            0          2                                 |
//  |                                                                               |
// М|2  0      3--------> 3            3          3                                 |
//  |                                                                               |
//  |3  0      3--------> 3            3          5                                 |
// А|                                                                               |
//  |4  0      3--------> 3            3          5                                 |
//  |                                                                               |
// С|5  0      3          4            5          5                                 |
//  |                                                                               |
//  |6  0      3          4            5                                            |
// С|                                                                               |
//  |7  0      3          4            8                                            |
//  |                                                                               |
// А|8  0      3          4            8                                            |
//  |                                                                               |
//  |9  0      3          4            8                                            |
//  |                                                                               |
//  10  0      3          4            9                                            |
//  |                                                                               |
//  11  0      3          4            9                                            |
//                                                                                  |
//      Рассмотрим работу функции knapsackProblem:                                  |
//  Создаем вектор векторов - двумерный динамический массив. Так как индексы начи-  |
//  наются с нулевого, а нам нужно чтобы номер предмета (первый, второй...) соот-   |
//  ветствовал индексу (индекс 1, индекс 2...), мы прибавляем по одному элементу к  |
//  стоблцам и строкам соответственно.                                              |
//  Описываем базовые случаи: когда предполагаем, что берем 0 предметов и заполняем |
//  стоимости и весы нулямя - ноль предметов стоят ноль и весят ноль.               |
//      РЕКУРРЕНТНЫЕ СЛУЧАИ:                                                        |
//  Функция Ф[грузоподъемность, кол-во предметов] равна максимуму из возможностей:  |
//  Ф[Г, К - 1] - когда предмет НЕ беру и когда я хочу эту вещь взять:              |
//   Ценность этого предмета value + максимальная ценность БЕЗ этого предмета К - 1 |
//      при этом нужно вес этого предмета нужно вычесть из Г рюкзака:               |
//                                                                                  |
//              Ф[Г, К] = Ф[Г, К - 1], Ценность + Ф[Г минус вес этого П, К - 1]     |
//                                                                                  |
//  Пробегаем по столбцам ПРЕДМЕТЫ с ПЕРВОГО и по ПОСЛЕДНЕГО ВКЛЮЧИТЕЛЬНО! Сначала  |
//  находим ВЕС и СТОИМОСТЬ предыдущего предмета. Начиная с объекта ВЕСОМ 1, пока   |
//  вес меньше веса предыдущего объекта, в ответ записываем ЦЕННОСТЬ предыдущего    |
//  объекта. Затем, начиная с ВЕСА этого объекта и до максимальной ГРУЗОПОДЪЕМНОСТИ |
//  рюкзака ВКЛЮЧИТЕЛЬНО записываем ЦЕННОСТЬ равную МАКСИМУМУ из (если я этот пред- |
//  мет НЕ беру и ЦЕННОСТЬЮ этого предмета ПЛЮС Суммарная ЦЕННОСТЬ без этого пред-  |
//  мета в ячейке для предыдущих предметов, которые поместятся в рюкзак вместе с    |
//  этим предметом!                                                                 |
//__________________________________________________________________________________|

#include <iostream>
// Нам нужно использовать ДВУМЕРНЫЙ массив.
// Для решения этой проблемы будем использовать объект vector - динамически
// расширяемый массив для любого типа. Это шаблонный класс.
#include <vector>

// объявляем функцию
int knapsackProblem(std::vector<std::pair<int, int>> objects, int capacityOfKnapsack);

int main(int argc, const char * argv[]){
    std::cout << "Задача \"Проблема укладки рюкзака\"!\n";
    std::cout << "Введите грузоподъемность рюкзака: ";
    int capacityOfKnapsack;
    std::cin >> capacityOfKnapsack;
    std::cout << "Введите количество предметов: ";
    int objectsNumber;
    std::cin >> objectsNumber;
    
    // создаем вектор пар "вес-ценность"
    std::vector<std::pair<int, int>> objects;
    // заполняем вектор пар
    for (int count = 0; count < objectsNumber; ++count) {
        int weigthOfObject;
        int valueOfObject;
        std::cout << "Введите вес вещи № " << count + 1 << std::endl;
        std::cin >> weigthOfObject;
        std::cout << "Введите ценность вещи № " << count + 1 << std::endl;
        std::cin >> valueOfObject;
        objects.push_back(std::make_pair(weigthOfObject, valueOfObject));
    }
    
    std::cout << "Максимальная ценность, которую можно унести в рюкзаке: "
            << knapsackProblem(objects, capacityOfKnapsack) << std::endl;
    
    return 0;
}

// реализации функций

int knapsackProblem(std::vector<std::pair<int, int>> objects, int capacityOfKnapsack){
    // создаем массив ответов
    std::vector<std::vector<int>> answers;
    answers.resize(capacityOfKnapsack + 1);
    for (int i = 0; i <= capacityOfKnapsack; ++i) {
        answers[i].resize(objects.size() + 1);
    }
    
    // базовые случаи:
    for (int weigthOfObject = 0; weigthOfObject <= capacityOfKnapsack; ++weigthOfObject) {
        answers[weigthOfObject][0] = 0;
    }
    for (int objectsNumber = 0; objectsNumber <= objects.size(); ++objectsNumber) {
        answers[0][objectsNumber] = 0;
    }
    
    // рекуррентные случаи:
    for (int objectsNumber = 1; objectsNumber <= objects.size(); ++objectsNumber) {
        int weigth = objects[objectsNumber - 1].first;
        int value = objects[objectsNumber - 1].second;
        for (int weigthOfObject = 1; weigthOfObject < weigth; ++weigthOfObject) {
            answers[weigthOfObject][objectsNumber] = answers[weigthOfObject][objectsNumber - 1];
        }
        
        for (int weigthOfObject = weigth; weigthOfObject <= capacityOfKnapsack; ++weigthOfObject) {
            answers[weigthOfObject][objectsNumber] =
                    std::max(answers[weigthOfObject][objectsNumber - 1],
                                value + answers[weigthOfObject - weigth][objectsNumber - 1]);
        }
    }
    
    return answers[capacityOfKnapsack][objects.size()];
}