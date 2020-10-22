//
// Created by YUANYIN on 2020/10/21.
//

#ifndef C___SOLUTION_H
#define C___SOLUTION_H
#include "../allhead.h"

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;

        for (int i = 1; i <= numRows; i++) {
            vector<int> row;
            row.push_back(1);
            for (int j = 0; j < 2; j++) {
                int sum = res.back()[j] + res.back()[j+1];
                row.push_back(sum);
            }
            if (i != 1) row.push_back(1);

            res.push_back(row);
        }

        return res;
    }
};


#endif //C___SOLUTION_H
