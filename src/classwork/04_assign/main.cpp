//write includes statements
#include "loops.h"
#include <iostream>
//write using statements for cin and cout
using namespace std;

/*
Use a do while loop to prompt the user for 
a number, call the factorial function, and display the number's
factorial.  Also, loop continues as long as user wants to.
*/
int main() 
{
	int number;
	char retry;

	do
	{
		cout << "Enter number between 1 and 10: ";
		cin >> number;

		if (number >= 1 && number <= 10)
		{
			cout << "The factorial of " << number << " is: " << 
			factorial(number) << ".\n";
		}

		else

			cout << "Number entered not in range.\n";

		cout << "Would you like to enter another number? If yes, type Y. ";
		cin >> retry;

	} while (retry == 'Y' || retry == 'y');
	
	return 0;
}