/**
* Title: timelib
* Author: Antonia Lenz
* Created: 25.01.2021
**/

// Preprocessor: include libraries
#include <stdio.h>
#include <stdlib.h>
#include "dayOfYear.h"
#define InputRqstYear printf("Please enter year (yyyy): ");
#define InputRqstMonth printf("Please enter month (m/mm): ");
#define InputRqstDay printf("Please enter day (d/dd): ");
#define ErrorMsgYear printf("The year you entered is not valid. Please enter a year between 1582 and 2400. \n");
#define ErrorMsgMonth printf("The month you entered doesn't exist. Please try again. \n");
#define ErrorMsgDay printf("The day you entered doesn't exist. Please try again. \n");
#define DaysTotalMsg printf("The entered day is the %i. day of the year",
#define End );

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

