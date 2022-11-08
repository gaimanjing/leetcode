//
//  exist.cpp
//  leetcode
//
//  Created by houguanhua on 2022/11/8.
//  Copyright © 2022 gaimanjing. All rights reserved.
//

#include "exist.hpp"

#include <utility>
using std::pair;

bool Solution79::exist(vector<vector<char>>& board, string word) {
    struct Solution {
        bool check(vector<vector<char>>& board,
                   vector<vector<bool>>& visited,
                   int i,
                   int j,
                   string &s,
                   int k) {
            if (k == s.size()) {
                return true;
            }
            
            auto h = board.size();
            auto w = board[0].size();
            if (i < 0 || i >= h) {
                return false;
            }
            if (j < 0 || j >= w) {
                return false;
            }
            
            if(visited[i][j]) {
                return false;
            }
            
            if (board[i][j] == s[k]) {
                visited[i][j] = true;
                
                vector<pair<int, int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
                for (const auto &direction : directions) {
                    auto row = i + direction.first;
                    auto col = j + direction.second;
                    
                    auto r = check(board, visited, row, col, s, k+1);
                    if (r) {
                        return true;
                    }
                }
                
                visited[i][j] = false;
            }
            
            return false;
        }
    } solution;
    
    auto h = board.size();
    auto w = board[0].size();
    vector<vector<bool>> visited(h, vector<bool>(w, false));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (solution.check(board, visited, i, j, word, 0)) {
                return true;
            }
        }
    }
    
    return false;
}
