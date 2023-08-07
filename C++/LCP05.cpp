#include <leetcode.h>

class Solution {
public:
    static constexpr long N = 1e9 + 7;
    struct Person {
        int num_subordinates;
        vector<int> subordinate;
        long stat_coins;
        long todo_coins;
        int leader;

        Person() : leader(-1), num_subordinates(0), stat_coins(0), todo_coins(0) {}
    };

    int build_team(int p) {
        int sum = 0;
        for (auto q : team[p].subordinate) {
            sum += build_team(q);
        }
        team[p].num_subordinates = sum;
        return sum + 1;
    }

    vector<Person> team;

    long query(int p) {
        if (team[p].leader != -1) {
            query(team[p].leader);
        }
        auto todo_coins = team[p].todo_coins;
        for (auto q : team[p].subordinate) {
            team[q].stat_coins += (1 + team[q].num_subordinates) * todo_coins;
            team[q].stat_coins %= N;
            team[q].todo_coins += todo_coins;
            team[q].todo_coins %= N;
        }
        team[p].todo_coins = 0;

        return team[p].stat_coins;
    }

    vector<int> bonus(int n, vector<vector<int>>& leadership, vector<vector<int>>& operations) {
        team.resize(n + 1, Person());
        for (auto& ls : leadership) {
            auto x = ls[0], y = ls[1];
            team[x].subordinate.push_back(y);
            team[y].leader = x;
        }
        int head = 0;
        for (int i = 1; i <= n; i++) {
            if (team[i].leader == -1) {
                head = i;
                break;
            }
        }

        vector<int> ans;
        build_team(head);

        for (auto op : operations) {
            int opcode = op[0], p = op[1];
            if (opcode == 1) {
                long num_coins = op[2] % N;
                while (p != -1) {
                    team[p].stat_coins += num_coins;
                    team[p].stat_coins %= N;
                    p = team[p].leader;
                }
            } else if (opcode == 2) {
                long num_coins = op[2] % N;
                long add_coins = (1 + team[p].num_subordinates) * num_coins % N;
                team[p].todo_coins += num_coins;
                team[p].todo_coins %= N;

                while (p != -1) {
                    team[p].stat_coins += add_coins;
                    team[p].stat_coins %= N;
                    p = team[p].leader;
                }
            } else {
                ans.push_back(query(p) % N);
            }
        }
        return ans;
    }
};