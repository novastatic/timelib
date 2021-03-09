/**
* Title: dayOfYear - header file
* Author: Antonia Lenz
* Created: 27.02.2021
**/

#ifndef DAYOFYEAR_H_INCLUDED
#define DAYOFYEAR_H_INCLUDED

// Define struct date
struct date
{
    int year;
    int month;
    int day;

};


// Declare functionprototypes
int day_of_the_year(struct date userDate);
void input_date(struct date *userDate_pointer);
int is_leapyear(int year);
int get_days_for_month(int month, int year);
int exists_date(struct date userDateExist);

#endif // DAYOFYEAR_H_INCLUDED
