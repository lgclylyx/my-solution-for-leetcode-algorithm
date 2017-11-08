/*
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. 
Assume that there is only one duplicate number, find the duplicate one.

Note:

    You must not modify the array (assume the array is read only).
    You must use only constant, O(1) extra space.
    Your runtime complexity should be less than O(n2).
    There is only one duplicate number in the array, but it could be repeated more than once.
*/

/*

	O(nlogn)
	鸽笼原理。因为对于n+1个单元中，存放着大小[1,n]的数。
	所以对于[1,n]的单元中，肯定有某个数所在的单元中要
	放入多余一个数。所以对于mid = l + (r-l)/2.如果小于
	mid的数大于一半，则说明多余的数在该一半。

	int findDuplicate(vector<int>& nums) {
    	int n=nums.size()-1;
    	int low=1;
    	int high=n;
    	int mid;
    	while(low<high){
        	mid=(low+high)/2;
        	int count=0;
        	for(int num:nums){
            	if(num<=mid) count++;
        	}
        	if(count>mid) high=mid;
        	else low=mid+1; 
    	}
    	return low;
	}
*/