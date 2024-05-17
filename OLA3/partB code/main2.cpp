#include <iostream> 
#include <string> 
#include <fstream> 
#include <cassert> 
using namespace std;

// Function Prototypes
//Provide function prototypes for CheckDigit and IsValidISBN

int main( ) {
  string isbn; //ISBN number to be processed
  bool   isValid; //indicates if the isbn is valid
  ifstream  myIn;

  myIn.open("isbn.dat"); 
  assert(myIn);

  while ( myIn >> isbn) //read a ISBN number from data file
  {
    // Add statement that makes a call to the function IsValidISBN to find out the value of variable isValid.
    if ( isValid )
      cout << isbn << " is a valid ISBN number" << endl;
    else
      cout << isbn << " is not a valid ISBN number" << endl;
  }

  myIn.close();
  return 0; 
}

// Define the IsValidISBN function here. The IsValidISBN function will call function "CheckDigit" to compute the check digit

// Define the IsValidISBN function here. The IsValidISBN function will call function "CheckDigit" to compute the check digit

// Define CheckDigit function here.