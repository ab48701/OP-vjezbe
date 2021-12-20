#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <chrono>


using namespace std::chrono;

using namespace std;


class Timer {
private:
    int h;
    int m;
    double s;

public:
    void addSeconds(double seconds);
    void addMinutes(int minutes);
    void addHour(int hour);

    void setSeconds(double seconds);
    void setMinutes(int minutes);
    void setHour(int hour);

    int getHour();
    int getMinutes();
    double getSeconds();

    Timer();
    Timer(int hour, int minute, double second);

    Timer() {
        h = 0;
        m = 0;
        s = 0;
    }
    Timer(int hour, int min, double sec) {
        h = hour;
        m = min;
        s = sec;
    }

    Timer operator+=(Timer timer);
    Timer operator-=(Timer timer);
    Timer operator+(Timer timer);
    Timer operator-(Timer timer);
    Timer operator/=(int n);
    Timer operator/(int n);
    bool operator<(Timer timer);
    operator double();
    friend ostream& operator<<(ostream& os, const Timer& t);
};



class Penalty
{
private:
    double sec;

public:
    Penalty(int p) {
        sec = p;
    }
    double operator() (Timer& penalty) {
        penalty.addSeconds(sec);
        return sec;
    }



};





void Timer::setSeconds(double seconds) {
    s = seconds;
}
void Timer::setMinutes(int minutes) {
    m = minutes;
}
void Timer::setHour(int hour) {
    h = hour;
}

int Timer::getHour() {
    return h;
}
int Timer::getMinutes() {
    return m;
}
double Timer::getSeconds() {
    return s;
}
Timer::operator double() {
    return h * 3600 + m * 60 + s;
}


void Timer::addSeconds(double seconds); {
    s += seconds;

    if (s >= 60) {
        m++;
        s -= 60;
    }

    if (m >= 60) {
        h++;
        m -= 60;
    }
}



void Timer::addMinutes(int minutes) {
    m += minutes;

    if (m >= 60) {
        h++;
        m -= 60;
    }
}

void Timer::addHour(int hour) {
    h += hour;
}

Timer Timer::operator+=(Timer object) {

    h += object.h;
    m += object.m;
    s += object.s;
    if (s >= 60) {
        m++;
        s = s - 60;
    }
    if (m >= 60) {
        h++;
        m = m - 60;
    }
    return *this;
}

Timer Timer::operator+(Timer object) {

    Timer t;
    t.h = h + object.h;
    t.m = m + object.m;
    t.s = s + object.s;
    if (t.s >= 60) {
        t.m++;
        t.s -= 60;
    }
    if (t.m >= 60) {
        t.h++;
        t.m -= 60;
    }
    return t;
}

Timer Timer::operator-=(Timer object) {

    h -= object.h;
    m -= object.m;
    s -= object.s;
    if (h < 0) {
        h = 0;
        m -= abs(h) * 60;
    }
    if (m < 0) {
        m = 0;
        s -= abs(m) * 60;
    }
    if (s < 0) {
        s = 0;
    }
    return *this;
}

Timer Timer::operator-(Timer object) {

    Timer t;
    t.h = h - object.h;
    t.m = m - object.m;
    t.s = s - object.s;
    if (t.h < 0) {
        t.h = 0;
        t.m -= abs(t.h) * 60;
    }
    if (t.m < 0) {
        t.m = 0;
        t.s -= abs(t.m) * 60;
    }
    if (t.s < 0) {
        t.s = 0;
    }
    return t;
}

Timer Timer::operator/(int n) {

    Timer t;
    double time;
    time = h * 3600 + m * 60 + s;
    time = time / n;
    t.h = time / 3600;
    t.m = (time - (t.h * 3600)) / 60;
    t.s = (time - ((t.h * 3600) + (t.m * 60)));
    return t;
}

Timer Timer::operator/=(int n) {

    double time;
    time = h * 3600 + m * 60 + s;
    time = time / n;
    h = time / 3600;
    m = (time - (h * 3600)) / 60;
    s = (time - ((h * 3600) + (m * 60)));
    return *this;
}

bool Timer::operator<(Timer object) {
    double t1 = h * 3600 + m * 60 + s;
    double t2 = object.h * 3600 + object.m * 60 + object.s;

    return t1 < t2;
}

ostream& operator<<(ostream& os, const Timer& timer) {
    os << timer.h << ":" << timer.m << ":" << timer.s << endl;
    return os;
}
int main() {
    vector<Timer> v{ {2, 6, 9.118}, {2, 6, 15.251}, {2, 6, 9.925}, {2, 7, 15.222}, {2, 7, 10.775} };

    // prosjecno vrijeme
    Timer avg;
    for (auto t : v) {
        avg += t;
    }
    avg /= v.size();
    cout << "avg " << avg << endl;

    // vrijeme najbrzeg (operator<)
    Timer tmax = *min_element(v.begin(), v.end());
    cout << "min " << tmax << endl;

    // zaostajanje za vodecim u sekundama
    for (auto& tm : v)
        cout << double(tm - tmax) << endl;

    // penaliziranje vozaca s m sekundi (funkcijski objekt)
    Penalty p(5);
    for (auto& tm : v)
    {
        p(tm);
        cout << tm << endl;
    }
}

/*
 * Rezultat
 * avg 2:6:36.0582
 * min 2:6:9.118
 * 0
 * 6.133
 * 0.807
 * 66.104
 * 61.657
 *
 */