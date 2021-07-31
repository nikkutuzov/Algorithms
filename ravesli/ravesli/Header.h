//
//  Header.h
//  Ravesli
//
//  Created by Николай Кутузов on 26.05.2021.
//

#ifndef Header_h
#define Header_h
namespace myConst {
constexpr double gravity { 9.8 };
}

void inputHightOfTower();
void currentHight(int hightOfTower, int startTime);

void inputHightOfTower(){
    std::cout << "Enter HIGHT of TOWER: ";
    int hightOfTower;
    std::cin >> hightOfTower;
    
    if ( hightOfTower < 0 ){
        std::cout << "Hight will not to be less of ZERO!\nReEnter Hight!\n";
        inputHightOfTower();
    }
    else if ( hightOfTower == 0 ){
        std::cout << "Ball on the Ground!\n";
    }
    else {
    currentHight(hightOfTower, 0);
    }
    
}

void currentHight(int hightOfTower, int startTime) {
    double currentHightOfBall { hightOfTower - (myConst::gravity * startTime * startTime / 2) };
    if (currentHightOfBall > 0){
        std::cout << "On " << startTime <<  " sec. the ball on "
        << currentHightOfBall << " meters before Ground!" << std::endl;
        ++startTime;
        currentHight(hightOfTower, startTime);
    }
    else
        std::cout << "On " << startTime <<  " sec. the ball on the Ground!\n";
}

#endif /* Header_h */
