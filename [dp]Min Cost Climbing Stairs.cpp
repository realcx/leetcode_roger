
/* g++ origin.cpp -o origin -std=c++11 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* 
Descrition:
On a staircase, the i-th step has some non-negative cost cost[i] assigned (0 indexed).
Once you pay the cost, you can either climb one or two steps. You need to find minimum cost to reach
the top of the floor, and you can either start from the step with index 0, or the step with index 1.

Example 1:
Input: cost = [10, 15, 20]
Output: 15
Explanation: Cheapest is start on cost[1], pay that cost and go to the top.

Example 2:
Input: cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
Output: 6
Explanation: Cheapest is start on cost[0], and only step on 1s, skipping cost[3].

Note:
cost will have a length in the range [2, 1000].
Every cost[i] will be an integer in the range [0, 999].
*/

/*
Result:
Runtime: 4 ms, faster than 99.31% of C++ online submissions for Min Cost Climbing Stairs.
Memory Usage: 8.9 MB, less than 48.00% of C++ online submissions for Min Cost Climbing Stairs.
*/

/*
Analysis:
Time Complexity:
Space Complexity:
*/

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int size = cost.size();
        int total_cost_p, total_cost_pp;
        vector<int> total_cost(size, 0);
        total_cost[0] = cost[0];
        for (int i = 1; i < size; i++) {
            total_cost_p = total_cost[i - 1];
            if (i < 2) {
                total_cost_pp = 0;
            } else {
                total_cost_pp = total_cost[i - 2];
            }
            total_cost[i] = min(total_cost_p, total_cost_pp) + cost[i];
        }
        return min(total_cost[size - 1], total_cost[size - 2]);
    } 
};

int main() {
    vector<int> v = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    cout << Solution().minCostClimbingStairs(v) << endl;
    return 0;
}

