#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
//define functions
int numberOfDaysInMonth(int month, int day, int year );
bool dateIsValid(int month, int day, int year);
bool isALeapYear(int year);
void dayOfTheYear(int month, int day, int year, int& dayNum);
void readDateFromFile(int& year,int& month, int& day, char& c);

int main()
{
    //declear variables in main function
	int year, month, day;
	char c;
    int dayNum;


	readDateFromFile( year, month,  day,  c);//call the function which  read date from file


    if (!dateIsValid ( month, day, year) ) //test the input date valid or not
		{
			cout << "Sorry, that is not a valid date" << endl;
            return -1;

		}


    dayOfTheYear( month, day, year, dayNum);

	cout << setw(2) << setfill('0') << month
			 << "/" << setw(2) << setfill('0') << day << "/"
			 << setw(4) << year;
	cout << " is day #" << dayNum << " of that year." << endl; //output the outcome

	return 0;
}

int numberOfDaysInMonth( int month, int day, int year ) //function numberOfDaysInMonth returns an int
{                                                 //numberOfDaysInMonth contain number of days in month
    int numberOfDaysInMonth = 0;
			switch (month)
			{
				case 1:
				case 3:
				case 5:
				case 7:
				case 8:
				case 10:
				case 12:
					numberOfDaysInMonth = 31;
					break;
				case 4:
				case 6:
				case 9:
				case 11:
					numberOfDaysInMonth = 30;
					break;
				case 2:
					if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
						numberOfDaysInMonth = 29;
					else
						numberOfDaysInMonth = 28;
			}

        return numberOfDaysInMonth;
    }

bool dateIsValid(int month, int day, int year) //tests a date to see if it is a valid date
{                                // The Gregorian calendar began On Oct 15, 1582. Earlier dates
    // are invalid.
    if (year < 1582)
			return false;
		else if (year == 1582 && month < 10)
			return false;
		else if (year == 1582 && month == 10 && day < 15)
			return false;
		// Months must be in the range 1..12
		else if (month < 1 || month > 12)
			return false;
		else if (day < 1 || day > numberOfDaysInMonth(month, day, year))
				return false;
    else
        return true;



}

bool isALeapYear(int year)  //determines whether a given year is a leap year or not
//leap year should exactly divisible by 4 and exactly divisible by 100 or can by evenly divided by 400

{

    if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
        return true;
    else
        return false;

}

void dayOfTheYear( int month, int day,int year, int& dayNum) // to computer day# of the year
{
    int sum = 0;

	for (int m = 1; m < month; ++m)
	{
		int monthLength = 0;
		switch (m)
		{
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				monthLength = 31;
				break;
			case 4:
			case 6:
			case 9:
			case 11:
				monthLength = 30;
				break;
			case 2:
				if (isALeapYear(year))
					monthLength = 29;
                 else
					monthLength = 28;
		}

		sum = sum + monthLength;
    }
	    dayNum = sum + day ;

}
void readDateFromFile(int& year,int& month, int& day, char& c)
{
    ifstream inDate;
    inDate.open("dateFile.txt");
    inDate >> year >> c >> month >> c >> day;
    cout << "Date read: " << year << c << month << c << day << endl;       //input the year month and day from file dateFile.txt
    inDate.close();

}


