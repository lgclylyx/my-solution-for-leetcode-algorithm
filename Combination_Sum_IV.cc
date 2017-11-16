/*
Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.

Example:

nums = [1, 2, 3]
target = 4

The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

Note that different sequences are counted as different combinations.

Therefore the output is 7.

*/

/*

	DP. dp[i]代表target = i时的可能组合总数。dp[i] = dp[i - nums[j]] j = [0,nums.size()) 

    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1,1);
        for(int i = 1; i <= target; i++){
            int count = 0;
            for(int j = 0; j < nums.size(); j++){
                int k = i - nums[j];
                if(k >= 0)
                    count += dp[k]; 
            }
            dp[i] = count;
        }
        return dp[target];
    }
*/