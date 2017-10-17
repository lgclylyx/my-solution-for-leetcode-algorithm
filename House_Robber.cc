/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each 
of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
*/

/*
    int rob(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int maxrob = 0;
        for(int i = 0; i < nums.size(); i++){
            int j = i - 2;
            int t = nums[i];
            while(j >= 0){
                t = max(t,nums[i] + nums[j--]);
            }
            nums[i] = t; 
            maxrob = max(maxrob , nums[i]);
        }
        return maxrob;
    }
*/

/*

	improvement;对与位置为i的房子有偷与不偷两种选项。对于偷，则max(nums[i],nums[i] + nums[i - 2])，如果不偷max(nums[i],nums[i-1])，从而判断这两种
	情况的谁的值更大。

    int rob(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int maxrob = 0;
        for(int i = 0; i < nums.size(); i++){
            
            if(i - 2 >= 0){
                nums[i] = max(nums[i],nums[i] + nums[i - 2]);
            }
            
            if(i - 1 >= 0)
                nums[i] = max(nums[i],nums[i-1]);
            
            maxrob = max(maxrob , nums[i]);
        }
        return maxrob;
    }
*/