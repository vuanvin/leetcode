#include <leetcode.h>

class FizzBuzz {
private:
    int n;
    int i;
    mutex mtx;
    condition_variable cv;

public:
    FizzBuzz(int n) {
        this->n = n;
        this->i = 1;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while (1) {
            {
                unique_lock<mutex> lock(mtx);
                cv.wait(lock, [&] { return i % 3 == 0 && i % 5 != 0 || i > n; });
                if (i > n) return;
                printFizz();
                ++i;
            }
            cv.notify_all();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while (1) {
            {
                unique_lock<mutex> lock(mtx);
                cv.wait(lock, [&] { return i % 3 != 0 && i % 5 == 0 || i > n; });
                if (i > n) return;
                printBuzz();
                ++i;
            }
            cv.notify_all();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
    void fizzbuzz(function<void()> printFizzBuzz) {
        while (1) {
            {
                unique_lock<mutex> lock(mtx);
                cv.wait(lock, [&] { return i % 3 == 0 && i % 5 == 0 || i > n; });
                if (i > n) return;
                printFizzBuzz();
                ++i;
            }
            cv.notify_all();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while (1) {
            {
                unique_lock<mutex> lock(mtx);
                cv.wait(lock, [&] { return i % 3 != 0 && i % 5 != 0 || i > n; });
                if (i > n) return;
                printNumber(i);
                ++i;
            }
            cv.notify_all();
        }
    }
};