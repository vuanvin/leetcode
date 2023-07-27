#include <leetcode.h>

class MedianFinder {
private:
    map<int, int> lt, rt;
    int ln, rn;
public:
    MedianFinder() : ln(0), rn(0) {}

    void addNum(int num) {
        if (ln == 0) {
            lt[num] = 1;
            ln ++;
            return;
        }
        int bound = lt.rbegin()->first;
        if (num <= bound) {
            lt[num] ++;
            ln ++;
        } else {
            rt[num] ++;
            rn ++;
        }
        if (ln < rn) {
            auto& [rbv, rbn] = *rt.begin();
            lt[rbv]++;
            rbn--;
            if (rbn == 0) {
                rt.erase(rt.begin());
            }
            ln ++;
            rn --;
        } else if (ln > rn + 1) {
            auto& [lbv, lbn] = *lt.rbegin();
            rt[lbv]++;
            lbn--;
            if (lbn == 0) {
                lt.erase(lbv);
            }
            ln --;
            rn ++;
        }
    }

    double findMedian() {
        if (ln == rn) {
            return (lt.rbegin()->first + rt.begin()->first) / 2.0;
        } else {
            return lt.rbegin()->first;
        }
    }
};