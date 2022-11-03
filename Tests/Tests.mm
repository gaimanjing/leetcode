//
//  Tests.m
//  Tests
//
//  Created by houguanhua on 2022/11/2.
//  Copyright © 2022 gaimanjing. All rights reserved.
//

#import <XCTest/XCTest.h>

#import "maxSubArray.hpp"

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


@end
