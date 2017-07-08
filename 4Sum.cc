/*

Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note: The solution set must not contain duplicate quadruplets.

For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]


*/

/*

	与3sum相似，对数组进行排序，然后在固定两位的基础上，进行遍历各种情况O(n^3)

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        
        if(nums.size() < 4)
            return result;
        
        sort(nums.begin(),nums.end());
        
        for(int i = 0; i < nums.size(); i++){
            for(int j = i+1; j < nums.size(); j++){
                int sum = nums[i] + nums[j];
                int front = j + 1;
                int back = nums.size() - 1;
                while (front < back) {
                    int tempsum = sum + nums[front] + nums[back];
                    if (tempsum < target)
                        front++;
                    else if (tempsum > target)
                        back--;
                    else {
                        vector<int> triplet(4, 0);
                        triplet[0] = nums[i];
                        triplet[1] = nums[j];
                        triplet[2] = nums[front];
                        triplet[3] = nums[back];
                        result.push_back(triplet);
                        while (front < back && nums[front] == triplet[2]) front++;
                        while (front < back && nums[back] == triplet[3]) back--;
                    }
                }
                while (j + 1 < nums.size() && nums[j + 1] == nums[j]) 
                    j++;
            }
            while (i + 1 < nums.size() && nums[i + 1] == nums[i]) 
                i++;
        }
        return result;
    }

*/