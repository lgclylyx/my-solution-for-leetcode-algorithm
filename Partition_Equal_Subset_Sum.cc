/*
Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

Note:

    Each of the array element will not exceed 100.
    The array size will not exceed 200.

Example 1:

Input: [1, 5, 11, 5]

Output: true

Explanation: The array can be partitioned as [1, 5, 5] and [11].

Example 2:

Input: [1, 2, 3, 5]

Output: false

Explanation: The array cannot be partitioned into equal sum subsets.

*/


/*

	O(nlogn).要将数列切分成相等的两个序列，则其和必须为偶数。
	对于偶数，其每一个序列和必为total/2。所以在有序数组中，使用
	binary——search查找能构成相应和的序列。如果能找到，则可以切分，否则，不能。

    bool canPartition(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        int total = 0;
        bool t = 0;
        for(int c : nums)
            total += c;
        
        if(total % 2 == 1)
            return false;
        
        total /= 2;
        
        for(int j = nums.size() - 1; j >= 0; j--){
            t = solver(nums,total - nums[j],j);
            if(t)
                return true;
        }
        return false;
    }
    
    bool solver(vector<int>& nums, int target,int j){
        if(target < 0)
            return false;
        
        if(0 == target)
            return true;
        
        auto itr = upper_bound(nums.begin(),nums.begin()+j,target);
        
        int pos = (itr - nums.begin()) - 1;
        
        if(pos < 0)
            return false;
        else
            return solver(nums,target - nums[pos],pos);
    }
*/