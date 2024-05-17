/*
 Description: This example illustrates the usage of
 command line arguments
 To run the program:
 a.out  movie-file-name  theater-file-name showings-file-name
 */

#include <iostream>
#include <fstream>
#include <cassert>
#include <cstdlib>
using namespace std;

// global constants
const int MAX_MOVIES=25;   // maximum number of movies to read
const int MAX_THEATERS=25; // maximum number of movie theaters to read
const int MAX_LENGTH=80;   // the maximum length of the name of any movie theater

int main(int argc, char *argv[])
{
    char       listOfMovies[MAX_MOVIES][MAX_LENGTH]; // record the titles of the list of movies read
									// Used a 2D array of Char to illustrate C type string usage
	int          numberOfMovies;   // number of movies read
	
	char		listOfTheaters[MAX_THEATERS][MAX_LENGTH]; // record the names of the theaters
								// Used a 2D array of Char to illustrate C type string usage
    int			numberOfTheaters; // number of movie theaters read

	
	int          showings[MAX_THEATERS][MAX_MOVIES];  // this 2D array records which theater is showing which movies
							// The index of the theaters and the index of the movies are used to index into this 2D array
	
	ifstream     movieFile;    // input file stream for "movies.dat"
    ifstream     theaterFile;   // input file stream for "theaters.dat"
	ifstream	 showingFile;   // input file stream for "showings.dat"
	
	int i, j;   // loop index
    int row, col;  // loop index
	
	// debugging statement
	cout << "argc = " << argc << endl;
	
	// check whether the correct number of command line arguments are provided
    if (argc < 4)
    {
        cerr << "Incorrect number of command line arguments.";
        cerr << "Run the program as following :"
			<< "a.out   movies-file  theaters-file showings-file"<< endl;
        exit(-1);
    }
    else
    {
		// opens the movies data file
        movieFile.open(argv[1]);
        assert(movieFile);  // make sure the file is opened correctly
		
		// This loop reads in the list of movie titles.
		// It also counts the number of movie titles read and stores
		// the count in "numberOfMovies"
		numberOfMovies=0;
        while(movieFile.peek() != EOF)
        {
            movieFile.getline(listOfMovies[numberOfMovies], 255, '\n');
			numberOfMovies++;
		}
		
		// debugging statements to check the above file input is done correctly
		cout << "Number of Movies read: " << numberOfMovies << endl;
		cout << "=======================" << endl;
		for (i=0; i<numberOfMovies; i++)
			cout << listOfMovies[i] << endl;
		
		// opens the theater data file
		theaterFile.open(argv[2]);
		assert(theaterFile);
		
		// This loop reads in the list of theater names.
		// It also counts the number of theaters read and stores
		// the count in "numberOfTheaters"
		// This code illustrates:
		// (1) nested while loop
		// (2) the use of peek() function
		// (3) C type string
		numberOfTheaters=0;
		col=0; // start with the first character of the first name
		while ((theaterFile.peek() != EOF)&&(numberOfTheaters < MAX_THEATERS))
		{
			theaterFile.get(listOfTheaters[numberOfTheaters][col]);
			if (listOfTheaters[numberOfTheaters][col] == '\n')
			{
				listOfTheaters[numberOfTheaters][col] = '\0';
				
				numberOfTheaters++;
				col=0;  // set index k to the start of the next theater name
			}
			else
				col++;  // move on to the next character in the name
		}
		listOfTheaters[numberOfTheaters][col] = '\0';  // terminating symbol for C type string
		
		// debugging statements to check the above file input is done correctly
		cout << endl;
		cout << "Number of Theaters read: " << numberOfTheaters << endl;
		cout << "=========================" << endl;
		for (i=0; i<numberOfTheaters; i++)
			cout << listOfTheaters[i] << endl;
		
		// opens the showings data file
		showingFile.open(argv[3]);
		assert(showingFile);
		
		// initialize the entries in the 2D array to '-1'
		for (i=0; i<numberOfTheaters; i++)
			for (j=0; j<numberOfMovies; j++)
				showings[i][j] = -1;
		
		// read the values in the showings array
		row=0; // index for theater
		while ((showingFile.peek() != EOF)&&(row < MAX_MOVIES))
		{
			col=0; // index for movie
			while ((showingFile.peek() != '\n')&&(showingFile.peek() != EOF)&&(col < MAX_THEATERS))
			{
				showingFile >> showings[row][col];
				col++;
			}
			// !!
			showingFile.ignore(100, '\n');
			row++;   // move onto next theater
		}
				
		// debugging statements to check whether the content of showings array is correct
		// after the above file input code
		cout << endl;
		cout << "Display Showings :" << endl;
		cout << "==================" << endl;
		for (i=0; i<numberOfTheaters; i++)
		{
			for (j=0; j<numberOfMovies; j++)
				cout << showings[i][j] << "\t";
			cout << "\n";
		}
	}
	
	movieFile.close();
	theaterFile.close();
	showingFile.close();
	return 0;
}

