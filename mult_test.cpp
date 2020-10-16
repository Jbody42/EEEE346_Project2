#include <iostream>
#include "Matrix.h"
using namespace std;

const bool SHOW_PROMPTS = false;

int main(void)
{
	// For this test size of A = B (rows, cols)
	int rowsA, colsA, rowsB, colsB;

	if(SHOW_PROMPTS) {
		cout << "Enter Matrix A:\n";
		cout << "Number of rows: ";
	}
	cin >> rowsA;
	if( SHOW_PROMPTS ) {
		cout << "Number of cols: ";
	}
	cin >> colsA;

	Matrix a(rowsA,colsA);
	if( SHOW_PROMPTS ){
		cout << "Enter values in row then column order:\n";
	}
	cin >> a;

	if( SHOW_PROMPTS ){
		cout << "Enter Matrix B:\n";
		cout << "Number of rows: ";
	}
	cin >> rowsB;
	if( SHOW_PROMPTS ){
		cout << "Number of cols: ";
	}
	cin >> colsB;
	
	Matrix b(rowsB,colsB);
	if( SHOW_PROMPTS ){
		cout << "Enter values in row then column order:\n";
	}
	cin >> b;
	
	cout << "Matrix A\n";
	cout << a;
	cout << "--------------------------\n";

	cout << "Matrix B\n";
	cout << b;
	cout << "--------------------------\n";

	cout << "Multiplying A*B store in C \n";
	Matrix c = a * b;
	cout << "Matrix C:\n";
	cout << a*b;
	cout << "--------------------------\n";

	return 0;
}