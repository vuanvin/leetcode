#include <leetcode.h>

class FooBar {
private:
    std::mutex foo_job;
    std::mutex bar_job;
    int n;

public:
    FooBar(int n) {
        this->n = n;
        bar_job.lock();
    }

    void foo(function<void()> printFoo) {
        for (int i = 0; i < n; i++) {
            foo_job.lock();
            // printFoo() outputs "foo". Do not change or remove this line.
            printFoo();
            bar_job.unlock();
        }
    }

    void bar(function<void()> printBar) {
        for (int i = 0; i < n; i++) {
            bar_job.lock();
            // printBar() outputs "bar". Do not change or remove this line.
            printBar();
            foo_job.unlock();
        }
    }
};