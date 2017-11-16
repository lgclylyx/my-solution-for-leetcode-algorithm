/*
A sequence of numbers is called a wiggle sequence if the differences between successive numbers strictly alternate between positive and negative. The first difference (if one exists) may be either positive or negative. A sequence with fewer than two elements is trivially a wiggle sequence.

For example, [1,7,4,9,2,5] is a wiggle sequence because the differences (6,-3,5,-7,3) are alternately positive and negative. In contrast, [1,4,7,2,5] and [1,7,4,5,5] are not wiggle sequences, the first because its first two differences are positive and the second because its last difference is zero.

Given a sequence of integers, return the length of the longest subsequence that is a wiggle sequence. A subsequence is obtained by deleting some number of elements (eventually, also zero) from the original sequence, leaving the remaining elements in their original order.

Examples:

Input: [1,7,4,9,2,5]
Output: 6
The entire sequence is a wiggle sequence.

Input: [1,17,5,10,13,15,10,5,16,8]
Output: 7
There are several subsequences that achieve this length. One is [1,17,10,13,10,16,8].

Input: [1,2,3,4,5,6,7,8,9]
Output: 2
*/

/*

	DP. minl[i]代表nums[i]大于其所在wiggle sequence中的其前一个数时最长长度。minl[i] = max(minl[i] , maxl[j] + 1);maxl[i]同理

    int wiggleMaxLength(vector<int>& nums){
        if(nums.empty())
            return 0;
        vector<int> minl(nums.size(),1), maxl(nums.size(),1);
        
        for(int i = 1; i < nums.size(); i++){
            for(int j = i - 1; j >= 0; j--){
                if(nums[i] > nums[j])
                    minl[i] = max(minl[i] , maxl[j] + 1);
                else if(nums[i] < nums[j])
                    maxl[i] = max(maxl[i],minl[j] + 1);
                else{
                    maxl[i] = max(maxl[i],maxl[j]);
                    minl[i] = max(minl[i],minl[j]);
                }
            }
        }
        return max(maxl.back(),minl.back());
    }
*/

/*

	DP.说明一下为什么nums[i] > nums[i-1]时,maxl[i] = maxl[i-1]?maxl[i]代表的是
	某一个以nums[i]结尾的目标序列中nums[i]前一个数要大于nums[i]，所以这时该数必
	然也大于nums[i-1]。则对于该目标序列maxl[i] = maxl[i-1];

    int wiggleMaxLength(vector<int>& nums) {
        if(nums.empty())
            return 0;
        vector<int> minl(nums.size(),1), maxl(nums.size(),1);
        
        for(int i = 1; i < nums.size(); i++){
                if(nums[i] > nums[i-1]){
                    minl[i] = maxl[i-1] + 1;
                    maxl[i] = maxl[i-1];
                }else if(nums[i] < nums[i-1]){
                    maxl[i] = minl[i-1] + 1;
                    minl[i] = minl[i-1];
                }else{
                    maxl[i] = maxl[i-1];
                    minl[i] = minl[i-1];
                }
        }
        return max(maxl.back(),minl.back());
    }
*/