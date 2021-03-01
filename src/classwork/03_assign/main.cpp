//Write the include statement for decisions.h here
#include "decision.h"
//Write namespace using statements for cout and cin
using std::cout; using std::cin;
int main() 
{
	int grade_entered;
	std::string grade_earned;

	cout << "Please enter a grade between 0 and 100: ";
	cin >> grade_entered;

	if(grade_entered >= 0 && grade_entered <= 100)
	{
		grade_earned = get_letter_grade_using_if(grade_entered);
		cout << "The letter grade: " << grade_earned << "\n";

		grade_earned = get_letter_grade_using_switch(grade_entered);
		cout << "The letter grade: " << grade_earned << "\n";
	}
	else
	{
		cout << "Number not in range.";
	}

	return 0;
}

