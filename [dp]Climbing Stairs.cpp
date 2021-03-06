/* g++ origin.cpp -o hello -std=c++11 */

#include <math.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* 
Descrition:
You are climbing a stair case. It takes n steps to reach to the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
Note: Given n will be a positive integer.

Example 1:
Input: 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

Example 2:
Input: 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
*/

/*
Result:
Runtime: 4 ms, faster than 81.86% of C++ online submissions for Climbing Stairs.
Memory Usage: 8.5 MB, less than 38.09% of C++ online submissions for Climbing Stairs.
*/

/*
Analysis:
Time Complexity:
Space Complexity:
*/


class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }

        vector<int> total_ways(n, 0);
        total_ways[0] = 1;
        total_ways[1] = 2;
        for (int i = 2; i < n; i++) {
            total_ways[i] = total_ways[i - 1] + total_ways[i - 2];
        }
        return total_ways[n - 1];
    }
};


int main() {
    cout << Solution().climbStairs(3) << endl;
    return 0;
}
