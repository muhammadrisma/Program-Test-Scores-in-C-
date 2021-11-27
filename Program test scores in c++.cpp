
#include <iostream>

using std::cout;
using std::endl;
using std::fixed;
using std::left;

#include <iomanip>

using std::setw;
using std::setprecision;

const int students = 36; // number of students
const int exams = 2; // number of exams

// function prototypes
int minimum( int [][ exams ], int, int );
int maximum( int [][ exams ], int, int );
double average( int [], int );
void printArray( int [][ exams ], int, int );

int main() 
{
	int studentGrades[ students ][ exams ] = 
	{ { 74, 98},
	 { 77, 68},
	 { 74, 58},
	 { 76, 68},
	 { 75, 68},
	 { 73, 68},
	 { 47, 78},
	 { 77, 68},
	 { 100, 68},
	 { 77, 100},
	 { 78, 99},
	 { 76, 78},
	 { 56, 68},
	 { 80, 88},
	 { 97, 88},
	 { 74, 67},
	 { 89, 90},
	 { 77, 88},
	 { 75, 68},
	 { 77, 95},
	 { 77, 68},
	 { 77, 98},
	 { 77, 78},
	 { 73, 79},
	 { 74, 88},
	 { 73, 68},
	 { 77, 63},
	 { 33, 48},
	 { 100, 100},
	 { 77, 68},
	 { 60, 60},
	 { 46, 58},
	 { 75, 68},
	 { 87, 58},
	 { 72, 78},
	 { 88, 82} };
	 
	cout << "The array is:\n";
	printArray( studentGrades, students, exams );
	
	cout << "\n\nLowest grade: "
		<< minimum( studentGrades, students, exams )
		<< "\nHighest grade: "
		<< maximum( studentGrades, students, exams ) << '\n';
		
	cout << fixed << setprecision( 2 );
	
	
	for ( int person = 0; person < students; person++ )
		cout << "The average grade for student " << person
			<< " is " 
			<< average( studentGrades[ person ], exams )
			<< endl;
		
	return 0;
}

int minimum( int grades[][ exams ], int pupils, int tests )
{
	int lowGrade = 100;
	for ( int i = 0; i < pupils; i++ )
		for ( int j = 0; j < tests; j++ )
			if ( grades[ i ][ j ] < lowGrade )
				lowGrade = grades[ i ][ j ];
				
	return lowGrade;

}

int maximum( int grades[][ exams ], int pupils, int tests )
{
	int highGrade = 0;
	for ( int i = 0; i < pupils; i++ )
		for ( int j = 0; j < tests; j++ )
			if ( grades[ i ][ j ] > highGrade )
				highGrade = grades[ i ][ j ];
	
	return highGrade;
}

double average( int setOfGrades[], int tests )
{
	int total = 0;
	for ( int i = 0; i < tests; i++ )
		total += setOfGrades[ i ]; 
	return static_cast< double >( total ) / tests;
}

void printArray( int grades[][ exams ], int pupils, int tests )
{
	cout << left << " [0] [1] [2] [3] ... [35]";
	for ( int i = 0; i < pupils; i++ ) {
		cout << "\nstudentGrades[" << i << "] ";
		
		for ( int j = 0; j < tests; j++ )
			cout << setw( 5 ) << grades[ i ][ j ];
	}
}


