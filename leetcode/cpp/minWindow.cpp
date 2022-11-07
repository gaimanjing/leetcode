//
//  minWindow.cpp
//  leetcode
//
//  Created by houguanhua on 2022/11/7.
//  Copyright © 2022 gaimanjing. All rights reserved.
//

#include "minWindow.hpp"

#include <unordered_map>
using std::unordered_map;

string Solution76::minWindow(string s, string t) {
    string result;
    
    unordered_map<char, int> sCharCount, tCharCount;
    for (auto const c : t) {
        ++tCharCount[c];
    }
    
    class Solution {
    public:
        bool check(unordered_map<char, int>& sCnt, unordered_map<char, int>& tCnt) {
            for (const auto &p : tCnt) {
                if (sCnt[p.first] < p.second) {
                    return false;
                }
            }
            return true;
        }
    };
    
    int left = 0;
    int len = INT_MAX;
    
    int tmpLeft = 0;
    Solution solution;
    for (int right=0; right<s.size(); ++right) {
        if (tCharCount.find(s[right]) != tCharCount.end()) {
            ++sCharCount[s[right]];
        }
        
        while(solution.check(sCharCount, tCharCount) && (tmpLeft <= right)) {
            int tmpLen = right - tmpLeft + 1;
            if (tmpLen < len) {
                len = tmpLen;
                left = tmpLeft;
            }
            
            if (sCharCount.find(s[tmpLeft]) != sCharCount.end()) {
                --sCharCount[s[tmpLeft]];
            }
            
            ++tmpLeft;
        }
    }
    
    if (len <= s.size()) {
        result = s.substr(left, len);
    }
    
    return result;
}
