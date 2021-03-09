/**
* Title: timelib
* Author: Antonia Lenz
* Created: 25.01.2021
**/

// Preprocessor: include libraries
#include <stdio.h>
#include <stdlib.h>
#include "dayOfYear.h"

// Call main function
int main()
{
    struct date userDate;

    // Introduction message
    printf("What day of the year is today? Find out with this little program and enter your date of choice. \n");

    // Call input_date function
    input_date(&userDate);

    // Output & end of program
    printf("The entered day is the %i. day of the year",day_of_the_year(userDate));

    return 0;
}

