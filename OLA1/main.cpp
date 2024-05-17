#include <iostream>  // for cin, cout, endl, etc
#include <fstream> // for ifstream
#include <cassert>  // for assert
using namespace std;

int main()
{
        int day; // a person's day of birth from user input.
        int month; // a person's month of birth from user input.
        int year; // a person's year of birth from user input.
        // declare other variables here

        ifstream myIn("birthday.dat");
        assert(myIn);

        // This loop will read one birthday at a time til the end
        // of the data file is reached
        // For each birthday read:
        // (1) check whether the birthday is valid
        //     if it is not valid, display the message
        // (2) if it is valid compute and display the day of the week
        while (myIn >> month >> day >> year)
        {   
            
            cout << month << " " <<  day << " " << year << " => ";
            
            
            // Check for birthday validity
            
            
            // if the birthday is valid, compute and display its corresponding weekday

        
        
        }// end while
                
        myIn.close();
        return 0;
}
