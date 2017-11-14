/*
Given an integer array nums, return the number of range sums that lie in [lower, upper] inclusive.
Range sum S(i, j) is defined as the sum of the elements in nums between indices i and j (i ≤ j), inclusive.

Note:
A naive algorithm of O(n2) is trivial. You MUST do better than that.

Example:
Given nums = [-2, 5, -1], lower = -2, upper = 2,
Return 3.
The three ranges are : [0, 0], [2, 2], [0, 2] and their respective sums are: -2, -1, 2. 
*/

/*

	O(nlogn).分治算法。sum[i]表示nums[0-i]的和。使用mergesort的思想，则可以将原问题看作两个子问题并将其
	组合。因为要找[lower，upper]的序列和，则对于两个已排序的子序列，只用找到sum[m] - sum[i] >= lower
	和sum[n] - sum[i] <= upper，m和n都是在右半区间，则m和n之间的数满足条件。

    int mergeSort(vector<long>& sum, int lower, int upper, int low, int high){
        if(high-low <= 1) return 0;
        int mid = (low+high)/2, m = mid, n = mid, count =0;
        count =mergeSort(sum,lower,upper,low,mid) +mergeSort(sum,lower,upper,mid,high);
        for(int i =low; i< mid; i++){//O(n),m 和 n都能单调递增，因为左右两个序列是单调增的
            while(m < high && sum[m] - sum[i] < lower) m++;
            while(n < high && sum[n] - sum[i] <= upper) n++;
            count += n - m;
        }
        inplace_merge(sum.begin()+low, sum.begin()+mid, sum.begin()+high);//o(n)
        return count;
    }

    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int len = nums.size();
        vector<long> sum(len + 1, 0);
        for(int i =0; i< len; i++) sum[i+1] = sum[i]+nums[i];
        return mergeSort(sum, lower, upper, 0, len+1);
    }
*/