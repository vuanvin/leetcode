#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000 * 1000 * 1000;

class MyCalendar {
public:
    set<int> tree, lazy;

    MyCalendar() {}

    bool query(int start, int end, int l, int r, int idx) {
        if (r < start or end < l) {
            return false;
        }
        if (lazy.count(idx)) {
            return true;
        }
        if (start <= l and r <= end) {
            return tree.count(idx);
        }
        int mid = (l + r) / 2;
        return query(start, end, l, mid, idx * 2) or query(start, end, mid + 1, r, idx * 2 + 1);
    }

    void update(int start, int end, int l, int r, int idx) {
        if (r < start || end < l)
            return;
        if (start <= l && r <= end) {
            this->tree.insert(idx);
            this->lazy.insert(idx);
        } else {
            int mid = (l + r) / 2;
            update(start, end, l, mid, idx * 2);
            update(start, end, mid + 1, r, idx * 2 + 1);
            tree.insert(idx);
            if (lazy.find(idx * 2) != lazy.end() and lazy.find(idx * 2 + 1) != lazy.end()) {
                lazy.insert(idx);
            }
        }
    }
    
    bool book(int start, int end) {
        if (this->query(start, end - 1, 0, MAXN, 1)) {
            return false;
        }

        this->update(start, end - 1, 0, MAXN, 1 );
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

 int main() {
    MyCalendar cal;
 }