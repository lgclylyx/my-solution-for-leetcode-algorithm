/*
 Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.

For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint.

click to show more practice.
More practice:

If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).

Credits:
Special thanks to @Freezen for adding this problem and creating all test cases.
*/

/*

	O(nlogn)，借用归并排序的思想。

    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.empty())
            return 0;
        vector<int> sum;
        for(int i : nums)
            sum.push_back(sum.empty() ? i : sum.back() + i);
        
        int minlen = INT_MAX;
        
        solver(nums,sum,s,0,nums.size()-1,minlen);
        
        return minlen == INT_MAX ? 0 : minlen;
    }
    
    void solver(vector<int>& nums,vector<int>& sum, int s, int left, int right, int& minlen){
        if(left == right){
            if(nums[left] >= s)
                minlen = 1;
            return;
        }
        int mid = left + (right - left)/2;
        solver(nums,sum,s,left,mid,minlen);
        solver(nums,sum,s,mid+1,right,minlen);
        
        int max = mid+1, min = left , tsum = 0;
        while(max <= right && min <= mid){
            int tsum = max==min ? nums[max] : sum[max] -sum[min] + nums[min];
            if(tsum < s){
                max++;
            }
            while(tsum >= s && min <= max){
                minlen = std::min(max - min + 1,minlen);
                tsum -= max== min ? 0 : nums[min];
                min++;
            }
        }
    }
*/

/*

	O(n),满足一定约束条件的最优子串的一般解法

	int minSubArrayLen(int s, vector<int>& nums) {
        int max = 0, min = 0 , minlen = INT_MAX;
        int sum = 0;

        
        while(max < nums.size()){
            sum += nums[max];
            while(sum >= s){
                minlen = std::min(max - min + 1,minlen);
                sum -= nums[min];
                min++;
            }
            max++;
        }
        return minlen == INT_MAX ? 0 : minlen;
    }
*/