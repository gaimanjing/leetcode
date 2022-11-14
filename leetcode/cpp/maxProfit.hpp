//
//  maxProfit.hpp
//  leetcode
//
//  Created by houguanhua on 2022/11/14.
//  Copyright © 2022 gaimanjing. All rights reserved.
//

#ifndef maxProfit_hpp
#define maxProfit_hpp

#include <algorithm>
#include <vector>
using std::vector;
using std::max;
using std::min;

class Solution121 {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        
        int minPrice = prices[0];
        
        int ans = 0;
        for (int price : prices) {
            minPrice = min(minPrice, price);
            ans = max(ans, price - minPrice);
        }
        
        return ans;
    }
};

#endif /* maxProfit_hpp */
