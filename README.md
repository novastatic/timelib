# timelib

Initial repository for a time library written in C by Christian Wichmann.
Co-author in this repository: *A. Lenz* 

## how to run timelib

- Clone the repository
- Compile both the main and the dayOfYear file
- Alternatively: open the cbp file with CodeBlocks & go from there
- Now you can run timelib! Have fun 🧭🎉
- If you need further information, please refer to the documentation below or the included PAP-file!

## limitations
- *The date must be a valid date between 01.01.1582 and 31.12.2400!*

# functions

This program consists of five functions, excluding the main function:

- day_of_the_year()
- input_date()
- is_leapyear()
- get_days_for_month()
- exists_date()

## day_of_the_year()

The function calculates for a given date of the Gregorian calendar consisting of day, month and year the number of the day and the number of the day counted from the beginning of the year (January 1). Leap years are taken into
taken into account in the calculation. If the passed date is invalid, the return value is -1.
| Function          | Parameters                      | Return value       |
|-------------------|---------------------------------|--------------------|
| day_of_the_year() | day: int, month: int, year: int | Number of day: int |

## input_date()
The function reads 3 integer values, for day, month and year. If the specified date is invalid, it is read in again until a valid date is entered.
| Function     | Parameters                                            | Return value |
|--------------|-------------------------------------------------------|--------------|
| input_date() | day: pointer int month: pointer int year: pointer int | none         |

## is_leapyear()
The function checks whether a given year is a leap year according to the rules of the Gregorian calendar. An error is returned for years before the year 1582. 
| Function      | Parameters | Return value                                         |
|---------------|------------|------------------------------------------------------|
| is_leapyear() | year: int  | 1 if leapyear, 0 if no leapyear, -1 if invalid year  |
## get_days_for_month()
The function determines for a given month of a given year how many days the month has. The value of the month must be between 1 and 12. Leap years are taken into account.
| Function             | Parameters            | Return value                                                    |
|----------------------|-----------------------|-----------------------------------------------------------------|
| get_days_for_month() | month: int, year: int | Number of days: int,  1-31 if valid month,  -1 if invalid month |

## exists_date()
The function checks whether an entered date is valid. Dates before 1.1.1582 are invalid, as are all dates after 31.12.2400.
| Function      | Parameters                       | Return value                             |
|---------------|----------------------------------|------------------------------------------|
| exists_date() | day: int, month: int, year: int  | 1 if date is valid, 0 if date is invalid |
