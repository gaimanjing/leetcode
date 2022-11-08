//
//  Tests.m
//  Tests
//
//  Created by houguanhua on 2022/11/2.
//  Copyright © 2022 gaimanjing. All rights reserved.
//

#import <XCTest/XCTest.h>

#import "maxSubArray.hpp"
#include "canJump.hpp"
#include "merge.hpp"
#include "uniquePaths.hpp"
#include "minPathSum.hpp"
#include "climbStairs.hpp"
#include "minDistance.hpp"
#include "sortColors.hpp"
#include "minWindow.hpp"
#include "subsets.hpp"

@interface Tests : XCTestCase

@end

@implementation Tests

- (void)setUp {
}

- (void)tearDown {
}

// MARK: - 53
- (void)test53maxSubArray {
    vector<int> nums({-2,1,-3,4,-1,2,1,-5,4});
    
    Solution53 sut;
    int result = sut.maxSubArray(nums);
    
    XCTAssertEqual(result, 6);
}

- (void)test53maxSubArray_2 {
    vector<int> nums({1});
    
    Solution53 sut;
    int result = sut.maxSubArray(nums);
    
    XCTAssertEqual(result, 1);
}

- (void)test53maxSubArray_3 {
    vector<int> nums({5,4,-1,7,8});
    
    Solution53 sut;
    int result = sut.maxSubArray(nums);
    
    XCTAssertEqual(result, 23);
}

- (void)test53maxSubArray_194 {
    vector<int> nums({-1});
    
    Solution53 sut;
    int result = sut.maxSubArray(nums);
    
    XCTAssertEqual(result, -1);
}

// MARK: 55
- (void)test55canJump1 {
    vector<int> nums({2,3,1,1,4});
    
    Solution55 sut;
    auto result = sut.canJump(nums);
    
    XCTAssertEqual(result, true);
}

- (void)test55canJump2 {
    vector<int> nums({3,2,1,0,4});
    
    Solution55 sut;
    auto result = sut.canJump(nums);
    
    XCTAssertEqual(result, false);
}

// MARK: - 56
- (void)test56merge1 {
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> r = {{1,6},{8,10},{15,18}};
    
    Solution56 sut;
    auto result = sut.merge(intervals);
    
    XCTAssert(result == r);
}

- (void)test56merge2 {
    vector<vector<int>> intervals = {{1,4},{4, 5}};
    vector<vector<int>> r = {{1,5}};
    
    Solution56 sut;
    auto result = sut.merge(intervals);
    
    XCTAssert(result == r);
}

// MARK: - 62
- (void)test62uniquePaths1 {
    Solution62 sut;
    XCTAssert(sut.uniquePaths(3, 7) == 28);
}

- (void)test62uniquePaths2 {
    Solution62 sut;
    XCTAssert(sut.uniquePaths(3, 2) == 3);
}

- (void)test62uniquePaths3 {
    Solution62 sut;
    XCTAssert(sut.uniquePaths(7, 3) == 28);
}

- (void)test62uniquePaths4 {
    Solution62 sut;
    XCTAssert(sut.uniquePaths(3, 3) == 6);
}

// MARK: - 64
- (void)test64minPathSum1 {
    vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};
    
    Solution64 sut;
    auto result = sut.minPathSum(grid);
    
    XCTAssert(result == 7);
}
    
- (void)test64minPathSum2 {
    vector<vector<int>> grid = {{1,2,3},{4,5,6}};
    
    Solution64 sut;
    auto result = sut.minPathSum(grid);
    
    XCTAssert(result == 12);
}

// MARK: - 70
- (void)test70climbStairs1 {
    Solution70 sut;
    XCTAssert(sut.climbStairs(2) == 2);
}

- (void)test70climbStairs2 {
    Solution70 sut;
    XCTAssert(sut.climbStairs(3) == 3);
}

// MARK: - 72
- (void)test72minDistance1 {
    Solution72 sut;
    XCTAssert(sut.minDistance("horse", "ros") == 3);
}

- (void)test72minDistance2 {
    Solution72 sut;
    XCTAssert(sut.minDistance("intention", "execution") == 5);
}

- (void)test72minDistance602 {
    Solution72 sut;
    XCTAssert(sut.minDistance("a", "a") == 0);
}

- (void)test72minDistance1054 {
    Solution72 sut;
    XCTAssert(sut.minDistance("sea", "eat") == 2);
}

// MARK: - 75
- (void)test75sortColors1 {
    vector<int> nums({2,0,2,1,1,0});
    vector<int> r({0,0,1,1,2,2});
    
    Solution75 sut;
    sut.sortColors(nums);
    
    XCTAssert(nums == r);
}

- (void)test75sortColors2 {
    vector<int> nums({2,0,1});
    vector<int> r({0,1,2});
    
    Solution75 sut;
    sut.sortColors(nums);
    
    XCTAssert(nums == r);
}
    
// MARK: - 76
- (void)test76minWindow1 {
    string s = "ADOBECODEBANC", t = "ABC";
    string r("BANC");
   
    Solution76 sut;
    auto result = sut.minWindow(s, t);
    
    XCTAssert(result == r);
}

- (void)test76minWindow2 {
    string s = "a", t = "a";
    string r("a");
   
    Solution76 sut;
    auto result = sut.minWindow(s, t);
    
    XCTAssert(result == r);
}

- (void)test76minWindow3 {
    string s = "a", t = "aa";
    string r("");
   
    Solution76 sut;
    auto result = sut.minWindow(s, t);
    
    XCTAssert(result == r);
}

// MARK: - 78
- (void)test78subsets1 {
    vector<int> nums{1,2,3};
    vector<vector<int>> r{{},{1},{2},{1,2},{3},{1,3},{2,3},{1,2,3}};
   
    Solution78 sut;
    auto result = sut.subsets(nums);
    
    XCTAssert(result == r);
}

- (void)test78subsets2 {
    vector<int> nums{0};
    vector<vector<int>> r{{},{0}};
   
    Solution78 sut;
    auto result = sut.subsets(nums);
    
    XCTAssert(result == r);
}
@end
