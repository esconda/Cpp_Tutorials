#include "TimeMeasurement.h"

TimeMeasurement::TimeMeasurement()
{
}

void TimeMeasurement::elapsedTimeExample()
{
    auto tStartTime = std::chrono::system_clock::now();
    int i = 0;
    while (i <= 20000)
    {
        i++;
        std::cout << i << std::endl;
    }
    auto tEndTime = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed = tEndTime - tStartTime;
    std::cout << "Elapsed time: " << elapsed.count() <<std::endl;
}

std::tm TimeMeasurement::createTmStruct(int year, int month, int day, int hour, int minutes, int seconds)
{
    struct tm tm_ret{0};

    tm_ret.tm_sec = seconds;
    tm_ret.tm_min = minutes;
    tm_ret.tm_hour = hour;
    tm_ret.tm_mday = day;
    tm_ret.tm_mon = month - 1;
    tm_ret.tm_year = year - 1900;

    return tm_ret;
}

int TimeMeasurement::get_days_in_year(int year)
{
    using namespace std;
    using namespace std::chrono;
    // We want results to be in days
    typedef duration<int, ratio_multiply<hours::period, ratio<24>>::type> days;

    // Create start time span
    std::tm tm_start = createTmStruct(year, 1, 1, 0, 0, 0);
    auto tms = system_clock::from_time_t(std::mktime(&tm_start));

    // Create end time span
    std::tm tm_end =  createTmStruct(year + 1, 1, 1, 0, 0, 0);
    auto tme = system_clock::from_time_t(std::mktime(&tm_end));

    // Calculate time duration between those two dates
    auto diff_in_days = std::chrono::duration_cast<days>(tme - tms);

    return diff_in_days.count();
}
