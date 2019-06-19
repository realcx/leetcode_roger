/* g++ origin.cpp -o hello -std=c++11 */

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#include "common/vector_util.h"

using namespace std;

/* 
Descrition:
In the computer world, use restricted resource you have to generate maximum benefit is what we always want to pursue.
For now, suppose you are a dominator of m 0s and n 1s respectively. On the other hand,
there is an array with strings consisting of only 0s and 1s.
Now your task is to find the maximum number of strings that you can form with given m 0s and n 1s.
Each 0 and 1 can be used at most once.

Note:
The given numbers of 0s and 1s will both not exceed 100
The size of given string array won't exceed 600.
 
Example 1:
Input: Array = {"10", "0001", "111001", "1", "0"}, m = 5, n = 3
Output: 4
Explanation: This are totally 4 strings can be formed by the using of 5 0s and 3 1s, which are “10,”0001”,”1”,”0”
 

Example 2:
Input: Array = {"10", "0", "1"}, m = 1, n = 1
Output: 2
Explanation: You could form "10", but then you'd have nothing left. Better form "0" and "1".
*/

/*
Result:
Runtime: 236 ms, faster than 19.96% of C++ online submissions for Ones and Zeroes.
Memory Usage: 91.1 MB, less than 19.82% of C++ online submissions for Ones and Zeroes.
*/

/*
Analysis:
Time Complexity:
Space Complexity:
*/


class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int size = strs.size();
        vector<vector<vector<int>>> amount(size, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));

        int zero_num = 0;
        int one_num = 0;
        count_num(strs[0], &zero_num, &one_num);

        for (int j = 0; j <= m; j++) {
            for (int p = 0; p <= n; p++) {
                if (j >= zero_num && p >= one_num) {
                    amount[0][j][p] = 1;
                } else {
                    amount[0][j][p] = 0;
                }
            }
        }

        for (int i = 1; i < size; i++) {
            count_num(strs[i], &zero_num, &one_num);
            for (int j = 0; j <= m; j++) {
                for (int p = 0; p <= n; p++) {
                    if (j >= zero_num && p >= one_num) {
                        amount[i][j][p] = max(amount[i - 1][j][p],
                                              amount[i - 1][j - zero_num][p - one_num] + 1);
                    } else {
                        amount[i][j][p] = amount[i - 1][j][p];
                    }
                }
            }
        }

        return amount[size - 1][m][n];
    }

    void count_num(const string& str, int* zero_num, int* one_num) {
        *one_num = 0;
        *zero_num = 0;
        for (const char& c : str) {
            if (c == '1') {
                *one_num += 1;
            } else if (c == '0') {
                *zero_num += 1;
            }
        }
    }
};


int main() {
    vector<string> v1 = {"10", "0001", "111001", "1", "0"};
    cout << Solution().findMaxForm(v1, 5, 3) << endl;
    vector<string> v2 = {"10", "0", "1"};
    cout << Solution().findMaxForm(v2, 1, 1) << endl;
    return 0;
}
