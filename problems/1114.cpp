#include <leetcode.h>

class Foo {
    std::mutex firstJobDone;
    std::mutex secondJobDone;

public:
    Foo() {
        firstJobDone.lock();
        secondJobDone.lock();
    }

    void first(function<void()> printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        firstJobDone.unlock();
    }

    void second(function<void()> printSecond) {
        firstJobDone.lock();
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        secondJobDone.unlock();
    }

    void third(function<void()> printThird) {
        secondJobDone.lock();
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};