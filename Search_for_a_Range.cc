/*
Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4]. 
*/

/*

	
用binary search 分两次找到左端点和右端点，也可以通过c++标准库函数的lower_bound,upper_bound和equal_range来解决


    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        int lo = 0, hi = nums.size()-1;
        int left , right;
        while(lo < hi){
            left = (lo + hi)/2;
            nums[left] < target ? lo = left + 1 : hi = left;
        }
        left = (!nums.empty()&&nums[lo] == target) ? lo : -1;
        result.push_back(left);
        if(left == -1){
            result.push_back(-1);
            return result;
        }
        lo = 0, hi = nums.size()-1;
        while(lo + 1 < hi){
            right = (lo + hi)/2;
            target < nums[right] ? hi = right-1 : lo = right;
        }
        right = nums[hi] == target ? hi : hi-1;
        result.push_back(right);
        return result;
    }
*/