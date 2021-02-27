/**
* Title: dayOfYear - header file
* Author: Antonia Lenz
* Created: 27.02.2021
**/

#ifndef DAYOFYEAR_H_INCLUDED
#define DAYOFYEAR_H_INCLUDED

// Declare functionprototypes
int day_of_the_year(int day, int month, int year);
void input_date(int *day, int *month, int *year);
int is_leapyear(int year);
int get_days_for_month(int month, int year);
int exists_date(int day, int month, int year);

#endif // DAYOFYEAR_H_INCLUDED