/*
Given a set of distinct integers, nums, return all possible subsets.

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

/*

	位操作，从0到2^size计数，根据1的位置来确定subset

    vector<vector<int>> subsets(vector<int>& nums) {
        int i = 0 , j = pow(2,nums.size());
        vector<int> a(nums.size());
        vector<vector<int>> result;
        while(i < j){
            result.push_back(solver(i,j,nums));
            i++;
        }
        return result;
    }
    
    vector<int> solver(int i, int j, vector<int>& nums){
        vector<int> a;
        for(int k = 0; k < nums.size(); k++){
            if((i >> k) & 0x1) 
                a.push_back(nums[k]);
        }
        return a;
    }
*/