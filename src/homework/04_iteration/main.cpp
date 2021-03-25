//write include statements
#include "dna.h"
#include <iostream>
//write using statements
using namespace std;

/*
Write code that prompts user to enter 1 for Get GC Content, 
or 2 for Get DNA Complement.  The program will prompt user for a 
DNA string and call either get gc content or get dna complement
function and display the result. Program runs as long as 
user enters a y or Y.
*/
int main() 
{
	int option;
	string dna;

	while(1){
		cout << "Enter a DNA string: ";
		cin >> dna;

		cout << "\nSelect option" << endl;
		cout << "1. GC Content" << endl;
		cout << "2. DNA Complement\n" << endl;

		cout << "Enter Option: ";
		cin >> option;

		if (option == 1){
			double content = get_gc_content(dna);
			cout << "GC content: " << content << endl;
		}
		else if (option == 2){
			string complement = get_dna_complement(dna);
			cout << "Complement: " << complement << endl;
		}
		else{
			cout << "Invalid Input." << endl;
		}
		char ch;

		cout << "\nTo continue enter (Y/y): ";
		cin >> ch;

		if(ch == 'Y' || ch == 'y'){
			cout << "\n" << endl;
			continue;
		}
		else{
			break;
		}
	}
	return 0;
}