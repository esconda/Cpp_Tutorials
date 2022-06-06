#ifndef TIMEMEASUREMENT_H
#define TIMEMEASUREMENT_H

#include <iostream>
#include <chrono>
//Author : Burak Dogancay
/* A static data member of the class may be fully defined within the class definition if it is declared inline. For
example, the following class may be defined in a header. Prior to C++17, it would have been necessary to provide a
.cpp file to contain the definition of Foo::num_instances so that it would be defined only once, but in C++17 the
multiple definitions of the inline variable Foo::num_instances all refer to the same int object.
 */
class TimeMeasurement
{
public:
    TimeMeasurement();
    TimeMeasurement(int val) = delete;
    TimeMeasurement(TimeMeasurement &&ruleOfFive) noexcept = delete;         //III. MOVE CONSTRUCTOR
    TimeMeasurement(const TimeMeasurement &ruleOfThree) = delete;            // II. COPY CONSTRUCTOR
    TimeMeasurement &operator=(const TimeMeasurement &ruleOfThree) = delete; // III. COPY ASSIGNMENT
    ~TimeMeasurement() = default;                                            //Destructor

    void elapsedTimeExample();
    std::tm createTmStruct(int year, int month, int day, int hour, int minutes, int seconds);
    int get_days_in_year(int year);
};

#endif