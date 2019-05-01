/* g++ origin.cpp -o origin -std=c++11 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* 
Descrition:
Alice and Bob take turns playing a game, with Alice starting first.
Initially, there is a number N on the chalkboard. On each player's turn, that player makes a move consisting of:
Choosing any x with 0 < x < N and N % x == 0.
Replacing the number N on the chalkboard with N - x.
Also, if a player cannot make a move, they lose the game.
Return True if and only if Alice wins the game, assuming both players play optimally.

Example 1:
Input: 2
Output: true
Explanation: Alice chooses 1, and Bob has no more moves.

Example 2:
Input: 3
Output: false
Explanation: Alice chooses 1, Bob chooses 1, and Alice has no more moves.

Note:
1 <= N <= 1000
*/

/*
Result:
Runtime: 4 ms, faster than 100.00% of C++ online submissions for Divisor Game.
Memory Usage: 8.2 MB, less than 100.00% of C++ online submissions for Divisor Game.
*/

/*
Analysis:
Time Complexity: O(1)
Space Complexity: O(1)
*/

class Solution {
public:
    bool divisorGame(int N) {
        return !(N % 2);
    }
};


int main() {
    cout << Solution().divisorGame(3) << endl;
    return 0;
}


