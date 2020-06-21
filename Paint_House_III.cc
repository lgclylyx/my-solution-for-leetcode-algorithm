/*
There is a row of m houses in a small city, each house must be painted with one of the n colors (labeled from 1 to n), some houses that has been painted last summer should not be painted again.

A neighborhood is a maximal group of continuous houses that are painted with the same color. (For example: houses = [1,2,2,3,3,2,1,1] contains 5 neighborhoods  [{1}, {2,2}, {3,3}, {2}, {1,1}]).

Given an array houses, an m * n matrix cost and an integer target where:

    houses[i]: is the color of the house i, 0 if the house is not painted yet.
    cost[i][j]: is the cost of paint the house i with the color j+1.

Return the minimum cost of painting all the remaining houses in such a way that there are exactly target neighborhoods, if not possible return -1.

 

Example 1:

Input: houses = [0,0,0,0,0], cost = [[1,10],[10,1],[10,1],[1,10],[5,1]], m = 5, n = 2, target = 3
Output: 9
Explanation: Paint houses of this way [1,2,2,1,1]
This array contains target = 3 neighborhoods, [{1}, {2,2}, {1,1}].
Cost of paint all houses (1 + 1 + 1 + 1 + 5) = 9.

Example 2:

Input: houses = [0,2,1,2,0], cost = [[1,10],[10,1],[10,1],[1,10],[5,1]], m = 5, n = 2, target = 3
Output: 11
Explanation: Some houses are already painted, Paint the houses of this way [2,2,1,2,2]
This array contains target = 3 neighborhoods, [{2,2}, {1}, {2,2}]. 
Cost of paint the first and last house (10 + 1) = 11.

Example 3:

Input: houses = [0,0,0,0,0], cost = [[1,10],[10,1],[1,10],[10,1],[1,10]], m = 5, n = 2, target = 5
Output: 5

Example 4:

Input: houses = [3,1,2,3], cost = [[1,1,1],[1,1,1],[1,1,1],[1,1,1]], m = 4, n = 3, target = 3
Output: -1
Explanation: Houses are already painted with a total of 4 neighborhoods [{3},{1},{2},{3}] different of target = 3.

 

Constraints:

    m == houses.length == cost.length
    n == cost[i].length
    1 <= m <= 100
    1 <= n <= 20
    1 <= target <= m
    0 <= houses[i] <= n
    1 <= cost[i][j] <= 10^4
*/

/*
dp[i][j][k]:it represents the min cost when the i-th house painted by color j+1, and it will construct k+1 neighborhoods
            if the i-th house and the (i-1)-th house has different color, the number of neighborhoods will inc 1
            so min(dp[m-1][0][target-1],...,dp[m-1][n-1][target-1]) is the answer.

            if dp[i][j][k] is euqal to INT_MAX, it represents the i-th house painted by color j+1 constructed k+1 neighborhoods
            is impossible.
class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(target+1, INT_MAX)));

        if(houses[0] == 0) { // if the 0-th house has no color
            for(int i = 0; i < n; i++) {
                dp[0][i][0] = cost[0][i]; // we can paint the 0-th house all color
            }
        } else {
            dp[0][houses[0]-1][0] = 0; // if the 0-th house has color, we don't need to paint it.
        }

        for(int i = 1; i < m; i++) { // we calculate every dp[i][j][k]
            for(int j = 0; j < n; j++) {
                for(int k = 0; k < target; k++) {
                    if(houses[i] == 0) { // if we need to paint i-th house
                        for(int prev_j = 0; prev_j < n; prev_j++) { // we consider every condition about (i-1)-th house's color 
                            if(dp[i-1][prev_j][k] == INT_MAX) {
                                continue;
                            }

                            if(prev_j == j) { // if (i-1)-th and i-th house's color are same, we don't inc neighborhoods
                                dp[i][j][k] = min(dp[i-1][prev_j][k] + cost[i][prev_j], dp[i][j][k]);
                            } else { // if (i-1)-th and i-th house's color are not same, we inc neighborhoods
                                dp[i][j][k+1] = min(dp[i-1][prev_j][k] + cost[i][j], dp[i][j][k+1]);
                            }
                        }
                    } else { // if we don't need to paint i-th house
                        for(int prev_j = 0; prev_j < n; prev_j++) {
                            if(dp[i-1][prev_j][k] == INT_MAX) {
                                continue;
                            }

                            if(prev_j == houses[i] - 1) { // we can only update dp[i][houses[i]-1][x]
                                dp[i][houses[i] - 1][k] = min(dp[i-1][prev_j][k], dp[i][houses[i] - 1][k]);
                            } else {
                                dp[i][houses[i] - 1][k+1] = min(dp[i-1][prev_j][k], dp[i][houses[i] - 1][k+1]);
                            }
                        }
                    }
                } 
            }
        }

        int result = INT_MAX;
        for (int i = 0; i < n; i++) {
            result = min(result, dp[m - 1][i][target - 1]);
        }
        return result == INT_MAX ? -1 : result;
    }
};
*/