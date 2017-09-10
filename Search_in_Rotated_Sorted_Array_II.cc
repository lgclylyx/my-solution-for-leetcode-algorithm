/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Write a function to determine if a given target is in the array.

The array may contain duplicates.
*/

/*

	binarysearch

    bool search(vector<int>& nums, int target) {
        if(nums.empty())
            return false;
        int lo = 0, hi = nums.size() - 1;
        int mid = 0;
        while(lo < hi){
            mid = (lo + hi) / 2;
            if(nums[mid] == target) return true;
            if(nums[hi] < nums[mid]){
                if(nums[mid] >target && nums[lo] <= target)
                    hi = mid;
                else
                    lo = mid + 1;
            }else if(nums[mid] < nums[hi]){
                if(nums[mid] < target && nums[hi] >= target)
                    lo = mid + 1;
                else
                    hi = mid;
            }else{
                hi--;
            }
        }
        return nums[lo] == target ? true : false;
    }
*/