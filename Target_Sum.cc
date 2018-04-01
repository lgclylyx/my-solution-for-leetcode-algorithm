/*
You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.

Find out how many ways to assign symbols to make sum of integers equal to target S.

Example 1:

Input: nums is [1, 1, 1, 1, 1], S is 3. 
Output: 5
Explanation: 

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

There are 5 ways to assign symbols to make the sum of nums be target 3.

Note:

    The length of the given array is positive and will not exceed 20.
    The sum of elements in the given array will not exceed 1000.
    Your output answer is guaranteed to be fitted in a 32-bit integer.

*/

/*

    TLE; O(2^n);

    int findTargetSumWays(vector<int>& nums, int S) {
        vector<vector<int>> dp(nums.size());
        int ret = 0;
        
        for(int i = nums.size() - 1; i >= 0; i--){
            if(i == nums.size() - 1){
                dp[i].push_back(-nums[i]);
                dp[i].push_back(nums[i]);
            }else{
                for(auto j : dp[i+1]){
                    dp[i].push_back(j+nums[i]);
                    dp[i].push_back(j-nums[i]);
                }
            }
        }
        
        for(int i = 0; i < dp[0].size(); i++)
            if(dp[0][i] == S)
                ret++;
        return ret;
    }
*/

/*

 集合P和N为nums中的分别应该取正号和负号的元素；则可以推到：sum(p)-sum(n) = S; 2*sum(p) = sum(nums) + S; sum(p) = (sum(nums)+S)/2;所以将
 原问题转换为在nums中元素的组合其值和为(sum(nums)+S)/2的数目；则这就可以看作一个0/1背包问题；则dp[i][j] = dp[i-1][j]+dp[i-1][j-nums[i-1]];
 其中，dp[i][j]为nums中0-i的范围内的元素组合的值为j的数目。

 int findTargetSumWays(vector<int>& nums, int S) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if(sum < S || ((sum + S) & 0x1) != 0)
        return 0;
    sum = (sum+S) / 2;
    S = sum;
    vector<vector<int>> dp(nums.size()+1,vector<int>(S+1,0));
    dp[0][0] = 1;
    
    for(int i=1; i<=nums.size(); i++){
        if(nums[i-1]==0)
            dp[i][0] = dp[i-1][0] * 2;
        else
            dp[i][0] = dp[i-1][0];
    }
        
    for(int i=1; i<=nums.size(); i++){
        for(int j=1; j<=S; j++){
            if(j>=nums[i-1])
                dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    
    return dp[nums.size()][S];
 }
*/
