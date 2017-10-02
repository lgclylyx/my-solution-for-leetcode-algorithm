/*
Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory? 
*/

/*

	a trick. 偶数个相同值的异或为0.

    int singleNumber(vector<int>& nums) {
        for(int i = 1; i < nums.size(); i++)
            nums[0] ^= nums[i];
        return nums[0];
    }
*/

/*
Given an array of integers, every element appears three times except for one, which appears exactly once. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory? 
*/

/*

	这相当于是一个计算器。根据状态表化简出相应的式子。

    int singleNumber(vector<int>& nums) {
        int a=0;
        int b=0;
        for(int c:nums){
            int ta=(~a&b&c)|(a&~b&~c);
            b=(~a&~b&c)|(~a&b&~c);
            a=ta;
        }
        return a|b;
    }
*/

/*
Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

For example:

Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].

Note:

    The order of the result is not important. So in the above example, [5, 3] is also correct.
    Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?

*/

/*

	先通过XOR求出两个出现一次的值的异或值。然后，这两个唯一的数的异或值中为1的bit位，则为这两个数不同的比特位。所以可以根据这些为1的bit位将整个数组分为两个部分，这些bit位为1的一类，这些bit位不为1的
	是一类。然后这两类分别对得到的异或值进行异或，将得到不在这一类中的一个出现一次的值。

    vector<int> singleNumber(vector<int>& nums) 
    {
        int diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());

        diff &= -diff;

        vector<int> rets = {0, 0}; 
        for (int num : nums){
            if ((num & diff) == 0) {
                rets[0] ^= num;
            }
            else {
                rets[1] ^= num;
            }
        }
        return rets;
    }
*/