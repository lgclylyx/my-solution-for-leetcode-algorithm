/*
Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6. 
*/

/*

相当于DP算法，在位置i处，分别保存乘积的最大值和最小值,maxhere & minhere。在i处的最大和最小值与i-1处的值有关。

public int maxProduct(int[] A) {
    if (A.length == 0) {
        return 0;
    }
    
    int maxherepre = A[0];
    int minherepre = A[0];
    int maxsofar = A[0];
    int maxhere, minhere;
    
    for (int i = 1; i < A.length; i++) {
        maxhere = Math.max(Math.max(maxherepre * A[i], minherepre * A[i]), A[i]);
        minhere = Math.min(Math.min(maxherepre * A[i], minherepre * A[i]), A[i]);
        maxsofar = Math.max(maxhere, maxsofar);
        maxherepre = maxhere;
        minherepre = minhere;
    }
    return maxsofar;
}
*/

/*
Maximum Subarray:
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6. 
*/

/*
Max subarry问题，可以用kadane’s algorithm解决。对于以位置i结尾的子数组，其最大值可以分为包不包含以i-1结尾的数组两种情况，即max(x[i], max_ending_i-1 + x[i])。

def max_subarray(A):
    max_ending_here = max_so_far = A[0]
    for x in A[1:]:
        max_ending_here = max(x, max_ending_here + x)
        max_so_far = max(max_so_far, max_ending_here)
    return max_so_far

*/