#include <iostream>
#include <iomanip>
#include <fstream>
#include "interestCalc.hpp"
#include "ListQueue.hpp"


using namespace std;


int main(){
    
    // find interest 
    int startingVal = 1000;
    const double interest = 1.015;
    int daysToTrade = 150;
    int years = 1;
    float result;

    ofstream ints;
    ints.open("ints.txt");
    
    result = doTheMath(getStartingVal(), getYears(), daysToTrade, interest);

            //For Testing
            //result = doTheMath(startingVal, years, daysToTrade, interest);

    ints << fixed << showpoint << setprecision(2) << result;

    //  -Read contents from file into a list
    ListQueue list;
    
    ifstream noCommasIn("ints.txt");   
    string x;               //  <-
    noCommasIn >> x;        //Stops working around here
    cout << x;              //  <-
    for (int i = 0; i<x.length(); i++){
        char y;
        y = x[i];
        list.push(y);
    }
    
    list.print();
    
    
    
};
    
    





