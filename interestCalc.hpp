/*******************************************************************
 * interestCalc.hpp
 * 
 * What is It?      Mathmatical functions to be called 
 *                  by compounding interest calculator.
 * 
 * Author:          Jered Stevens
 * 
 * Date:            06/08/2020
 *******************************************************************/

/********************************************************************
 * function:        doTheMath(int, int, int, double)
 * 
 * Params:          int start, int years, int days, int interest
 * 
 * Whats it do?     Calculates interest for a given amount of years
 *                  with interest being earned and compounded 
 *                  each day such as in a stock trading account
 * 
 * returns:         double
 ********************************************************************/
double doTheMath(int start, int years, int days, double interest){
    double endVal = start;

    for (int i = 0; i < years; i++){
        for (int j = 0; j < days; j++){
            endVal *= interest;
        }
    }

    return endVal;
}

/********************************************************************
 * function:        setYears()
 * 
 * Params:          none
 * 
 * Whats it do?     gets number of years from user
 * 
 * returns:         int
 ********************************************************************/
int setYears(){
    int years;
    std::cout << "enter years\n";
    std::cin >> years;

    return years;
}

/********************************************************************
 * function:        setStartingVal()
 * 
 * Params:          none
 * 
 * Whats it do?     gets starting value of the interest earning account
 * 
 * returns:         int
 ********************************************************************/
int setStartingVal(){
    int x;
    std::cout << "enter starting value\n";
    std::cin >> x;

    return x;
}

/********************************************************************
 * function:        setInterest()
 * 
 * Params:          none
 * 
 * Whats it do?     gets interest to be earned by user
 * 
 * returns:         double
 ********************************************************************/
double setInterest()