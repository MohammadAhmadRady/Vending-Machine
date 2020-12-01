#include <iostream>
#include <cstdlib>
#include <fstream>
#include <limits>
#include <windows.h>
#include <ctime>
#include "item.h"
#include "person.h"
#include "Time.h"
#include "stock.h"
#include "customer.h"
#include "admin.h"
using namespace std;
Time::Time()
{
    time_t now;
    struct tm nowLocal;
    now = time(NULL);
    nowLocal=*localtime(&now);
    hours=nowLocal.tm_hour;//12-
    minutes=nowLocal.tm_min;
}
void Time::set_hours(int h)
{
    hours=h;
}
void Time::set_minutes(int m)
{
    minutes=m;
}
int Time::get_hours()
{
    return hours;
}
int Time::get_minutes()
{
    return minutes;
}
Time Time::operator+(Time &val)
{
    Time result;
    result.hours=hours+val.hours;
    result.minutes=minutes+val.minutes;
    if (result.minutes>=60)
    {
        result.hours++;
        result.minutes-=60;
    }
    return result;
}
Time::~Time()
{}
