#ifndef CALENDAR_HPP
#define CALENDAR_HPP

#include <string>
#include <iostream>

enum DayName { Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday };

enum MonthName {
    January, February, March, April, May, June,
    July, August, September, October, November, December
};

class Calendar {
private:
    int day;
    MonthName month;
    int year;

    int dayOfWeek(int d, int m, int y) const; // Helper function

public:
    Calendar(int day, MonthName month, int year);

    DayName getDayOfWeek() const;
    int getDay() const;
    MonthName getMonth() const;
    int getYear() const;

    void setDay(int day);
    void setMonth(MonthName month);
    void setYear(int year);

    DayName getDayNameForDate(int day, MonthName month, int year) const; // New function
    std::string getMonthNameAsString() const;
    std::string getDayNameAsString() const;
    Calendar addDays(int days) const;
    Calendar addMonths(int months) const;
    Calendar addYears(int years) const;
    int daysInMonth(MonthName month, int year) const;
    bool isLeapYear(int year) const;

};

#endif // CALENDAR_HPP