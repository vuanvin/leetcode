#include <leetcode.h>

class DiningPhilosophers {
private:
    mutex mtx;

public:
    DiningPhilosophers() {}

    void wantsToEat(int philosopher, function<void()> pickLeftFork, function<void()> pickRightFork, function<void()> eat,
                    function<void()> putLeftFork, function<void()> putRightFork) {
        lock_guard<mutex> lock(mtx);
        pickLeftFork();
        pickRightFork();
        eat();
        putLeftFork();
        putRightFork();
    }
};