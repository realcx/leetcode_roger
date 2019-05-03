/* g++ origin.cpp -o origin -std=c++11 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

/* 
Descrition:
Given a non-empty integer array of size n, find the minimum number of moves required to make all
array elements equal, where a move is incrementing n - 1 elements by 1.

Example:
Input:
[1,2,3]
Output:
3
Explanation:
Only three moves are needed (remember each move increments two elements):
[1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
*/

/*
Result:
Runtime: 52 ms, faster than 85.15% of C++ online submissions for Minimum Moves to Equal Array Elements.
Memory Usage: 11.1 MB, less than 100.00% of C++ online submissions for Minimum Moves to Equal Array Elements.
*/

/*
Analysis:
Time Complexity: O(N)
Space Complexity: O(1)
*/

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minimum = INT_MAX, sum = 0;
        for (int& i : nums)
            minimum = min(minimum, i);
        for (int i = 0; i < nums.size(); i++)
            sum += nums[i] - minimum;
        return sum;
    }
};

int main() {
    vector<int> v = {1, 214748364};
    cout << Solution().minMoves(v) << endl;
    return 0;
}
