/*
Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.

click to show follow up.

Follow up:
A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.

Could you come up with an one-pass algorithm using only constant space?
*/

/*

	O(n),三项切分快速排序算法,只需要一趟排序和 constant space 对数组排序。对于只有若干不同主键的随机数组，三向切分快排能达到O(n)

    void sortColors(vector<int>& nums) {
        int lt = 0 , gt = nums.size() - 1, i = 1, pivot = 1;
        
        int t = nums[0]; 
            
        nums[0] = pivot;
        
        while(i <= gt){
            if(nums[i] < pivot)
                swap(nums[i++],nums[lt++]);
            else if(nums[i] > pivot)
                swap(nums[i],nums[gt--]);
            else
                i++;
        }
        if(0 == t)
            nums[lt] = t;
        else
            nums[gt] = t;
    }
*/