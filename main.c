/**
* Title: timelib
* Author: Antonia Lenz
* Created: 25.01.2021
**/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Declare functionprototypes
int day_of_the_year(int day, int month, int year);
int input_date(int day, int month, int year);
int is_leapyear(int year);
int get_days_for_month(int month, int year);
int exists_date(int day, int month, int year);

int main()
{
    int day;
    int month;
    int year;
    int daysTotal = 0;
    int daysPerMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    bool leapyear = false;
    bool dayExists = false;
    bool dateValid = false;
    bool monthExists = false;

    printf("What day of the year is today? Find out with this little program and enter your date of choice. \n");

    // Input & check if year is valid
    printf("Enter year (yyyy): \n");
    while (!dateValid)
    {
        scanf("%i", &year);
        if (year >= 1582 && year <= 2400)
        {
            dateValid = true;
            break;
        }
        else
        {
            printf("The year you entered is not valid. Please enter a year between 1582 and 2400. \n");
            return 0;
        }
    }

    // Set date validation to false for checking further input
    dateValid = false;

    // Check if year is a leapyear
    if (year % 4 == 0 && year % 100 == 0 && year % 400 == 0)
    {
        leapyear = true;
    }
    fflush(stdin);

    // Input month & check if month is valid
    printf("Enter month (mm): \n");
    while (!monthExists)
    {
        scanf("%i", &month);
        fflush(stdin);
        // Check if month input is valid
        if (month > 0 && month < 13)
        {
            monthExists = true;
            break;
        }
        else
        {
            printf("The month you entered doesn't exist. Please try again. \n");
            return 0;
        }
    }

    // Input date & check if valid
    printf("Enter day (dd): \n");
    while (!dayExists)
    {
        scanf("%i", &day);
        fflush(stdin);
        // Check if day is valid
        if ((day <= daysPerMonth[month - 1]) ||
            (month == 2 && day == 29 && leapyear))
        {
            dayExists = true;
            break;
        }
        else
        {
            printf("The day you entered doesn't exist. Please try again. \n");
            return 0;
        }
    }

    // Calculate what day of the year it is
    for (int i = 0; i < month - 1; i++)
    {
        daysTotal += daysPerMonth[i];
    }
    daysTotal += day;

    if(leapyear && month >= 3) {
        daysTotal += 1;
    }

    // Output result
    printf("Today is the %i. day of the year %i (%i.%i.%i). \n ", daysTotal, year, day, month, year);
    if(leapyear) {
        printf("It's a leapyear.");
    }

    return 0;
}

/**
 *  This function calculates the day of the year for a given date in the Gregorian calendar (starting January, 1st), consisting of day, month and year.
 *  Leapyears are taken into account in the calculation.
 *  If the passed date is invalid, the return value is -1.
 **/
int day_of_the_year(int day, int month, int year);

/**
 *  The function reads 3 integer values, for day, month and year.
 *  If the specified date is invalid, it is read again until a valid date is entered.
 **/
void input_date(int* day, int* month, int* year);

/**
 *  The function checks whether a given year is a leap year according to the rules of the Gregorian calendar.
 *  An error is returned for years before the year 1582.
 **/
int is_leapyear(int year);

/**
 *  The function determines for a given month of a given year how many days the month has.
 *  The value of the month must be between 1 and 12. Leap years are taken into account.
 **/
int get_days_for_month(int month, int year);

/**
 *  The function checks whether an entered date is valid.
 *  Dates before 1.1.1582 are invalid, as are all dates after 31.12.2400.
 **/
int exists_date(int day, int month, int year);

