/* g++ origin.cpp -o origin -std=c++11 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* 
Descrition:
You have a total of n coins that you want to form in a staircase shape, where every k-th row must have exactly k coins.
Given n, find the total number of full staircase rows that can be formed.
n is a non-negative integer and fits within the range of a 32-bit signed integer.

Example 1:
n = 5
The coins can form the following rows:
¤
¤ ¤
¤ ¤
Because the 3rd row is incomplete, we return 2.

Example 2:
n = 8
The coins can form the following rows:
¤
¤ ¤
¤ ¤ ¤
¤ ¤
Because the 4th row is incomplete, we return 3.
*/

/*
Result:
Runtime: 12 ms, faster than 83.94% of C++ online submissions for Arranging Coins.
Memory Usage: 8.4 MB, less than 98.96% of C++ online submissions for Arranging Coins.
*/

/*
Analysis:
Time Complexity:
Space Complexity:
*/

class Solution {
public:
    int arrangeCoins(int n) {
        int row = 0, sum = 0;
        while (sum <= n) {
            if (n - sum >= row) {
                sum += row;
                row++;
            } else {
                break;
            }
        }
        return row - 1;
    }
};


int main() {
    cout << Solution().arrangeCoins(5) << endl;
    cout << Solution().arrangeCoins(8) << endl;
    return 0;
}
