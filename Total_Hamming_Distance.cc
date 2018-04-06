/*
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Now your job is to find the total Hamming distance between all pairs of the given numbers.

Example:

Input: 4, 14, 2

Output: 6

Explanation: In binary representation, the 4 is 0100, 14 is 1110, and 2 is 0010 (just
showing the four bits relevant in this case). So the answer will be:
HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2 + 2 + 2 = 6.

Note:

    Elements of the given array are in the range of 0 to 10^9
    Length of the array will not exceed 10^4.
*/

/*

  如果一对数对于最后的结果有贡献，则其对应的比特位要不同为0或1；所以对所有的数按为进行统计，统计该位为0和1的个数，
  其乘积即为该为对于最后结果的贡献。

    int totalHammingDistance(vector<int>& nums) {
        int total = 0;
        for(int i = 0; i < 32; i++){
            vector<int> a(2,0);
            for(int j = 0; j < nums.size(); j++){
                a[nums[j]%2]++;
                nums[j] = nums[j] >> 1;
            }
            total += a[0] * a[1];
        }
        return total;
    }
*/
