/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/

/*

	对于一个序列[1,6,3,2,5,4]，其降序时字典序最大。所以下一个置换是：一个从后往前的一个降序序列（5,4）比一个非降序元素（2）大的最小值（4），代替该非降序元素，并将降序改为升序。（4,2,5）

    void nextPermutation(vector<int>& nums) {
        if(nums.size() <= 1)
            return;
        int i = nums.size() - 1,j = i-1;
        for(; nums[j] >= nums[i] && j >= 0; i--,j--)
            ;
        sort(nums.begin()+j+1,nums.end());//
        
        for(int mindex = j + 1; mindex < nums.size() && j >= 0; mindex++){
            if(nums[mindex] > nums[j]){
                swap(nums[mindex],nums[j]);
                break;
            }
        }
    }

*/

/*

	将sort改为reverse能使复杂度进一步降低（O（nlogn）-> O(n)）,因为需排序的序列本来就是有序的，只需改变其有序方向

    void nextPermutation(vector<int>& nums) {
        if(nums.size() <= 1)
            return;
        int i = nums.size() - 1,j = i-1;
        for(; nums[j] >= nums[i] && j >= 0; i--,j--)
            ;
        reverse(nums.begin()+j+1,nums.end());//
        
        for(int mindex = j + 1; mindex < nums.size() && j >= 0; mindex++){
            if(nums[mindex] > nums[j]){
                swap(nums[mindex],nums[j]);
                break;
            }
        }
    }

*/