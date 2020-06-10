/*******************************************************************
 * interestCalc.hpp
 * 
 * What is It?      Mathmatical functions to be called 
 *                  by compounding interest calculator.
 * 
 * Author:          Jered Stevens
 * Date:            06/08/2020
 *******************************************************************/

double doTheMath(int start, int years, int days, double interest){
    double endVal = start;

    for (int i = 0; i < years; i++){
        for (int j = 0; j < days; j++){
            endVal *= interest;
        }
    }

    return endVal;
}

int getYears(){
    int years;
    std::cout << "enter years\n";
    std::cin >> years;

    return years;
}

int getStartingVal(){
    int x;
    std::cout << "enter starting value\n";
    std::cin >> x;

    return x;
}

