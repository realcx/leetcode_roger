/* g++ origin.cpp -o hello -std=c++11 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* 
Descrition:
Assume you are an awesome parent and want to give your children some cookies.
But, you should give each child at most one cookie. Each child i has a greed factor gi,
which is the minimum size of a cookie that the child will be content with; and each cookie j has a size sj.
If sj >= gi, we can assign the cookie j to the child i, and the child i will be content.
Your goal is to maximize the number of your content children and output the maximum number.

Note:
You may assume the greed factor is always positive. 
You cannot assign more than one cookie to one child.

Example 1:
Input: [1,2,3], [1,1]
Output: 1
Explanation: You have 3 children and 2 cookies. The greed factors of 3 children are 1, 2, 3. 
And even though you have 2 cookies, since their size is both 1, you could only make the child whose
greed factor is 1 content.
You need to output 1.

Example 2:
Input: [1,2], [1,2,3]
Output: 2
Explanation: You have 2 children and 3 cookies. The greed factors of 2 children are 1, 2. 
You have 3 cookies and their sizes are big enough to gratify all of the children, 
You need to output 2.
*/

/*
Result:
Runtime: 52 ms, faster than 23.51% of C++ online submissions for Assign Cookies.
Memory Usage: 10.2 MB, less than 96.53% of C++ online submissions for Assign Cookies.
*/

/*
Analysis:
Time Complexity:
Space Complexity:
*/

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int count = 0;
        int i = 0;
        int j = 0;
        while (i < g.size() && j < s.size()) {
            if (s[j] >= g[i]) {
                i++;
                count++;
            }
            j++;
        }
        return count;
    }
};


int main() {
    vector<int> g1 = {1, 2, 3};
    vector<int> v1 = {1, 1};
    cout << Solution().findContentChildren(g1, v1) << endl;
    vector<int> g2 = {1, 2};
    vector<int> v2 = {1, 2, 3};
    cout << Solution().findContentChildren(g2, v2) << endl;
    return 0;
}
