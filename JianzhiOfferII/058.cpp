#include <bits/stdc++.h>
using namespace std;

class MyCalendar {
    map<int, int> dates;

public:
    MyCalendar() {}

    bool book(int start, int end) {
        auto it = dates.upper_bound(start);
        if (it == dates.end() || it->second >= end) {
            dates[end] = start;
            return true;
        }
        return false;
    }
};