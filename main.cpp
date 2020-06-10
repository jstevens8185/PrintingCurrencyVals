#include <iostream>
#include <iomanip>
#include <fstream>
#include "interestCalc.hpp"
#include "InsertCommas.hpp"


using namespace std;


int main(){
    
                            //Initialize stuff
    int startingVal = 1000;
    const double interest = 1.015;
    int daysToTrade = 150;
    int years = 1;
    float result;

                            //Open file to print to
    ofstream ints;
    ints.open("ints.txt");
    
                            //Get the variables and do something 
    result = doTheMath(getStartingVal(), getYears(), daysToTrade, interest);

            //For Testing
            //result = doTheMath(startingVal, years, daysToTrade, interest);


                            //Print the result as a dollar amount
    ints << fixed << showpoint << setprecision(2) << result; 

    //Close outfile
    ints.close();

    //  -Read contents from file into a list
    ListQueue list;
    
    ifstream noCommas("ints.txt");   





    //string x;                                                 //  <-
    //noCommas >> x;                                            //Stops working around here
    //cout << x;                                                //  <-
    char y;
    while(noCommas >> y){
        //cout << y;
        list.push(y);
    }
    
    list.print();
    
    
    
};
    
    





