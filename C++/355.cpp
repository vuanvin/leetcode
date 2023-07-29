#include <leetcode.h>

class Twitter {
private:
    struct Node {
        unordered_set<int> followee;
        list<int> tweet;
    };

    int time, maxRecent;
    unordered_map<int, int> tweetTime;
    unordered_map<int, Node> users;

public:
    Twitter() : time(0), maxRecent(10) {}

    void postTweet(int userId, int tweetId) {
        if (!users.count(userId)) {
            init(userId);
        }
        auto& user = users[userId];
        if (user.tweet.size() == maxRecent) user.tweet.pop_back();

        user.tweet.push_front(tweetId);
        tweetTime[tweetId] = ++time;
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> feed;

        for (auto it = users[userId].tweet.begin(); it != users[userId].tweet.end(); ++it) {
            feed.emplace_back(*it);
        }
        for (int followeeId : users[userId].followee) {
            if (followeeId == userId) continue;
            vector<int> temp;
            auto it = users[followeeId].tweet.begin();
            int i = 0;
            while (i < (int)feed.size() || it != users[followeeId].tweet.end()) {
                if (i == (int)feed.size() || tweetTime[*it] > tweetTime[feed[i]]) {
                    temp.push_back(*(it++));
                } else {
                    temp.push_back(feed[i++]);
                }
                if ((int)temp.size() == maxRecent) break;
            }
            feed.assign(temp.begin(), temp.end());
        }

        return feed;
    }

    void init(int userId) {
        users[userId].followee.clear();
        users[userId].tweet.clear();
    }

    void follow(int followerId, int followeeId) {
        if (!users.count(followerId)) {
            init(followerId);
        }
        if (!users.count(followeeId)) {
            init(followeeId);
        }
        users[followerId].followee.insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) { users[followerId].followee.erase(followeeId); }
};
