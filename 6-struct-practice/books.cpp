#include <iostream> // Header file for input/output
#include <fstream> 
#include <string>
#include <cassert>
using namespace std;
const int MAX_BOOKS = 1000; // Maximum number of books to be stored

struct DateType
{
	int month;
	int day;
	int year;
};

struct BookType
{
	string title;
	string author;
	DateType dateBorrowed;
	float price;
};

// declare all the functions here
void EnterBooksInLibrary(ifstream& infile, BookType library[], int &number);
void DisplayBooks(BookType library[], const int number);
void SortByAuthor(BookType library[], int number);
void ListBooksByThisAuthor(BookType library[], int number, string thisAuthor);

int main()
{
	int numberBooksInLibrary;
	BookType library[MAX_BOOKS];
	string thisAuther;
	ifstream myIn;
	myIn.open("library.dat");
	assert(myIn);

	EnterBooksInLibrary(myIn, library, numberBooksInLibrary);

	// Sort all books by author's name and display
	SortByAuthor (library, numberBooksInLibrary);

	// Display all the information about each book in the library
	// Fields of the
	DisplayBooks (library, numberBooksInLibrary);

	// Read author from user & display all data for each book written by this author.
	cout << "Please enter the name of the author you are interested in: ";
	getline(cin, thisAuthor);
	ListBooksByThisAuthor(library, numberBooksInLibrary, thisAuthor);

	myIn.close();
	return 0;
}

void EnterBooksInLibrary(ifstream& infile, BookType library[], int &number)
{
	number = 0;
	while (infile.peek() != EOF && number < MAX_BOOKS)
   	{
		getline(infile, library[number].title);
		getline(infile, library[number].author);
		infile >> library[number].dateBorrowed.month;
		infile >> library[number].dateBorrowed.day;
		infile >> library[number].dateBorrowed.year;

		infile >> library[number].price;
		infile.ignore(100, '\n');

		number ++;
	}
}

void DisplayBooks(BookType library[], const int number)
{
	cout << "The list of books are:" << endl;
	for (int i=0; i<number; i++)
	{
		cout << library[i].title << '\t' << library[i].author 
			<< library[i].dateBorrowed.year << '\t' << library[i].price << endl;
	}

}

void SortByAuthor(BookType library[], int number)
{
    bool sorted=false;    // indicates whether additional comparison passes are needed
    int  last=number-1; // the index of the last item in the remaining part of the array

	BookType tmp;

    while (!sorted)
    {
        // assuming the remaining array is sorted.
        sorted=true;
        for (int i=0; i<last; i++)
        {
            if (library[i].author > library[i+1].author)
            {
                // swap the two records
				tmp = library[i];
				library[i] = library[i+1];
				library[i+1] = tmp;			

                // the remaining array is not sorted, need at least another pass
                // of pairwise comparison
                sorted = false;
            }

        }

        last--;
    }

    return;
}

void ListBooksByThisAuthor(BookType library[], int number, string thisAuthor)
{
	for (int i=0; i<number; i++)
	{
		if (thisAuthor == library[i].author)
		{
			cout << library[i].title << endl;
		}
	}
}
