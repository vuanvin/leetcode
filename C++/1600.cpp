#include <leetcode.h>

class ThroneInheritance {
public:
    struct Person {
        int state;
        int cnt;
        string name;
        Person* father;
        vector<Person*> children;
        Person(string n, Person* f) : name(n), father(f), state(0), cnt(0) {}
    };

    unordered_map<string, Person*> name_map;
    vector<Person> people;

    ThroneInheritance(string kingName) {
        people.reserve(100000 + 5);
        people.emplace_back(kingName, nullptr);

        name_map[kingName] = &people.back();
    }

    void birth(string parentName, string childName) {
        people.emplace_back(childName, name_map[parentName]);

        name_map[parentName]->children.push_back(&people.back());
        name_map[childName] = &people.back();
    }

    void death(string name) { name_map[name]->state = -1; }

    vector<string> getInheritanceOrder() {
        Person* king = &people[0];
        vector<string> res;

        while (king) {
            if (king->state == 0 && king->cnt == 0) {
                res.push_back(king->name);
            }
            if (king->cnt < king->children.size()) {
                auto child = king->children[king->cnt];
                king->cnt++;
                king = child;
            } else {
                king = king->father;
            }
        }

        for (auto& k : people) {
            k.cnt = 0;
        }

        return res;
    }
};
