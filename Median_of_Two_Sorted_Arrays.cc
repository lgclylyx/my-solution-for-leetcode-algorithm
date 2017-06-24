/*
 * question:
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 *
 * Example 1:
 * nums1 = [1, 3],nums2 = [2]
 * The median is 2.0
 *
 * Example 2:
 * nums1 = [1, 2],nums2 = [3, 4]
 * The median is (2 + 3)/2 = 2.5
 *
 *
 */

/*
 * first solution: 因为两个数组已经有序，则只需遍历一次即可将其归并排序完成，则可找到median
 *
 *problems: 时间复杂度为O(M+N),并未达到规定的O(log(m+n))
 *

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    	int size1 = nums1.size();
    	int size2 = nums2.size();
    	if(size2 == 0)
    		return size1%2?nums1[size1/2]:(double(nums1[(size1-1)/2])+nums1[size1/2])/2;
    	if(size1 == 0)
    		return size2%2?nums2[size2/2]:(double(nums2[(size2-1)/2])+nums2[(size2)/2])/2;
    	vector<double> result;
    	int j = 0, i = 0;
    	while(i < size1 && j < size2){
    		if(nums1[i] < nums2[j])
    			result.push_back(nums1[i++]);
    		else
    			result.push_back(nums2[j++]);
    	}
    	while(i<size1)
    		result.push_back(nums1[i++]);

    	while(j<size2)
    		result.push_back(nums2[j++]);

    	return (size1+size2)%2?result[(size1+size2)/2]:(result[(size1+size2-1)/2]+result[(size1+size2)/2])/2;
    }
};
*/

/*
 * 理论上的复杂度为O(log(m+n)),但是在测试时没有上一种解法快，应该在最后那个递归处有问题
 * （数组按升序排序的情况）
 * 题目要求找到median，这对于一个m+n长度的数组，则其median肯定在(m+n)/2处,所以设k=(m+n)/2，且对于长度为m和n的两个数组(m<n)为a,b,则在a和b中分别取i=min(m,k/2)和j=k-min(m,k/2),
 * 则在该位置处有三种情况，（1）a和b在该位置处相等，则肯定为median;（2）a在该位置小于b，则可以将a中从开始到该位置的值舍去，因为合并后该处肯定不会为median，这样就相当于将i向右移动，j向左移动，且保持相加
 * 为K。（3）同理，a在该位置大于b时，则可以将b中的k/2长度舍去；
 * 这可以推广到不是寻找median,对任意的k都可以按此种方法求解，只是初始值不同而已
class Solution {
public:
    //get the kth number of two sorted array
    double findkth(vector<int>::iterator a,int m,
                vector<int>::iterator b,int n,
                int k)
    {
        if(m >  n)
            return findkth(b,n,a,m,k);
        if(m == 0)
            return b[k-1];
        if(k == 1)
            return min(*a,*b);

        int pa = min(k/2,m),pb = k - pa;
        if(*(a + pa - 1) < *(b + pb -1))
            return findkth(a+pa,m-pa,b,n,k-pa);
        else if(*(a + pa -1) > *(b + pb -1))
            return findkth(a,m,b+pb,n-pb,k-pb);
        else
            return *(a+pa-1);
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>::iterator a = nums1.begin();
        vector<int>::iterator b = nums2.begin();
        int total = nums1.size() + nums2.size();

        // judge the total num of two arrays is odd or even
        if(total & 0x1)
            return findkth(a,nums1.size(),
                           b,nums2.size(),
                           total/2+1);
        else
            return (findkth(a,nums1.size(),
                           b,nums2.size(),
                           total/2) +
                    findkth(a,nums1.size(),
                            b,nums2.size(),
                            total/2 + 1))/2;
    }
};
 */
