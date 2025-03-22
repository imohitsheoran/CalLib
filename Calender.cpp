#include "Calender.hpp"

Calendar::Calendar(int day, MonthName month, int year) : day(day), month(month), year(year) {}

DayName Calendar::getDayOfWeek() const {
    return getDayNameForDate(day, month, year);
}

int Calendar::getDay() const {
    return day;
}

MonthName Calendar::getMonth() const {
    return month;
}

int Calendar::getYear() const {
    return year;
}

void Calendar::setDay(int day) {
    this->day = day;
}

void Calendar::setMonth(MonthName month) {
    this->month = month;
}

void Calendar::setYear(int year) {
    this->year = year;
}

int Calendar::dayOfWeek(int d, int m, int y) const {
    if (m < 3) {
        m += 12;
        y--;
    }
    int k = y % 100;
    int j = y / 100;
    int h = (d + ((13 * (m + 1)) / 5) + k + (k / 4) + (j / 4) + (5 * j)) % 7;
    return (h + 6) % 7;
}

DayName Calendar::getDayNameForDate(int day, MonthName month, int year) const {
    int m = static_cast<int>(month) + 1;
    return static_cast<DayName>(dayOfWeek(day, m, year));
}

std::string Calendar::getMonthNameAsString() const {
    switch (month) {
        case January: return "January";
        case February: return "February";
        case March: return "March";
        case April: return "April";
        case May: return "May";
        case June: return "June";
        case July: return "July";
        case August: return "August";
        case September: return "September";
        case October: return "October";
        case November: return "November";
        case December: return "December";
        default: return "Invalid Month";
    }
}

std::string Calendar::getDayNameAsString() const {
    DayName dayOfWeekResult = getDayNameForDate(day, month, year);
    switch (dayOfWeekResult) {
        case Sunday: return "Sunday";
        case Monday: return "Monday";
        case Tuesday: return "Tuesday";
        case Wednesday: return "Wednesday";
        case Thursday: return "Thursday";
        case Friday: return "Friday";
        case Saturday: return "Saturday";
        default: return "Invalid Day";
    }
}

Calendar Calendar::addDays(int days) const {
    Calendar result = *this;
    result.day += days;
    while (result.day > result.daysInMonth(result.month, result.year)) {
        result.day -= result.daysInMonth(result.month, result.year);
        result.month = static_cast<MonthName>((static_cast<int>(result.month) + 1) % 12);
        if (result.month == January) {
            result.year++;
        }
    }
    return result;
}

Calendar Calendar::addMonths(int months) const {
    Calendar result = *this;
    int totalMonths = static_cast<int>(result.month) + months;
    result.month = static_cast<MonthName>(totalMonths % 12);
    result.year += totalMonths / 12;
    if (result.day > result.daysInMonth(result.month, result.year)) {
        result.day = result.daysInMonth(result.month, result.year);
    }
    return result;
}

Calendar Calendar::addYears(int years) const {
    Calendar result = *this;
    result.year += years;
    if (result.day > result.daysInMonth(result.month, result.year)) {
        result.day = result.daysInMonth(result.month, result.year);
    }
    return result;
}

int Calendar::daysInMonth(MonthName month, int year) const {
    switch (month) {
        case January: return 31;
        case February: return isLeapYear(year) ? 29 : 28;
        case March: return 31;
        case April: return 30;
        case May: return 31;
        case June: return 30;
        case July: return 31;
        case August: return 31;
        case September: return 30;
        case October: return 31;
        case November: return 30;
        case December: return 31;
        default: return 0;
    }
}

bool Calendar::isLeapYear(int year) const {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}