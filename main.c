/**
* Title: timelib
* Author: Antonia Lenz
* Created: 25.01.2021
**/

// Preprocessor: include libraries
#include <stdio.h>
#include <stdlib.h>
#define InputRqstYear printf("Please enter year (yyyy): ");
#define InputRqstMonth printf("Please enter month (m/mm): ");
#define InputRqstDay printf("Please enter day (d/dd): ");
#define ErrorMsgYear printf("The year you entered is not valid. Please enter a year between 1582 and 2400. \n");
#define ErrorMsgMonth printf("The month you entered doesn't exist. Please try again. \n");
#define ErrorMsgDay printf("The day you entered doesn't exist. Please try again. \n");
#define DaysTotalMsg printf("The entered day is the %i. day of the year",
#define End );

// Declare functionprototypes
int day_of_the_year(int day, int month, int year);
void input_date(int *day, int *month, int *year);
int is_leapyear(int year);
int get_days_for_month(int month, int year);
int exists_date(int day, int month, int year);

// Call main function
int main()
{
    // Declare variables
    int day, month, year;

    // Introduction message
    printf("What day of the year is today? Find out with this little program and enter your date of choice. \n");

    // Call input_date function
    input_date(&day, &month, &year);

    // Output & end of program
    DaysTotalMsg day_of_the_year(day, month, year) End

    return 0;
}

/**
 *  This function calculates the day of the year for a given date in the Gregorian calendar (starting January, 1st), consisting of day, month and year.
 *  Leapyears are taken into account in the calculation.
 *  If the passed date is invalid, the return value is -1.
 *  
 *  @param int day, month, year
 *  return int
 **/
int day_of_the_year(int day, int month, int year)
{
    int daysTotal;

    // Return error if date is invalid
    if(exists_date(day, month, year) == 0)
    {
        return -1;
    }

    // Calculate day of the year
    else
    {
        for(int i = 0; i < month - 1; i++)
        {
            daysTotal += get_days_for_month(i + 1, year);
        }
        daysTotal += day;

        return daysTotal;
    }
}

/**
 *  The function reads 3 integer values, for day, month and year.
 *  If the specified date is invalid, it is read again until a valid date is entered.
 *  
 *  @param int* day, month, year
 *  return void
 **/
void input_date(int* day, int* month, int* year)
{
    // Request input until valid date is entered
    do
    {
        InputRqstDay
        scanf("%i", day);
        fflush(stdin);

        InputRqstMonth
        scanf("%i", month);
        fflush(stdin);

        InputRqstYear
        scanf("%i", year);
        fflush(stdin);
    }
    while (exists_date(*day, *month, *year) == 0);
}


/**
 *  The function checks whether a given year is a leap year according to the rules of the Gregorian calendar.
 *  An error is returned for years before the year 1582.
 *  
 *  @param int year
 *  return int
 **/
int is_leapyear(int year)
{
    if (year < 1582 || year > 2400)
    {
        return -1;
    }
    else
    {
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

}

/**
 *  The function determines for a given month of a given year how many days the month has.
 *  The value of the month must be between 1 and 12. Leap years are taken into account.
 *  
 *  @param int month, year
 *  return int
 **/
int get_days_for_month(int month, int year)
{
    // Array providing the days per month if it's not a leap year
    int daysPerMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    // Check if month is valid & return days per selected month
    if (month < 1 || month > 12)
    {
        return -1;
    }
    else
    {
        return month == 2 && is_leapyear(year) ? 29 : daysPerMonth[month - 1];
    }
}

/**
 *  The function checks whether an entered date is valid.
 *  Dates before 1.1.1582 are invalid, as are all dates after 31.12.2400.
 *  
 *  @param int day, month, year
 *  return int
 **/
int exists_date(int day, int month, int year)
{
    int daysPerMonth = get_days_for_month(month, year);

    // Check day with the get_days_for_month function return (see above variable daysPerMonth)
    if (day > daysPerMonth || day < 1)
    {
        ErrorMsgDay
        return 0;
    }

    // Check month with the get_days_for_month function return
    if (get_days_for_month(month, year) == -1)
    {
        ErrorMsgMonth
        return 0;
    }

    // Check year
    if (year > 2400 || year < 1582)
    {
        ErrorMsgYear
        return 0;
    }

    return 1;
}


