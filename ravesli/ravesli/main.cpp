#include <iostream>

int main(int argc, const char * argv[]) {
    int quantityTotalNumbers; //quantity input numbers
    int range; // размер червяка
    int minOddNumber = 1000;
    int livingNumber; // число, которое покинуло очередь
    int qEnd = 0;
    int production = 10000;
    bool flag = false;  // для вывода -1, если не найдется пары
    // общее количество входящих чисел
    std::cout << "Enter quantity of numbers: ";
    std::cin >> quantityTotalNumbers;
    //задаем размер червяка
    std::cout << "Enter range of earthWorm: ";
    std::cin >> range;
    int earthWorm [range]; // сам червяк
    // Заполним червяка
    for (int i = 0; i <= range; ++i) {
        std::cout << "Enter " << i + 1 << " number of "
                << quantityTotalNumbers << " : ";
        std::cin >> earthWorm[i];
    }
    //проходим по дальнейшим числам и вытаскиваем/засовываем их из/в червяка
    for (int i = range + 1; i < quantityTotalNumbers; ++i) {
        int currentNumber;
        std::cout << "Enter " << i + 1 << " number of "
                << quantityTotalNumbers << " : ";
        std::cin >> currentNumber;
        livingNumber = earthWorm[qEnd];
        earthWorm[qEnd++] = currentNumber;
        if (qEnd > range)
            qEnd = 0;
        //ищем минималное неченое число
        if (livingNumber % 2 != 0 and livingNumber < minOddNumber) {
            minOddNumber = livingNumber;
            std::cout << "Minimal nember is " << livingNumber << std::endl;
        }
        //ищем минимальное произведение
        if (currentNumber % 2 != 0 and minOddNumber * currentNumber < production) {
            production = minOddNumber * currentNumber;
            std::cout << "Current production = " << production << std::endl;
            flag = true;
        }
    }
    if (flag)
        std::cout << "Production = " << production << std::endl;
    else
        std::cout << "Production = -1\n";
    
        return 0;
}
