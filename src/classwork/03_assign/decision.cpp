//cpp
#include "decision.h"

using std::string;

string get_letter_grade_using_if(int grade)
{
    if(grade >= 90 || grade <= 100)
    {
        return "A";
    }
    else if(grade >= 80 || grade < 90)
    {
        return "B";
    }
    else if(grade >= 70 || grade < 80)
    {
        return "C";
    }
    else if(grade >= 60 || grade < 70)
    {
        return "D";
    }
    else if(grade >= 0 || grade < 60)
    {
        return "F";
    }
    else
    {
        return "Number out of range.";
    }
    return 0;
}

std::string get_letter_grade_using_switch(int grade)
{
    std::string letter_grade;

    switch(grade / 10)
    {
        case 10:case 9:
            letter_grade = "A";
            break;
        case 8:
            letter_grade = "B";
            break;
        case 7:
            letter_grade = "C";
            break;
        case 6:
            letter_grade = "D";
            break;
        default:
            letter_grade = "F";
            break;
    }

    return letter_grade;
}