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
    int daysPerMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int year;
    int month;
    int day;
    int daysTotal;
    bool leapyear = false;
    bool dayExists = false;

    // Eingabe Jahr
    printf("Geben Sie das Jahr ein: \n");
    scanf("%i", &year);
    fflush(stdin);

    // Prüfung & Speicherung, ob Schaltjahr
    if (year % 4 == 0 && year % 100 == 0 && year % 400 == 0)
    {
        leapyear = true;
    }

    // Eingabe Monat
    printf("Geben Sie den Monat ein (1-12): \n");
    while (!dayExists)
    {
        scanf("%i", &month);
        // Prüfung ob der Monat existiert
        if (month > 0 && month < 13)
        {
            dayExists;
            break;
        }
        else
        {
            printf("Der Monat existiert nicht. \n");
            return 0;
        }
    }
    fflush(stdin);

    // Eingabe Tag
    printf("Geben Sie den Tag ein: \n");
    while (!dayExists)
    {
        scanf("%i", &day);
        // Prüfung, ob der Tag existiert
        if (month == 1 && day < 32 ||
            month == 3 && day < 32 ||
            month == 4 && day < 31 ||
            month == 5 && day < 32 ||
            month == 6 && day < 31 ||
            month == 7 && day < 32 ||
            month == 8 && day < 32 ||
            month == 9 && day < 31 ||
            month == 10 && day < 32 ||
            month == 11 && day < 31 ||
            month == 12 && day < 32 ||
            month == 2 && day < 29 ||
            month == 2 && day < 30 && leapyear)
        {
            dayExists;
            break;
        }
        else
        {
            printf("Der Tag existiert nicht. \n");
            return 0;
        }
    }
    fflush(stdin);

    // Berechnung der Tagesanzahl
    for (int i = 0; i < month; i++)
    {
        if (leapyear && month >= 2)
        {
            daysTotal = daysTotal + daysPerMonth[i] + day + 1;
        }
        else if (month == 1)
        {
            daysTotal = day;
        }
        else
        {
            daysTotal = daysTotal + daysPerMonth[i] + day;
        }
    }

    // Ausgabe Ergebnis
    printf("Heute ist der %i. Tag des Jahres %i. \n ", daysTotal, year);

    return 0;
}
