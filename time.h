#ifndef TIME_H
#define TIME_H

class Time
{
    private:
        int hours;
        int minutes;
    public:
        Time();
        ~Time();
        void set_hours(int h);
        void set_minutes(int m);
        int get_hours();
        int get_minutes();
        Time operator+(Time &val);
};

#endif // TIME_H
