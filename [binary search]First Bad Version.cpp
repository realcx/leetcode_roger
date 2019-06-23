/* g++ origin.cpp -o hello -std=c++11 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* 
Descrition:
You are a product manager and currently leading a team to develop a new product. Unfortunately, 
the latest version of your product fails the quality check. Since each version is developed based on
the previous version, all the versions after a bad version are also bad.
Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, 
which causes all the following ones to be bad.
You are given an API bool isBadVersion(version) which will return whether version is bad. 
Implement a function to find the first bad version. You should minimize the number of calls to the API.

Example:
Given n = 5, and version = 4 is the first bad version.
call isBadVersion(3) -> false
call isBadVersion(5) -> true
call isBadVersion(4) -> true
Then 4 is the first bad version. 
*/

/*
Result:
Runtime: 4 ms, faster than 77.90% of C++ online submissions for First Bad Version.
Memory Usage: 8.2 MB, less than 27.10% of C++ online submissions for First Bad Version.
*/

/*
Analysis:
Time Complexity:
Space Complexity:
*/


// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long int a = 1;
        long int b = n;
        long int i = (a + b) / 2;
        while (a != b) {
            if (!isBadVersion(i)) {
                a = i + 1;
            } else {
                b = i;
            }
            i = (a + b) / 2;
        }
        return (int)i;
    }
};


int main() {

    return 0;
}
