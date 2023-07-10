#include <leetcode.h>

class ZeroEvenOdd {
private:
    int n;
    std::mutex zero_job;
    std::mutex odd_job;
    std::mutex even_job;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        odd_job.lock();
        even_job.lock();
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for (int i = 1; i <= n; ++i) {
            zero_job.lock();
            printNumber(0);
            if (i % 2 == 1) {
                odd_job.unlock();
            } else {
                even_job.unlock();
            }
        }
    }

    void even(function<void(int)> printNumber) {
        for (int i = 2; i <= n; i += 2) {
            even_job.lock();
            printNumber(i);
            zero_job.unlock();
        }
    }

    void odd(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i += 2) {
            odd_job.lock();
            printNumber(i);
            zero_job.unlock();
        }
    }
};