#include <leetcode.h>

class H2O {
private:
    mutex h_mtx, o_mtx, com_mtx;
    int h_cnt, o_cnt;

public:
    H2O() { h_cnt = o_cnt = 0; }

    void hydrogen(function<void()> releaseHydrogen) {
        h_mtx.lock();
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        {
            lock_guard<mutex> lock(com_mtx);
            if (h_cnt == 0) {
                ++h_cnt;
                h_mtx.unlock();
            } else if (h_cnt == 1 && o_cnt == 0) {
                ++h_cnt;
            } else {
                h_cnt = o_cnt = 0;
                h_mtx.unlock();
                o_mtx.unlock();
            }
        }
    }

    void oxygen(function<void()> releaseOxygen) {
        o_mtx.lock();
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        {
            lock_guard<mutex> lock(com_mtx);
            ++o_cnt;
            if (h_cnt == 2) {
                h_cnt = o_cnt = 0;
                h_mtx.unlock();
                o_mtx.unlock();
            }
        }
    }
};