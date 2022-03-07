#include "TimeMeasurement.h"

int main()
{
    //Check for complex implementation
    TimeMeasurement timeMeasurement;
    timeMeasurement.elapsedTimeExample();

    for (int year = 2000; year <= 2016; ++year)
    {
        std::cout << "There are " << timeMeasurement.get_days_in_year(year) << " days in " << year << "\n";
    }
}